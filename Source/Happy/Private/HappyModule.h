#pragma once

#include "CoreMinimal.h"
#include "IHappyModule.h"
#include "Session.h"

class HAPPY_API FHappyModule
	: public IHappyModule
{
public:
    FHappyModule();
    
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    void StartSession(EHAPISessionType Type = EHAPISessionType::HST_Socket);
    void StopSession();

private:
    void* HAPIHandle;
    TSharedPtr<FHAPISession> Session;
    TSharedPtr<FHAPI> HAPI;
};