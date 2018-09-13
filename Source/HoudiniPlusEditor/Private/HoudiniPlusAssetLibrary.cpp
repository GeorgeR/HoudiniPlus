#include "HoudiniPlusPrivatePCH.h"

#include "HoudiniPlusAssetLibrary.h"

const uint32 UHoudiniPlusAssetLibrary::PersistenceFormatVersion = 2u;

UHoudiniPlusAssetLibrary::UHoudiniPlusAssetLibrary()
    : FilePath(TEXT("")),
    Bytes(nullptr),
    BytesCount(0),
    FileFormatVersion(UHoudiniPlusAssetLibrary::PersistenceFormatVersion),
    Usage(EHoudiniPlusAssetLibraryUsage::HPALF_None) { }

bool UHoudiniPlusAssetLibrary::SetFromFile(const uint8* BufferStart, const uint8* BufferEnd, const FString& FilePath)
{
    ensure(FPaths::FileExists(FilePath));
    
    this->FilePath = FilePath;
    BytesCount = BufferEnd - BufferStart;
    if (BytesCount > 0)
    {
        Bytes = static_cast<uint8*>(FMemory::Malloc(BytesCount));
        if (Bytes != nullptr)
            FMemory::Memcpy(Bytes, BufferStart, BytesCount);
    }

    auto FileExtension = FPaths::GetExtension(FilePath);
    if (FileExtension.EndsWith(TEXT("lc"), ESearchCase::IgnoreCase))
        Usage = EHoudiniPlusAssetLibraryUsage::HPALF_LimitedCommercial;
    else if (FileExtension.EndsWith(TEXT("nc"), ESearchCase::IgnoreCase))
        Usage = EHoudiniPlusAssetLibraryUsage::HPALF_NonCommercial;

    return true;
}

bool UHoudiniPlusAssetLibrary::IsValid() const
{
    // TODO: Add more validation
    return Bytes != nullptr;
}

void UHoudiniPlusAssetLibrary::FinishDestroy()
{
    if (Bytes != nullptr)
    {
        FMemory::Free(Bytes);
        Bytes = nullptr;
        BytesCount = 0;
    }

    Super::FinishDestroy();
}

void UHoudiniPlusAssetLibrary::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar);

    // TODO
    //Ar.UsingCustomVersion(FHoudiniCustomSerializationVersion::GUID);

    Ar << FileFormatVersion;
    Ar << BytesCount;

    if (Ar.IsLoading())
    {
        if (Bytes != nullptr)
        {
            FMemory::Free(Bytes);
            Bytes = nullptr;
        }

        if (BytesCount > 0)
            Bytes = static_cast<uint8*>(FMemory::Malloc(BytesCount));
    }

    if (Bytes != nullptr && BytesCount > 0)
        Ar.Serialize(Bytes, BytesCount);

    Ar << Usage;
    Ar << FilePath;
}

void UHoudiniPlusAssetLibrary::GetAssetRegistryTags(TArray<FAssetRegistryTag>& OutTags) const
{
    OutTags.Add(FAssetRegistryTag("FilePath", FilePath, FAssetRegistryTag::TT_Alphabetical));
    OutTags.Add(FAssetRegistryTag("FileFormatVersion", FString::FromInt(FileFormatVersion), FAssetRegistryTag::TT_Numerical));
    OutTags.Add(FAssetRegistryTag("Bytes", FString::FromInt(BytesCount), FAssetRegistryTag::TT_Numerical));

    FString AssetType = TEXT("Full");

    if (Usage == EHoudiniPlusAssetLibraryUsage::HPALF_LimitedCommercial)
        AssetType = TEXT("Limited Commercial (LC)");
    else if (Usage == EHoudiniPlusAssetLibraryUsage::HPALF_NonCommercial)
        AssetType = TEXT("Non Commercial (NC)");

    OutTags.Add(FAssetRegistryTag("Asset Type", AssetType, FAssetRegistryTag::TT_Alphabetical));

    Super::GetAssetRegistryTags(OutTags);
}

