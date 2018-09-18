#include "HappyPrivatePCH.h"

#include "HAPI.h"
#include "Result.h"
#include <ModuleManager.h>
#include "IHappyModule.h"

#if PLATFORM_WINDOWS
    #include "WindowsHWrapper.h"
    #ifdef GetGeoInfo
        #undef GetGeoInfo
    #endif
#endif

FHAPI* FHAPI::InstanceRaw = nullptr;
TSharedPtr<FHAPI> FHAPI::Instance;

TSharedPtr<FHAPI> FHAPI::Get()
{
    // Ensure StartupModule has been called
    auto Module = FModuleManager::LoadModulePtr<IHappyModule>(TEXT("Happy"));

    if (!Instance.IsValid())
    {
        ensure(InstanceRaw != nullptr);
        Instance = MakeShareable(InstanceRaw);
    }

    return Instance;
}

FHAPI::FHAPI(TFunction<const HAPI_Session*()> SessionProvider)
{
    this->SessionProvider = SessionProvider;

    if (!Instance.IsValid())
        InstanceRaw = this;
}

FHAPI::~FHAPI() { }

template <typename TResult>
FORCEINLINE TResult FHAPI::Call(TFunction<TResult(const HAPI_Session*)> Func)
{
    ensure(Func);
    return Func(SessionProvider());
}

FORCEINLINE bool FHAPI::EnsureSuccess(HAPI_Result Result)
{
    ensure(FHAPIResult::IsOK(Result));

    return true;
}

bool FHAPI::SafeCall(TFunction<HAPI_Result(const HAPI_Session*)> Func, EMessageSeverity::Type Severity /*= EMessageSeverity::Error*/)
{
    ensure(Func);

    HAPI_Result Result = Func(SessionProvider());
    if (Result != HAPI_RESULT_SUCCESS)
    {
        // Log
        return false;
    }

    return true;
}

FORCEINLINE bool FHAPI::IsValid() const
{
    return true;
}