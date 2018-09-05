#include "HoudiniAssetInstance.h"

#include "HoudiniAsset.h"
#include "HoudiniEngine.h"
#include "HoudiniEngineUtils.h"
#include "HoudiniEngineString.h"

FHoudiniAssetInstanceData::FHoudiniAssetInstanceData(const UHoudiniAssetInstance* Instance)
{
    this->Asset = Instance->Asset;
    this->AssetName = Instance->AssetName;
    this->Parameters = Instance->ParametersById;
}

bool FHoudiniAssetInstanceData::AssetIsSame(const UHoudiniAsset* Other)
{
    if (this->Asset == nullptr)
        return false;

    return this->Asset->AssetFileName.Equals(Other->AssetFileName, ESearchCase::IgnoreCase);
}

bool FHoudiniAssetInstanceData::AssetNameIsSame(const FString& Other)
{
    if (this->AssetName.Len() <= 0 || Other.Len() <= 0)
        return false;

    return this->AssetName.Equals(Other, ESearchCase::IgnoreCase);
}

UHoudiniAssetInstance* UHoudiniAssetInstance::Create(UObject* Outer, UHoudiniAsset* Asset, const FString& Name /*= TEXT("")*/)
{
    ensure(Outer);
    ensure(Asset);

    auto Result = NewObject<UHoudiniAssetInstance>(Outer);
    Result->Initialize(Asset, Name);

    return Result;
}

// NOTE: Can be valid but be errored
bool UHoudiniAssetInstance::IsValid() const
{
    // TODO: add more validation
    return this->Asset != nullptr
        && this->AssetName.Len() > 0;
}

void UHoudiniAssetInstance::PostInitProperties()
{
    Super::PostInitProperties();

    if (this->HasAnyFlags(EObjectFlags::RF_ClassDefaultObject))
        return;

    Initialize(this->Asset, this->AssetName);
}

void UHoudiniAssetInstance::Initialize(UHoudiniAsset* Asset, const FString& Name)
{
    ensure(Asset);

    auto PreviousData = FHoudiniAssetInstanceData(this);

    Clear(false);

    auto bIsNewAsset = !PreviousData.AssetIsSame(Asset);
    auto bIsNewName = !PreviousData.AssetNameIsSame(Name);

    if (bIsNewAsset) this->Asset = Asset;
    
    if (!GetAssetNames(this->AssetLibraryId))
        return;

    auto PreviousOrNewAssetName = bIsNewName ? Name : PreviousData.AssetName;
    if (PreviousOrNewAssetName.Len() > 0)
    {
        if (auto FoundAsset = AssetNames.FindByPredicate([&](FString& Str) -> bool { return Str.Equals(PreviousOrNewAssetName, ESearchCase::IgnoreCase); }))
            this->AssetName = *FoundAsset;
        else
        {
            LastError = TEXT("Asset with the name specified was not found in the input Asset.");
            return;
        }
    }
    else
        this->AssetName = this->AssetNames[0];

    OnAssetNameSet(this->AssetName);
}

void UHoudiniAssetInstance::OnAssetNameSet(const FString& Name)
{
    ensure(Name.Len() > 0);

    Clear(true);


}

void UHoudiniAssetInstance::Clear(bool bKeepNames)
{
    LastError.Empty();
    if(!bKeepNames) AssetNames.Empty();

    ParametersById.Empty();
    ParametersByName.Empty();

    AssetLibraryId = -1;
    AssetId = -1;
}

bool UHoudiniAssetInstance::CreateParameters()
{
    return true;
}

bool UHoudiniAssetInstance::CreateInputs()
{
    return true;
}

bool UHoudiniAssetInstance::CreateAttributes()
{
    return true;
}

bool UHoudiniAssetInstance::GetAssetNames(HAPI_AssetLibraryId& LibraryId)
{
    if (this->AssetNames.Num() > 0)
        return true;

    TArray<HAPI_StringHandle> AssetNames;
    if (!this->Asset->GetAssetNames(LibraryId, AssetNames))
    {
        LastError = TEXT("Input Asset contains no AssetNames (it's empty).");
        return false;
    }

    this->AssetLibraryId = LibraryId;

    for (HAPI_StringHandle& AssetName : AssetNames)
    {
        FString AssetNameStr;
        FHoudiniEngineString(AssetName).ToFString(AssetNameStr);
        this->AssetNames.Add(AssetNameStr);
    }

    return true;
}

bool UHoudiniAssetInstance::GetAssetAndNodeInfo(const HAPI_NodeId& AssetId, HAPI_AssetInfo& AssetInfo, HAPI_NodeInfo& NodeInfo)
{
    auto Result = HAPI_RESULT_SUCCESS;

    Result = FHoudiniApi::GetAssetInfo(FHoudiniEngine::Get().GetSession(), AssetId, &AssetInfo);
    if (Result != HAPI_RESULT_SUCCESS)
    {
        LastError = TEXT("Error getting AssetInfo");
        return false;
    }

    Result = FHoudiniApi::GetNodeInfo(FHoudiniEngine::Get().GetSession(), AssetInfo.nodeId, &NodeInfo);
    if (Result != HAPI_RESULT_SUCCESS)
    {
        LastError = TEXT("Error getting NodeInfo");
        return false;
    }

    return true;
}