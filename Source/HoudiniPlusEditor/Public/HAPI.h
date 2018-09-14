#pragma once

#include "CoreMinimal.h"
#include "Logging/TokenizedMessage.h"

#include "HAPI/HAPI_Common.h"

struct HAPI_Session;
enum HAPI_Result;

struct HOUDINIPLUSEDITOR_API FHAPIStatus
{
private:
    // Prevent explicit creation
    FHAPIStatus() : Status(HAPI_STATUS_MAX) { }

public:
    FHAPIStatus& operator=(const HAPI_StatusType Status);

    FORCEINLINE const FString GetStatusString(const HAPI_StatusVerbosity Verbosity);
    static FORCEINLINE const FString GetStatusString(const HAPI_StatusType Status, const HAPI_StatusVerbosity Verbosity);

    static FORCEINLINE const FString GetError();
    static FORCEINLINE const FString GetCookState();
    static FORCEINLINE const FString GetCookResult();

private:
    HAPI_StatusType Status;
};

struct HOUDINIPLUSEDITOR_API FHAPIResult
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

struct HOUDINIPLUSEDITOR_API FHAPIVersion
{
public:
    int32 Major;
    int32 Minor;
    int32 Build;
    int32 Patch = -1;

    FHAPIVersion();
    
    const FString& ToString();

private:
    FString Str;
};

class HOUDINIPLUSEDITOR_API FHAPIHandle
{
public:
    FHAPIHandle();
    ~FHAPIHandle();

    bool Load(const FString& Location);

    FORCEINLINE bool IsValid() const { return HAPIHandle != nullptr && !HAPIPath.IsEmpty(); }

private:
    FString HAPIPath;
    void* HAPIHandle;

    FORCEINLINE bool GetHFSPathFromEnvironment(FString& Result) const;
    FORCEINLINE bool TryGetCustomHFSPath(const FString& LibName, FString& Result) const;
    const FORCEINLINE FString& GetLibHAPIName() const;
    FORCEINLINE bool TryLocateInHoudini(const FString& LibName, FHAPIVersion& Version, FString& HoudiniPath);
    FORCEINLINE bool TryGetHandle(const FString& Path, const FString& Name);

#if PLATFORM_WINDOWS
    FORCEINLINE void* TryLocateInRegistry(const FString& InstallationType, FHAPIVersion& Version, FString& HAPIPath);
#endif
};

class HOUDINIPLUSEDITOR_API FHAPI 
    : public TSharedFromThis<FHAPI>
{
public:
    static FORCEINLINE TSharedPtr<FHAPI> Get() { return Instance; }

    FHAPI();
    virtual ~FHAPI();
    
    FORCEINLINE bool Load(const FString& Location) { return Handle->Load(Location); }

    template <typename TResult>
    FORCEINLINE TResult Call(TFunction<TResult(HAPI_Session*)> Func);

    FORCEINLINE bool SafeCall(TFunction<HAPI_Result(HAPI_Session*)> Func, EMessageSeverity::Type Severity = EMessageSeverity::Error);

    FORCEINLINE bool IsValid() const;

private:
    static TSharedPtr<FHAPI> Instance;

    TSharedPtr<FHAPIHandle> Handle;
    HAPI_Session* GetSession();
};

template <typename TResult>
FORCEINLINE TResult FHAPI::Call(TFunction<TResult(HAPI_Session*)> Func)
{
    ensure(Func);
    return Func(GetSession());
}