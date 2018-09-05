#pragma once

#include "CoreMinimal.h"

#include "HoudiniApi.h"
#include "HoudiniAssetParameter.h"

class FHoudiniParameterFactory
{
public:
    typedef TFunction<UHoudiniAssetParameter*(UObject*, UHoudiniAssetParameter*, HAPI_NodeId, const HAPI_ParmInfo&)> TTerraHoudiniParameterFactory;

    static UHoudiniAssetParameter* Create(HAPI_ParmType ParameterType, UObject* PrimaryObject, UHoudiniAssetParameter* ParentParameter, HAPI_NodeId NodeId, const HAPI_ParmInfo& ParameterInfo);

    template <HAPI_ParmType TParameterType>
    static UHoudiniAssetParameter* Create(UObject* PrimaryObject, UHoudiniAssetParameter* ParentParameter, HAPI_NodeId NodeId, const HAPI_ParmInfo& ParameterInfo);

private:
    static TMap<HAPI_ParmType, TTerraHoudiniParameterFactory> Factories;
};
