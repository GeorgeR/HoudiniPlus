#include "HoudiniPlusPrivatePCH.h"

#include "HAPI.h"

FHAPIHandle::FHAPIHandle()
    : HAPIHandle(nullptr) { }

FHAPIHandle::~FHAPIHandle()
{
    if (HAPIHandle != nullptr)
    {
        delete HAPIHandle;
        HAPIHandle = nullptr;
    }
}

bool FHAPIHandle::Load(const FString& Location)
{
    FString HFSPath = TEXT("");
    bool bPathFromEnvironmentFound = GetHFSPathFromEnvironment(HFSPath);

    auto LibName = GetLibHAPIName();

    bool bCustomPathFound = TryGetCustomHFSPath(LibName, HFSPath);

    if (bPathFromEnvironmentFound || bCustomPathFound)
    {
        if (!bCustomPathFound)
        {
#if PLATFORM_WINDOWS
            HFSPath = FPaths::Combine(HFSPath, HAPI_HFS_SUBFOLDER_WINDOWS);
#elif PLATFORM_MAC
            HFSPath = FPaths::Combine(HFSPath, HAPI_HFS_SUBFOLDER_MAC);
#elif PLATFORM_LINUX
            HFSPath = FPaths::Combine(HFSPath, HAPI_HFS_SUBFOLDER_LINUX);
#endif
        }

        auto LibPath = FString::Printf(TEXT("/%s"), *HFSPath, *LibName);
        if (FPaths::FileExists(LibPath))
        {
#if PLATFORM_WINDOWS
            TryGetHandle(HFSPath, LibName);
#elif PLATFORM_MAC || PLATFORM_LINUX
            TryGetHandle(HFSPath, LibPath);
#endif

            if (HAPIHandle)
            {
                if (bCustomPathFound)
                {
                    UE_LOG(LogHoudiniPlus, Log, TEXT("Loaded %s from custom path %s"), *LibName, *HFSPath);
                }
                else
                {
                    UE_LOG(LogHoudiniPlus, Log, TEXT("Loaded %s from HFS environment path %s"), *LibName, *HFSPath);
                }

                HAPIPath = HFSPath;
                return true;
            }
        }
    }

    FHAPIVersion Version;
    FString HoudiniLocation = HOUDINI_ENGINE_HFS_PATH;
    bool bWasLocatedInHoudini = TryLocateInHoudini(LibName, Version, HoudiniLocation);
    if (bWasLocatedInHoudini && HAPIHandle)
        return true;

    auto LibPath = FPaths::Combine(HoudiniLocation, LibName);
    if (FPaths::FileExists(LibPath))
    {
        if (TryGetHandle(HoudiniLocation, LibPath))
        {
            UE_LOG(LogHoudiniPlus, Log, TEXT("Loaded %s from expected installation %s"), *LibName, *LibPath);
            HAPIPath = LibPath;
            return true;
        }
    }

    HAPIPath = TEXT("");
    return false;
}

FORCEINLINE bool FHAPIHandle::GetHFSPathFromEnvironment(FString& Result) const
{
    TCHAR HFS_ENV_VARIABLE[PLATFORM_MAX_FILEPATH_LENGTH] = { 0 };

    FPlatformMisc::GetEnvironmentVariable(TEXT("HAPI_PATH"), HFS_ENV_VARIABLE, PLATFORM_MAX_FILEPATH_LENGTH);
    if (*HFS_ENV_VARIABLE)
    {
        Result = &HFS_ENV_VARIABLE[0];
        return true;
    }

    FPlatformMisc::GetEnvironmentVariable(TEXT("HFS"), HFS_ENV_VARIABLE, PLATFORM_MAX_FILEPATH_LENGTH);
    if (*HFS_ENV_VARIABLE)
    {
        Result = &HFS_ENV_VARIABLE[0];
        return true;
    }

    return false;
}

FORCEINLINE bool FHAPIHandle::TryGetCustomHFSPath(const FString& LibName, FString& Result) const
{
    bool bFound = false;
    const auto Settings = GetDefault<UHoudiniPlusSettings>();
    if (Settings && Settings->bUseCustomHoudiniLocation)
    {
        auto CustomHFSPath = Settings->CustomHoudiniLocation.Path;
        if (!CustomHFSPath.IsEmpty())
        {
            if (FPaths::IsRelative(CustomHFSPath))
                CustomHFSPath = FPaths::ConvertRelativePathToFull(CustomHFSPath);

            CustomHFSPath = FPaths::Combine(CustomHFSPath, LibName);
            if (FPaths::FileExists(CustomHFSPath))
            {
                Result = CustomHFSPath;
                return true;
            }
        }
    }

    return false;
}

