#include "HoudiniAssetTaskRunner.h"

#include "UnrealEd.h"

#include "HoudiniAsset.h"
#include "HoudiniRuntimeSettings.h"
#include "HoudiniEngineTaskInfo.h"
#include "HoudiniEngine.h"
#include "HoudiniEngineUtils.h"

bool UHoudiniAssetTaskRunner::StartInstantiation(UHoudiniAsset* Asset, HAPI_StringHandle AssetName)
{
    ensure(Asset);

    bIsBeingInstantiated = true;

    UpdateDependencies(true);

    if (!bWaitingForDependencies)
    {
        FHoudiniEngineTask Task(EHoudiniEngineTaskType::AssetInstantiation, HapiGUID);
        Task.Asset = Asset;
        Task.AssetLibraryId = -1;
        Task.AssetHapiName = AssetName;

        FHoudiniEngine::Get().AddTask(Task);
    }

    Start();

    return true;
}

bool UHoudiniAssetTaskRunner::StartCooking(HAPI_NodeId AssetId)
{
    if (IsRunning())
        return false;

    HapiGUID = FGuid::NewGuid();

    FHoudiniEngineTask Task(EHoudiniEngineTaskType::AssetCooking, HapiGUID);
    Task.AssetId = AssetId;

    FHoudiniEngine::Get().AddTask(Task);

    Start();

    return true;
}

void UHoudiniAssetTaskRunner::Start()
{
    if (!OnCooking.IsBound() && GEditor)
    {
        OnCooking = FTimerDelegate::CreateUObject(this, &UHoudiniAssetTaskRunner::Tick);

        static const float TickTimerInterval = 0.25f;
        GEditor->GetTimerManager()->SetTimer(CookingHandle, OnCooking, TickTimerInterval, true);

        HapiNotificationStarted = FPlatformTime::Seconds();
    }
}

void UHoudiniAssetTaskRunner::Tick()
{
    const auto HoudiniRuntimeSettings = GetDefault<UHoudiniRuntimeSettings>();

    FHoudiniEngineTaskInfo TaskInfo;
    bool bStopTicking = false;
    bool bFinishedLoadInstantiation = false;

    if (HapiGUID.IsValid())
    {
        if (FHoudiniEngine::Get().RetrieveTaskInfo(HapiGUID, TaskInfo))
        {
            if (TaskInfo.TaskState != EHoudiniEngineTaskState::None)
                AddNotification(TaskInfo.StatusText);

            switch (TaskInfo.TaskState)
            {
            case EHoudiniEngineTaskState::FinishedCooking:
            {
                OnFinishedCooking(TaskInfo, false, bStopTicking);
                break;
            }

            case EHoudiniEngineTaskState::FinishedCookingWithErrors:
            {
                OnFinishedCooking(TaskInfo, true, bStopTicking);
                break;
            }

            case EHoudiniEngineTaskState::FinishedInstantiation:
            {
                bFinishedLoadInstantiation = OnFinishedInstantiation(TaskInfo, false, bStopTicking);
                break;
            }

            case EHoudiniEngineTaskState::Aborted:
            case EHoudiniEngineTaskState::FinishedInstantiationWithErrors:
            {
                OnFinishedInstantiation(TaskInfo, true, bStopTicking);
                break;
            }

            case EHoudiniEngineTaskState::Processing:
            {
                OnProcessing(TaskInfo, bStopTicking);
                break;
            }

            case EHoudiniEngineTaskState::None:
            default:
                break;
            }
        }
        else
        {
            HapiGUID.Invalidate();
            bStopTicking = true;
        }
    }

    if (bFinishedLoadInstantiation)
        bIsBeingInstantiated = false;

    if (!IsRunning())
    {
        if (HasBeenInstantiatedButNotCooked() || bParametersChanged || bNeedsCook || bManualRecookRequested)
        {
            HapiNotificationStarted = FPlatformTime::Seconds();

            bStopTicking = false;

            if (bWaitingForDependencies)
            {
                UpdateWaitingForUpstreamAssetsToInstantiate();

                if (!bWaitingForDependencies)
                    bRequiresInstantiation = true;
            }
            else if (bRequiresInstantiation)
            {
                bRequiresInstantiation = false;
                StartInstantiation(true);
            }
            else if (bFinishedLoadInstantiation)
            {

            }
            else
            {
                if (IsCookingEnabled() || bManualRecookRequested)
                {
                    StartCooking();

                    bNeedsCook = false;
                }
                else
                {
                    bNeedsCook = true;
                    bStopTicking = true;
                }
            }
        }
        else
            bStopTicking = true;
    }

    if (bStopTicking)
        Stop();
}

void UHoudiniAssetTaskRunner::Stop()
{
    if (OnCooking.IsBound() && GEditor)
    {
        GEditor->GetTimerManager()->ClearTimer(CookingHandle);
        OnCooking.Unbind();

        HapiNotificationStarted = 0.0;
    }
}

void UHoudiniAssetTaskRunner::StartUI()
{
    if (!OnUpdateUI.IsBound() && GEditor)
    {
        OnUpdateUI = FTimerDelegate::CreateUObject(this, &UHoudiniAssetTaskRunner::TickUI);

        static const float TickTimerInterval = 0.25f;
        GEditor->GetTimerManager()->SetTimer(UpdateUIHandle, OnUpdateUI, TickTimerInterval, true);
    }
}

