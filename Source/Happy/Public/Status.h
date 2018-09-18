#pragma once

#include "CoreMinimal.h"

#include "HAPI/HAPI_Common.h"

struct HAPPY_API FHAPIStatus
{
private:
    // Prevent explicit creation
    FHAPIStatus() : Status(HAPI_STATUS_MAX) { }

public:
    FHAPIStatus & operator=(const HAPI_StatusType Status);

    FORCEINLINE const FString GetStatusString(const HAPI_StatusVerbosity Verbosity);
    static FORCEINLINE const FString GetStatusString(const HAPI_StatusType Status, const HAPI_StatusVerbosity Verbosity);

    static FORCEINLINE const FString GetError();
    static FORCEINLINE const FString GetCookState();
    static FORCEINLINE const FString GetCookResult();

private:
    HAPI_StatusType Status;
};