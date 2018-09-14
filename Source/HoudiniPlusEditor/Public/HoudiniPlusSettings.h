#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "HoudiniPlusSession.h"

#include "HoudiniPlusSettings.generated.h"

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

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Location", meta = (DisplayName = "Use custom Houdini location (requires restart)."))
    bool bUseCustomHoudiniLocation;

    UPROPERTY(GlobalConfig, EditAnywhere, Category = "Location", meta = (DisplayName = "Custom Houdini Location."))
    FDirectoryPath CustomHoudiniLocation;

    virtual ~UHoudiniPlusSettings();

    virtual void PostInitProperties() override;
    virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};