void UHoudiniAssetTaskRunner::TickUI()
{

}

void UHoudiniAssetTaskRunner::StopUI()
{

}

bool UHoudiniAssetTaskRunner::UpdateDependencies(bool bNotifyDependency)
{
    bWaitingForDependencies = false;

    for (auto Input : AssetInstance->GetInputs())
    {
        bool bInputNeedsInstantiation = Input->DoesInputAssetNeedInstantiation();
        if (!bInputNeedsInstantiation)
            continue;

        bWaitingForDependencies = true;
            
        if (bNotifyDependency)
        {
            auto InputInstance = Input->GetConnectedAssetInstance();
            InputInstance->NotifyParameterChanged(nullptr);
        }
    }

    for (TMap<HAPI_ParmId, UHoudiniAssetParameter*>::TIterator Iterator(AssetInstance->ParametersById); Iterator; ++Iterator)
    {
        auto Input = Cast<UHoudiniAssetInput>(Iterator.Value());
        if(!Input)
            continue;

        bool bInputNeedsInstantiation = Input->DoesInputAssetNeedInstantiation();
        if(!bInputNeedsInstantiation)
            continue;

        bWaitingForDependencies = true;

        if (bNotifyDependency)
        {
            auto InputInstance = Input->GetConnectedInputAssetComponent();
            InputInstance->NotifyParameterChanged(nullptr);
        }
    }

    return bWaitingForDependencies;
}

void UHoudiniAssetTaskRunner::OnFinishedCooking(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors, bool& bStopTicking)
{
    if (FHoudiniEngineUtils::IsValidAssetId(TaskInfo.AssetId))
    {
        if (OnCooked.IsBound())
            OnCooked.Broadcast(TaskInfo.AssetId, bHasErrors);
    }

    AddNotification(TaskInfo.StatusText);

    InvalidateTask();

    bStopTicking = true;
    CookCount++;
}

bool UHoudiniAssetTaskRunner::OnFinishedInstantiation(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors, bool& bStopTicking)
{
    bool bFinishedLoadInstantiation = false;

    if (!bHasErrors)
    {
        if (FHoudiniEngineUtils::IsValidAssetId(TaskInfo.AssetId))
        {
            if (OnInstantiated.IsBound())
                OnInstantiated.Broadcast(TaskInfo.AssetId);

            AddNotification(TaskInfo.StatusText);

            InvalidateTask();

            CookCount = 0;

            if (TaskInfo.bLoadedComponent)
                bFinishedLoadInstantiation = true;

           SetHapiState(HAPI_RESULT_SUCCESS);
        }
        else
            bStopTicking = true;
    }
    else
    {
        bool bLicensingIssue = false;
        switch (TaskInfo.Result)
        {
        case HAPI_RESULT_NO_LICENSE_FOUND:
        {
            SetHapiState(HAPI_RESULT_NO_LICENSE_FOUND);
            bLicensingIssue = true;
            break;
        }

        case HAPI_RESULT_DISALLOWED_NC_LICENSE_FOUND:
        case HAPI_RESULT_DISALLOWED_NC_ASSET_WITH_C_LICENSE:
        case HAPI_RESULT_DISALLOWED_NC_ASSET_WITH_LC_LICENSE:
        case HAPI_RESULT_DISALLOWED_LC_ASSET_WITH_C_LICENSE:
        {
            bLicensingIssue = true;
            break;
        }

        default:
            break;
        }

        if (bLicensingIssue)
            ShowLicenseIssue(TaskInfo.StatusText);
        
        AddNotification(TaskInfo.StatusText);

        if (TaskInfo.bLoadedComponent)
            bFinishedLoadInstantiation = true;

        InvalidateTask();

        bStopTicking = true;
        CookCount = 0;
    }

    return bFinishedLoadInstantiation;
}

void UHoudiniAssetTaskRunner::OnProcessing(const FHoudiniEngineTaskInfo& TaskInfo, bool& bStopTicking)
{
    AddNotification(TaskInfo.StatusText);
}

FORCEINLINE bool UHoudiniAssetTaskRunner::HasBeenInstantiatedButNotCooked() const
{
    return FHoudiniEngineUtils::IsValidAssetId(AssetInstance->AssetId) && (CookCount == 0);
}

void UHoudiniAssetTaskRunner::AddNotification(const FText& Message)
{
    const auto HoudiniRuntimeSettings = GetDefault<UHoudiniRuntimeSettings>();

    static float NotificationFadeOutDuration = 2.0f;
    static float NotificationExpireDuration = 2.0f;
    static double NotificationUpdateFrequency = 2.0f;

    // Check whether we want to display Slate cooking and instantiation notifications.
    bool bDisplaySlateCookingNotifications = false;
    if (HoudiniRuntimeSettings)
        bDisplaySlateCookingNotifications = HoudiniRuntimeSettings->bDisplaySlateCookingNotifications;
}

void UHoudiniAssetTaskRunner::ShowLicenseIssue(const FText& Message)
{

}

FORCEINLINE void UHoudiniAssetTaskRunner::SetHapiState(HAPI_Result State)
{
    FHoudiniEngine::Get().SetHapiState(State);
}

FORCEINLINE void UHoudiniAssetTaskRunner::InvalidateTask()
{
    FHoudiniEngine::Get().RemoveTaskInfo(HapiGUID);
    HapiGUID.Invalidate();
}
