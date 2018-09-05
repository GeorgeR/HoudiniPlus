#pragma once

#include "CoreMinimal.h"

#include "HoudiniApi.h"

#include "HoudiniAssetInstance.generated.h"

class UHoudiniAsset;
class UHoudiniAssetParameter;

struct FHoudiniAssetInstanceData
{
public:
    UHoudiniAsset* Asset;
    FString AssetName;
    TMap<HAPI_ParmId, UHoudiniAssetParameter*> Parameters;

    FHoudiniAssetInstanceData(const UHoudiniAssetInstance* Instance);

    bool AssetIsSame(const UHoudiniAsset* Other);
    bool AssetNameIsSame(const FString& Other);
};

UCLASS(BlueprintType)
class HOUDINIPLUS_API UHoudiniAssetInstance
    : public UObject 
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Asset")
    UHoudiniAsset* Asset;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Asset")
    FString AssetName;

    UFUNCTION(BlueprintCallable, Category = "Creation")
    static UHoudiniAssetInstance* Create(UObject* Outer, UPARAM(DisplayName = "Asset") UHoudiniAsset* InAsset, const FString& Name = TEXT(""));

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Debug")
    FORCEINLINE bool HasError() const { return LastError.Len() > 0; }

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Debug")
    FORCEINLINE FString GetLastError() const { return LastError; }

    // TODO: Get notified on asset changed/reloaded

    /* This checks instance validity, EXCLUDING any errors (use HasError()). */
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Debug")
    bool IsValid() const;

    virtual void PostInitProperties() override;

private:
    friend struct FHoudiniAssetInstanceData;

    UPROPERTY()
    FString LastError;

    UPROPERTY()
    TArray<FString> AssetNames;

    HAPI_AssetLibraryId AssetLibraryId;
    HAPI_NodeId AssetId;

    TMap<HAPI_ParmId, UHoudiniAssetParameter*> ParametersById;
    TMap<FString, UHoudiniAssetParameter*> ParametersByName;

    void Initialize(UHoudiniAsset* Asset, const FString& Name);

    void OnAssetNameSet(const FString& Name);

    void Clear(bool bKeepNames = false);

    bool CreateParameters();
    bool CreateInputs();
    bool CreateAttributes();

    bool GetAssetNames(HAPI_AssetLibraryId& LibraryId);
    bool GetAssetAndNodeInfo(const HAPI_NodeId& AssetId, HAPI_AssetInfo& AssetInfo, HAPI_NodeInfo& NodeInfo);
};