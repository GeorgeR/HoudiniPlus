#include "HappyPrivatePCH.h"

#include "Version.h"

FHAPIVersion::FHAPIVersion()
{
    Major = HAPI_VERSION_HOUDINI_MAJOR;
    Minor = HAPI_VERSION_HOUDINI_MINOR;
    Build = HAPI_VERSION_HOUDINI_BUILD;

    if (HAPI_VERSION_HOUDINI_PATCH > 0)
        Patch = HAPI_VERSION_HOUDINI_PATCH;
}

const FString& FHAPIVersion::ToString()
{
    if (!Str.IsEmpty())
        return Str;

    Str = Patch >= 0
        ? FString::Printf(TEXT("%d.%d.%d.%d"), Major, Minor, Build, Patch)
        : FString::Printf(TEXT("%d.%d.%d"), Major, Minor, Build);

    return Str;
}