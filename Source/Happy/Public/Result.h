#pragma once

#include "CoreMinimal.h"

#include "HAPI/HAPI_Common.h"

struct HAPPY_API FHAPIResult
{
private:
    // Prevent explicit creation
    FHAPIResult() : Result(HAPI_RESULT_SUCCESS) { }

public:
    FHAPIResult & operator=(const HAPI_Result Result);

    FORCEINLINE bool IsOK() const { return FHAPIResult::IsOK(Result); }
    static FORCEINLINE bool IsOK(const HAPI_Result Result) { return Result == HAPI_RESULT_SUCCESS; }

    FORCEINLINE const FString& GetError();
    static FORCEINLINE const FString& GetError(const HAPI_Result Result);

private:
    static TMap<HAPI_Result, FString> Messages;
    static FString Message_Success;
    static FString Message_Failure;

    HAPI_Result Result;
};