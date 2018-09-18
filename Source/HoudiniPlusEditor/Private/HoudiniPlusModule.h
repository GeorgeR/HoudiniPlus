#pragma once

#include "CoreMinimal.h"
#include "IHoudiniPlusModule.h"

class HOUDINIPLUSEDITOR_API FHoudiniPlusModule
	: public IHoudiniPlusModule
{
public:
    FHoudiniPlusModule();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};