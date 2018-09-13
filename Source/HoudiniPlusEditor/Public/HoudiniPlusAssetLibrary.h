#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "HoudiniPlusAssetInfo.h"

#include "HAPI/HAPI_Common.h"

#include "HoudiniPlusAssetLibrary.generated.h"

UENUM(BlueprintType)
enum class EHoudiniPlusAssetLibraryUsage : uint8
{
    HPALF_None = 0                  UMETA(DisplayName = "None"),
    HPALF_LimitedCommercial = 1     UMETA(DisplayName = "Limited Commercial"),
    HPALF_NonCommercial = 2         UMETA(DisplayName = "Non Commercial"),
};

UCLASS(EditInlineNew)
class HOUDINIPLUSEDITOR_API UHoudiniPlusAssetLibrary 
    : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "File")
    FString FilePath;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "License")
    EHoudiniPlusAssetLibraryUsage Usage;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Instanced, Category = "File")
    UAssetImportData* ImportData;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Asset")
    TArray<FHoudiniPlusAssetInfo> Assets;

    UHoudiniPlusAssetLibrary();
    
    bool SetFromFile(const uint8* Start, const uint8* End, const FString& FilePath);
    bool IsValid() const;

    virtual void FinishDestroy() override;
    virtual void Serialize(FArchive& Ar) override;
    virtual void GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const override;

    virtual void PostLoad() override;
    virtual void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;

private:
    static const uint32 PersistenceFormatVersion;
    
    uint8* Bytes;
    uint32 BytesCount;
    uint32 FileFormatVersion;

    HAPI_AssetLibraryId LibraryId;

    void OnAssetSet();
    void Clear();

    bool TryLoadAsset();
    bool CanResolveFile(FString& OutAbsoluteFilePath);
};