#include "HoudiniAssetTask_Cook.h"

#include "HoudiniEngineTask.h"
#include "HoudiniEngine.h"
#include "HoudiniAssetInstance.h"
#include "HoudiniEngineUtils.h"

FHoudiniAssetTask_Cook::FHoudiniAssetTask_Cook(UHoudiniAssetInstance* Instance)
{
    ensure(Instance);

    OnDependenciesComplete.AddLambda([&]()-> void {
        FHoudiniEngineTask Task(EHoudiniEngineTaskType::AssetCooking, HapiGuid);
        Task.AssetId = Instance->GetAssetId();
        
        FHoudiniEngine::Get().AddTask(Task);

        Start();
    });

    CheckDependencies();
}

void FHoudiniAssetTask_Cook::BroadcastResult()
{
    if (OnComplete.IsBound())
        OnComplete.Broadcast(AssetId);
}

void FHoudiniAssetTask_Cook::Tick()
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

void FHoudiniAssetTask_Cook::PostComplete(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors)
{
    if (FHoudiniEngineUtils::IsValidAssetId(TaskInfo.AssetId))
    {
        this->AssetId = TaskInfo.AssetId;
        BroadcastResult();

        // TODO: Notify

        Invalidate();

        SetState(EHoudiniAssetTaskState::RanToCompletion);
        Stop();
    }
}