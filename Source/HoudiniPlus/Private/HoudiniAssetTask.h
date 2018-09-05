#pragma once

#include "CoreMinimal.h"
#include "TimerManager.h"

#include "HAL/ThreadSafeBool.h"
#include "HAL/ThreadSafeCounter.h"

#include "HAPI_Common.h"

enum class EHoudiniAssetTaskState : int32
{
    Created = 0,
    Faulted = 7,
    RanToCompletion = 5,
    Running = 3,
    WaitingForActivation = 1,
    WaitingForDependenciesToComplete = 4,
    WaitingToRun = 2,
    Stopped = 10
};

/* Loosely based on C# Tasks */
class FHoudiniAssetTask
{
public:
    typedef FHoudiniAssetTask Super;

    FHoudiniAssetTask();
    virtual ~FHoudiniAssetTask() { }

    FORCEINLINE EHoudiniAssetTaskState GetState() const { return (EHoudiniAssetTaskState)(State.GetValue()); }
    FORCEINLINE bool IsComplete() const;
    FORCEINLINE bool IsFaulted() const;
    FORCEINLINE bool IsWaiting() const;
    FORCEINLINE bool IsRunning() const;

    DECLARE_MULTICAST_DELEGATE_OneParam(FOnComplete, HAPI_NodeId)
    FOnComplete OnComplete;

    virtual void Start(float TickRate = 0.25f);
    virtual void Stop();

protected:
    FGuid HapiGuid;

    FTimerHandle TickHandle;

    FThreadSafeBool bStop;
    FThreadSafeBool bStopped;

    FThreadSafeCounter State;
    FORCEINLINE void SetState(EHoudiniAssetTaskState State) { this->State.Set((int32)(State)); }

    DECLARE_MULTICAST_DELEGATE(FOnDependenciesComplete)
    FOnDependenciesComplete OnDependenciesComplete;

    bool CheckDependencies();
    void Invalidate();
    
    virtual void BroadcastResult() = 0;

    virtual void Tick();
};