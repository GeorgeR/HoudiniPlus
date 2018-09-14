#include "HoudiniPlusPrivatePCH.h"

#include "HAPI.h"

FHAPIStatus& FHAPIStatus::operator=(const HAPI_StatusType Status)
{
    this->Status = Status;
    return *this;
}

FORCEINLINE const FString FHAPIStatus::GetStatusString(const HAPI_StatusVerbosity Verbosity)
{
    return FHAPIStatus::GetStatusString(this->Status, Verbosity);
}

FORCEINLINE const FString FHAPIStatus::GetStatusString(const HAPI_StatusType Status, const HAPI_StatusVerbosity Verbosity)
{
    return FHAPI::Get()->Call<FString>([&](auto Session) -> FString{
        auto StatusBufferLength = 0;
        HAPI_GetStatusStringBufLength(Session, Status, Verbosity, &StatusBufferLength);

        if (StatusBufferLength > 0)
        {
            TArray<char> StatusStringBuffer;
            StatusStringBuffer.SetNumZeroed(StatusBufferLength);
            HAPI_GetStatusString(Session, Status, &StatusStringBuffer[0], StatusBufferLength);
            return FString(UTF8_TO_TCHAR(&StatusStringBuffer[0]));
        }

        return TEXT("");
    });
}

FORCEINLINE const FString FHAPIStatus::GetError()
{
    return FHAPIStatus::GetStatusString(HAPI_STATUS_CALL_RESULT, HAPI_STATUSVERBOSITY_ERRORS);
}


FORCEINLINE const FString FHAPIStatus::GetCookState()
{
    return FHAPIStatus::GetStatusString(HAPI_STATUS_COOK_STATE, HAPI_STATUSVERBOSITY_ERRORS);
}

FORCEINLINE const FString FHAPIStatus::GetCookResult()
{
    return FHAPIStatus::GetStatusString(HAPI_STATUS_COOK_RESULT, HAPI_STATUSVERBOSITY_MESSAGES);
}