#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "HoudiniPlusAssetInfo.generated.h"

USTRUCT(BlueprintType)
struct HOUDINIPLUSEDITOR_API FHoudiniPlusAssetInfo
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    FString Name;
};
