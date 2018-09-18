#pragma once

#include "CoreMinimal.h"
#include "Logging/TokenizedMessage.h"

#include "HAPI/HAPI_Common.h"

class HAPPY_API FHAPI 
    : public TSharedFromThis<FHAPI>
{
public:
    static TSharedPtr<FHAPI> Get();

    FHAPI(TFunction<const HAPI_Session*()> SessionProvider);
    virtual ~FHAPI();

    template <typename TResult>
    FORCEINLINE TResult Call(TFunction<TResult(const HAPI_Session*)> Func);

    static FORCEINLINE bool EnsureSuccess(HAPI_Result Result);

    FORCEINLINE bool SafeCall(TFunction<HAPI_Result(const HAPI_Session*)> Func, EMessageSeverity::Type Severity = EMessageSeverity::Error);

    FORCEINLINE bool IsValid() const;

private:
    static FHAPI* InstanceRaw;
    static TSharedPtr<FHAPI> Instance;
    TFunction<const HAPI_Session*()> SessionProvider;
};