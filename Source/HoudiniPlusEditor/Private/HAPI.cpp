#include "HoudiniPlusPrivatePCH.h"

#include "HoudiniPlusSettings.h"
#include "HAPI.h"

#if PLATFORM_WINDOWS
    #include "WindowsHWrapper.h"
    #ifdef GetGeoInfo
        #undef GetGeoInfo
    #endif
#endif

TSharedPtr<FHAPI> FHAPI::Instance;

FHAPI::FHAPI()
{
    Handle = MakeShareable(new FHAPIHandle);

    if (!Instance.IsValid())
        Instance = this->AsShared();
}

FHAPI::~FHAPI()
{

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



