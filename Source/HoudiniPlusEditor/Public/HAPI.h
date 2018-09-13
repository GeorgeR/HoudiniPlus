#pragma once

#include "CoreMinimal.h"
#include "Logging/TokenizedMessage.h"

struct HAPI_Session;
enum HAPI_Result;

class HOUDINIPLUSEDITOR_API FHAPI 
    : public TSharedFromThis<FHAPI>
{
public:
    static FORCEINLINE TSharedPtr<FHAPI> Get();

    FORCEINLINE bool Call(TFunction<bool(HAPI_Session*)> Func);

    FORCEINLINE bool SafeCall(TFunction<HAPI_Result(HAPI_Session*)> Func, EMessageSeverity::Type Severity = EMessageSeverity::Error);

private:
    HAPI_Session* GetSession();
};