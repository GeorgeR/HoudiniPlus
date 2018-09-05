#include "HoudiniAssetTask.h"
#include "UnrealEd.h"

FHoudiniAssetTask::FHoudiniAssetTask()
{
    HapiGuid = FGuid::NewGuid();
}

FORCEINLINE bool FHoudiniAssetTask::IsComplete() const
{
    auto State = GetState();
    return State == EHoudiniAssetTaskState::RanToCompletion
        || State == EHoudiniAssetTaskState::Faulted
        || State == EHoudiniAssetTaskState::Stopped;
}

FORCEINLINE bool FHoudiniAssetTask::IsFaulted() const
{
    return GetState() == EHoudiniAssetTaskState::Faulted;
}

FORCEINLINE bool FHoudiniAssetTask::IsWaiting() const
{
    auto State = GetState();
    return State == EHoudiniAssetTaskState::WaitingForActivation
        || State == EHoudiniAssetTaskState::WaitingForDependenciesToComplete
        || State == EHoudiniAssetTaskState::WaitingToRun
        || State == EHoudiniAssetTaskState::Created;
}

FORCEINLINE bool FHoudiniAssetTask::IsRunning() const
{
    return GetState() == EHoudiniAssetTaskState::Running;
}

void FHoudiniAssetTask::Start(float TickRate /*= 0.25f*/)
{
    ensure(GEditor);
    ensure(TickRate >= 0.0f);

    GEditor->GetTimerManager()->SetTimer(TickHandle, this, &FHoudiniAssetTask::Tick, TickRate, true);
}

bool FHoudiniAssetTask::CheckDependencies()
{
    bool bHasDependencies = false;


    if (!bHasDependencies)
        if (OnDependenciesComplete.IsBound())
            OnDependenciesComplete.Broadcast();

    return bHasDependencies;
}

void FHoudiniAssetTask::Invalidate()
{
    FHoudiniEngine::Get().RemoveTaskInfo(HapiGuid);
    HapiGuid.Invalidate();
}

void FHoudiniAssetTask::Tick()
{
    if (bStopped == true || !HapiGuid.IsValid())
        return;

    if (bStop == true)
    {
        bStopped.AtomicSet(true);
        return;
    }
        
    if (!IsComplete() && !IsFaulted())
        SetState(EHoudiniAssetTaskState::Running);
}

void FHoudiniAssetTask::Stop()
{
    if (!bStopped)
    {
        bStop.AtomicSet(true);
        return;
    }
    
    if (!IsComplete() && !IsFaulted())
        SetState(EHoudiniAssetTaskState::Stopped);

    BroadcastResult();
}
