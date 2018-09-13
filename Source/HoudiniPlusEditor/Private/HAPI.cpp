#include "HoudiniPlusPrivatePCH.h"

#include "HAPI.h"

TSharedPtr<FHAPI> FHAPI::Get()
{
    static TSharedPtr<FHAPI> Instance;
    if (!Instance.IsValid())
    {

    }

    return Instance;
}

bool FHAPI::Call(TFunction<bool(HAPI_Session*)> Func)
{
    ensure(Func);

    return Func(GetSession());
}

bool FHAPI::SafeCall(TFunction<HAPI_Result(HAPI_Session*)> Func, EMessageSeverity::Type Severity /*= EMessageSeverity::Error*/)
{
    ensure(Func);

    HAPI_Result Result = Func(GetSession());
    if (Result != HAPI_RESULT_SUCCESS)
    {
        // Log
        return false;
    }

    return true;
}

HAPI_Session* FHAPI::GetSession()
{
    return nullptr;
}