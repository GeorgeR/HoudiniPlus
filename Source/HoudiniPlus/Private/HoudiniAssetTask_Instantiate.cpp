#include "HoudiniAssetTask_Instantiate.h"

#include "HoudiniEngineTask.h"
#include "HoudiniEngine.h"
#include "HoudiniAssetInstance.h"
#include "HoudiniEngineUtils.h"

FHoudiniAssetTask_Instantiate::FHoudiniAssetTask_Instantiate(UHoudiniAsset* Asset, HAPI_StringHandle AssetName)
{
    ensure(Asset);

    OnDependenciesComplete.AddLambda([&]()-> void{
        FHoudiniEngineTask Task(EHoudiniEngineTaskType::AssetInstantiation, HapiGuid);
        Task.Asset = Asset;
        Task.AssetLibraryId = -1;
        Task.AssetHapiName = AssetName;

        FHoudiniEngine::Get().AddTask(Task);

        Start();
    });
    
    CheckDependencies();
}

void FHoudiniAssetTask_Instantiate::BroadcastResult()
{
    if (OnComplete.IsBound())
        OnComplete.Broadcast(AssetId);
}

void FHoudiniAssetTask_Instantiate::Tick()
{
    Super::Tick();

    FHoudiniEngineTaskInfo TaskInfo;

    if (HapiGuid.IsValid())
    {
        if (FHoudiniEngine::Get().RetrieveTaskInfo(HapiGuid, TaskInfo))
        {

        }
        else
        {
            HapiGuid.Invalidate();
            Stop();
        }
    }
}

void FHoudiniAssetTask_Instantiate::PostComplete(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors)
{
    if (!bHasErrors)
    {
        if (FHoudiniEngineUtils::IsValidAssetId(TaskInfo.AssetId))
        {
            this->AssetId = TaskInfo.AssetId;
            BroadcastResult();

            Invalidate();

            FHoudiniEngine::Get().SetHapiState(HAPI_RESULT_SUCCESS);

            SetState(EHoudiniAssetTaskState::RanToCompletion);
            Stop();
        }
        else 
        {
            SetState(EHoudiniAssetTaskState::Faulted);
            Stop();
        }
    }
    else
    {
        bool bLicensingIssue = false;
        switch (TaskInfo.Result)
        {
        case HAPI_RESULT_NO_LICENSE_FOUND:
        {
            FHoudiniEngine::Get().SetHapiState(HAPI_RESULT_NO_LICENSE_FOUND);
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

        // TODO
        //if (bLicensingIssue)
        //    ShowLicenseIssue(TaskInfo.StatusText);

        //AddNotification(TaskInfo.StatusText);

        Invalidate();

        SetState(EHoudiniAssetTaskState::Faulted);
        Stop();
    }
}