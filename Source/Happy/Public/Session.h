#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Result.h"

#include "Session.generated.h"

UENUM(BlueprintType)
enum class EHAPISessionType : uint8
{
    HST_InProcess       UMETA(DisplayName = "In Process"),
    HST_Socket          UMETA(DisplayName = "Socket"),
    HST_NamedPiped      UMETA(DisplayName = "Named Pipe")
};

class HAPPY_API FHAPISession
{
public:
    virtual HAPI_Result Start() = 0;
    virtual HAPI_Result Stop();

    virtual bool IsValid() const;

    const FORCEINLINE HAPI_Session* GetHandle() const { return &Session; }

protected:
    HAPI_Session Session;

    HAPI_ThriftServerOptions& GetOptions();
};

class HAPPY_API FHAPISession_InProcess : public FHAPISession
{
public:
    FHAPISession_InProcess();
    virtual ~FHAPISession_InProcess();
    
    virtual HAPI_Result Start() override;
};

class HAPPY_API FHAPISession_Socket : public FHAPISession
{
public:
    FHAPISession_Socket(const FString Host = TEXT("localhost"), const int32 Port = 9090);
    virtual ~FHAPISession_Socket();

    virtual HAPI_Result Start() override;

private:
    FString Host;
    int32 Port;
    HAPI_ProcessId ProcessId;
};

class HAPPY_API FHAPISession_NamedPipe : public FHAPISession
{
public:
    FHAPISession_NamedPipe(FString PipeName = TEXT(""));
    virtual ~FHAPISession_NamedPipe();
    
    virtual HAPI_Result Start() override;

private:
    FString PipeName;
    HAPI_ProcessId ProcessId;
};