const FORCEINLINE FString& FHAPIHandle::GetLibHAPIName() const
{
    static const FString LibHAPIName =
#if PLATFORM_WINDOWS
    HAPI_LIB_OBJECT_WINDOWS;
#elif PLATFORM_MAC
    HAPI_LIB_OBJECT_MAC;
#elif PLATFORM_LINUX
    HAPI_LIB_OBJECT_LINUX;
#else
    TEXT("");
#endif

    return LibHAPIName;
}

FORCEINLINE bool FHAPIHandle::TryLocateInHoudini(const FString& LibName, FHAPIVersion& Version, FString& HoudiniPath)
{
    FString HFSPath;
    FString LibPath;

#if PLATFORM_WINDOWS
    HFSPath = FPaths::Combine(HoudiniPath, HAPI_HFS_SUBFOLDER_WINDOWS);
    LibPath = FPaths::Combine(HFSPath, LibName);

    if (FPaths::FileExists(LibPath))
    {
        if (TryGetHandle(HFSPath, LibName))
        {
            UE_LOG(LogHoudiniPlus, Log, TEXT("Loaded %s from Plugin defind HFS path %s"), *LibName, *HFSPath);
            HAPIPath = HFSPath;
            return true;
        }
    }

    HAPIHandle = TryLocateInRegistry(TEXT("Houdini Engine"), Version, HAPIPath);
    if (HAPIHandle)
        return true;

    HAPIHandle = TryLocateInRegistry(TEXT("Houdini"), Version, HAPIPath);
    if (HAPIHandle)
        return true;

    HoudiniPath = FPaths::Combine(TEXT(""), Version.ToString(), HAPI_HFS_SUBFOLDER_WINDOWS);
    return true;
#else
#if PLATFORM_MAC
    HoudiniPath = FString::Printf(TEXT("/Applications/Houdini/Houdini%s/Frameworks/Houdini.framework/Versions/%s/Libraries"), *Version.ToString(), *Version.ToString());
#elif PLATFORM_LINUX
    HoudiniPath = FString::Printf(TEXT("/opt/hfs%s/%s"), *Version.ToString(), HAPI_HFS_SUBFOLDER_LINUX);
#endif
    return true;
#endif
}

FORCEINLINE bool FHAPIHandle::TryGetHandle(const FString& Path, const FString& Name)
{
    FPlatformProcess::PushDllDirectory(*Path);
    HAPIHandle = FPlatformProcess::GetDllHandle(*Name);
    FPlatformProcess::PopDllDirectory(*Path);

    return HAPIHandle != nullptr;
}

#if PLATFORM_WINDOWS
FORCEINLINE void* FHAPIHandle::TryLocateInRegistry(const FString& InstallationType, FHAPIVersion& Version, FString& HAPIPath)
{
    auto HoudiniRegistryLocation = FString::Printf(TEXT("Software\\Side Effects Software\\%s %s"), *InstallationType, *Version.ToString());
    
    FString HoudiniInstallationPath;
    if (FWindowsPlatformMisc::QueryRegKey(HKEY_LOCAL_MACHINE, *HoudiniRegistryLocation, TEXT("InstallPath"), HoudiniInstallationPath))
    {
        HoudiniInstallationPath = FPaths::Combine(HoudiniInstallationPath, HAPI_HFS_SUBFOLDER_WINDOWS);
        auto LibPath = FPaths::Combine(HoudiniInstallationPath, HAPI_LIB_OBJECT_WINDOWS);

        if (FPaths::FileExists(LibPath))
        {
            FPlatformProcess::PushDllDirectory(*HoudiniInstallationPath);
            void* HAPIHandle = FPlatformProcess::GetDllHandle(HAPI_LIB_OBJECT_WINDOWS);
            FPlatformProcess::PopDllDirectory(*HoudiniInstallationPath);

            if (HAPIHandle)
            {
                UE_LOG(LogHoudiniPlus, Log, TEXT("Loaded %s from Registry path %s"), HAPI_LIB_OBJECT_WINDOWS, *HoudiniInstallationPath);

                HAPIPath = HoudiniInstallationPath;
                return HAPIHandle;
            }
        }
    }

    return nullptr;
}
#endif