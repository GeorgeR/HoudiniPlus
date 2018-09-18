#include "HappyPrivatePCH.h"

#include "Session.h"
#include "HoudiniAPI.h"
#include "HAPI.h"

#if PLATFORM_WINDOWS
#include <WindowsPlatformMisc.h>
#endif

HAPI_Result FHAPISession::Stop()
{
    if (!IsValid())
        return HAPI_RESULT_FAILURE;

    return FHAPI::EnsureSuccess(FHoudiniApi::CloseSession(&Session)) ? HAPI_RESULT_SUCCESS : HAPI_RESULT_FAILURE;
}

bool FHAPISession::IsValid() const
{
    return FHAPIResult::IsOK(FHoudiniApi::IsSessionValid(&Session));
}

HAPI_ThriftServerOptions& FHAPISession::GetOptions()
{
    static HAPI_ThriftServerOptions Options;
    FMemory::Memzero<HAPI_ThriftServerOptions>(Options);
    Options.autoClose = true;
    Options.timeoutMs = 3000.0f;

    return Options;
}

FHAPISession_InProcess::FHAPISession_InProcess()
{
    FHAPI::EnsureSuccess(FHoudiniApi::CreateInProcessSession(&Session));
#if PLATFORM_WINDOWS
    FWindowsPlatformMisc::SetUTF8Output();
#endif
}

FHAPISession_InProcess::~FHAPISession_InProcess()
{
    Stop();
}

HAPI_Result FHAPISession_InProcess::Start()
{
    return HAPI_RESULT_SUCCESS;
}

FHAPISession_Socket::FHAPISession_Socket(const FString Host, const int32 Port)
{
    this->Host = Host;
    this->Port = Port;

    FHAPI::EnsureSuccess(FHoudiniApi::StartThriftSocketServer(nullptr, Port, &ProcessId));
}

FHAPISession_Socket::~FHAPISession_Socket()
{
    Stop();
}

HAPI_Result FHAPISession_Socket::Start()
{
    return FHoudiniApi::CreateThriftSocketSession(&Session, TCHAR_TO_UTF8(*Host), Port);
}

FHAPISession_NamedPipe::FHAPISession_NamedPipe(FString PipeName)
{
    if (PipeName.IsEmpty())
    {
#if PLATFORM_MAC
        PipeName = TEXT("/tmp/hapi");
#else
        PipeName = TEXT("hapi");
#endif
    }

    this->PipeName = PipeName;

    FHAPI::EnsureSuccess(FHoudiniApi::StartThriftNamedPipeServer(nullptr, TCHAR_TO_UTF8(*PipeName), &ProcessId));
}

FHAPISession_NamedPipe::~FHAPISession_NamedPipe()
{
    Stop();
}

HAPI_Result FHAPISession_NamedPipe::Start()
{
    return FHoudiniApi::CreateThriftNamedPipeSession(&Session, TCHAR_TO_UTF8(*PipeName));
}