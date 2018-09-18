#pragma once

#include "CoreMinimal.h"

struct HAPPY_API FHAPIVersion
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