#pragma once

#include "HoudiniAssetTask.h"

class UHoudiniAssetInstance;

class FHoudiniAssetTask_Cook
    : public FHoudiniAssetTask
{
public:
    FHoudiniAssetTask_Cook(UHoudiniAssetInstance* Instance);

protected:
    HAPI_NodeId AssetId;

    virtual void BroadcastResult() override;
    virtual void Tick() override;
    void PostComplete(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors);
};