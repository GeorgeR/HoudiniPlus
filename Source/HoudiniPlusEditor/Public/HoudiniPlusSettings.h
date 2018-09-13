#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "HoudiniPlusSettings.generated.h"

class UHoudiniPlusSession;

UCLASS(config = Engine, defaultconfig)
class HOUDINIPLUSEDITOR_API UHoudiniPlusSettings 
    : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Session")
    TSubclassOf<UHoudiniPlusSession> SessionClass;

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Initialization")
    int32 CookingThreadStackSize;

    virtual ~UHoudiniPlusSettings();

    virtual void PostInitProperties() override;
    virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};