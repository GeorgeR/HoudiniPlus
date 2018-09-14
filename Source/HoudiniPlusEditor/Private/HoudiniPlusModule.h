#pragma once

#include "CoreMinimal.h"
#include "IHoudiniPlusModule.h"

class HOUDINIPLUSEDITOR_API FHoudiniPlusModule
	: public IHoudiniPlusModule
{
public:
    static const FString HoudiniEngineAppIdentifier;

    FHoudiniPlusModule();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

    virtual bool CheckHapiVersionMismatch() const override;

    virtual HAPI_Result GetHapiState() const override;
    virtual void SetHapiState(HAPI_Result Result) override;

    virtual const HAPI_Session* GetSession() override;

    //bool StartSession(HAPI_Session*& Session);
    //bool StopSession(HAPI_Session*& Session);
    //bool RestartSession();

private:
    HAPI_Result HAPIState;
    bool bHAPIVersionMismatch;
};