void UHoudiniPlusAssetLibrary::PostLoad()
{
    Super::PostLoad();
}

void UHoudiniPlusAssetLibrary::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
    Super::PostEditChangeChainProperty(PropertyChangedEvent);
}

void UHoudiniPlusAssetLibrary::OnAssetSet()
{
    // TODO: Validate the asset itself

    Clear();

    if (!TryLoadAsset())
        return;

    HAPI_Result Result = HAPI_RESULT_FAILURE;
    //FHAPIInterface::Get()->Execute([&](HAPI_Session* Session) {
    //    HAPI_Result Result = HAPI_RESULT_FAILURE;

    //    FString AbsoluteFilePath;
    //    bool bFileExists = CanResolveFile(AbsoluteFilePath);

    //    int32 AssetCount = -1;
    //    Result = HAPI_GetAvailableAssetCount(Session, LibraryId, &AssetCount);
    //    if (Result != HAPI_RESULT_SUCCESS)
    //    {
    //        // Log Message
    //        return false;
    //    }

    //    if (AssetCount <= 0)
    //    {
    //        // Log message
    //        return false;
    //    }

    //    TArray<HAPI_StringHandle> AssetNames;
    //    AssetNames.SetNumUninitialized(AssetCount);

    //    Result = HAPI_GetAvailableAssets(Session, LibraryId, &AssetNames[0], AssetCount);
    //    if (Result != HAPI_RESULT_SUCCESS)
    //    {
    //        // Log message
    //        return false;
    //    }

    //    if (AssetCount == 0)
    //    {
    //        // Log message
    //        return false;
    //    }

    //    Assets.SetNumUninitialized(AssetNames);
    //    for (auto i = 0; i < AssetNames.Num(); i++)
    //        Assets[i] = FHoudiniPlusAssetInfo(AssetNames[i]);

    //    return true;
    //});
}

void UHoudiniPlusAssetLibrary::Clear()
{
    Assets.Empty();
}

bool UHoudiniPlusAssetLibrary::TryLoadAsset()
{
    return false;

    //return FHAPIInterface::Get()->Execute([&](HAPI_Session* Session) {
    //    HAPI_Result Result = HAPI_RESULT_FAILURE;

    //    FString AbsoluteFilePath;
    //    bool bFileExists = CanResolveFile(AbsoluteFilePath);

    //    if (bFileExists)
    //    {
    //        std::string AbsoluteFilePathStd;
    //        // Convert AbsoluteFilePath to above

    //        Result = HAPI_LoadAssetLibraryFromFile(Session, *AbsoluteFilePath, true, &LibraryId);
    //    }

    //    // Something went wrong
    //    if (Result != HAPI_RESULT_SUCCESS)
    //    {
    //        auto FileExtension = FPaths::GetExtension(AbsoluteFilePath);
    //        if (FileExtension.Compare(TEXT("hdalibrary"), ESearchCase::IgnoreCase) == 0)
    //        {
    //            // Log Error
    //            return false;
    //        }
    //        else
    //        {
    //            // Log Warning

    //            Result = HAPI_LoadAssetLibraryFromMemory(Session, reinterpret_cast<const char*>(Bytes)), BytesCount, true, &LibraryId);
    //        }
    //    }

    //    if (Result != HAPI_RESULT_SUCCESS)
    //    {
    //        // Log message
    //        return false;
    //    }

    //    return true;
    //});
}

bool UHoudiniPlusAssetLibrary::CanResolveFile(FString& OutAbsoluteFilePath)
{
    OutAbsoluteFilePath = FilePath;
    if (FPaths::IsRelative(FilePath))
        OutAbsoluteFilePath = FPaths::ConvertRelativePathToFull(OutAbsoluteFilePath);

    if (OutAbsoluteFilePath.IsEmpty() || !FPaths::FileExists(OutAbsoluteFilePath))
    {
        OutAbsoluteFilePath.Empty();
        return false;
    }
        
    return true;
}