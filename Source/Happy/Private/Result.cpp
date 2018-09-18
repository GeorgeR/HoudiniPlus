#include "HappyPrivatePCH.h"

#include "Result.h"

TMap<HAPI_Result, FString> FHAPIResult::Messages;
//TMap<HAPI_Result, FString> FHAPIResult::Messages = TMap<HAPI_Result, FString>{
//    {HAPI_RESULT_FAILURE, TEXT("Generic Failure")},
//    {HAPI_RESULT_ALREADY_INITIALIZED, TEXT("Already Initialized")},
//    {HAPI_RESULT_NOT_INITIALIZED, TEXT("Not Initialized")},
//    {HAPI_RESULT_CANT_LOADFILE, TEXT("Unable to Load File")},
//    {HAPI_RESULT_PARM_SET_FAILED, TEXT("Failed Setting Parameter")},
//    {HAPI_RESULT_INVALID_ARGUMENT, TEXT("Invalid Argument")},
//    {HAPI_RESULT_CANT_LOAD_GEO, TEXT("Unable to Load Geometry")},
//    {HAPI_RESULT_CANT_GENERATE_PRESET, TEXT("Unable to Generate Preset")},
//    {HAPI_RESULT_CANT_LOAD_PRESET, TEXT("Unable to Load Preset")}
//};

FString FHAPIResult::Message_Success = TEXT("Success");
FString FHAPIResult::Message_Failure = TEXT("Generic Failure");

FHAPIResult& FHAPIResult::operator=(const HAPI_Result Result)
{
    this->Result = Result;
    return *this;
}

FORCEINLINE const FString& FHAPIResult::GetError()
{
    return FHAPIResult::GetError(Result);
}

FORCEINLINE const FString& FHAPIResult::GetError(const HAPI_Result Result)
{
    if (Result == HAPI_RESULT_SUCCESS)
        return Message_Success;

    auto bHasMessage = Messages.Contains(Result);
    if (bHasMessage)
        return Messages[Result];

    return Message_Failure;
}