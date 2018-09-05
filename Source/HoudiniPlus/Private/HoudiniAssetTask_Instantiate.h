#pragma once

#include "HoudiniAssetTask.h"
#include "HAPI_Common.h"

class UHoudiniAsset;

class FHoudiniAssetTask_Instantiate
    : public FHoudiniAssetTask
{
public:
    FHoudiniAssetTask_Instantiate(UHoudiniAsset* Asset, HAPI_StringHandle AssetName);

protected:
    HAPI_NodeId AssetId;

    virtual void BroadcastResult() override;
    virtual void Tick() override;
    void PostComplete(const FHoudiniEngineTaskInfo& TaskInfo, bool bHasErrors);
};