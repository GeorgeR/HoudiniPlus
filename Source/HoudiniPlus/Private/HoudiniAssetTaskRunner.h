#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimerManager.h"
#include "Async/Future.h"

#include "HoudiniEngineTaskInfo.h"

#include "HoudiniAssetTaskRunner.generated.h"

class UHoudiniAsset;

/* Handles one task at a time, for a single HoudiniAssetInstance */
UCLASS(Transient, Within = "HoudiniAssetInstance")
class HOUDINIPLUS_API UHoudiniAssetTaskRunner 
    : public UObject
{
	GENERATED_BODY()
	
public:
    // HAPI_NodeId AssetId
    DECLARE_MULTICAST_DELEGATE_OneParam(FOnInstantiated, HAPI_NodeId)
    FOnInstantiated OnInstantiated;

    bool StartInstantiation(UHoudiniAsset* Asset, HAPI_StringHandle AssetName);

    // HAPI_NodeID AssetId, bool bHasErrors
    DECLARE_MULTICAST_DELEGATE_TwoParams(FOnCooked, HAPI_NodeId, bool)
    FOnCooked OnCooked;

    bool StartCooking(HAPI_NodeId AssetId);

private:
    FGuid HapiGUID;
    double HapiNotificationStarted;
    int32 CookCount;

    bool bIsBeingInstantiated;
    bool bWaitingForDependencies;
    bool bRequiresInstantiation;

    FTimerHandle CookingHandle;
    FTimerDelegate OnCooking;

    FTimerHandle UpdateUIHandle;
    FTimerDelegate OnUpdateUI;

    void Start();
    void Tick();
    void Stop();

    void StartUI();
    void TickUI();
    void StopUI();

    bool UpdateDependencies(bool bNotifyDependency);
    
    void OnFinishedCooking(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors, bool& bStopTicking);
    bool OnFinishedInstantiation(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors, bool& bStopTicking);
    void OnProcessing(const FHoudiniEngineTaskInfo& TaskInfo, bool& bStopTicking);

    FORCEINLINE bool IsRunning() const { return HapiGUID.IsValid(); }
    FORCEINLINE bool HasBeenInstantiatedButNotCooked() const;

    void AddNotification(const FText& Message);
    void ShowLicenseIssue(const FText& Message);

    FORCEINLINE void SetHapiState(HAPI_Result State);
    FORCEINLINE void InvalidateTask();
};