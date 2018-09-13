#pragma once

#include "CoreMinimal.h"
#include "Editor.h"
#include "ISettingsModule.h"

#include <vector>
#include <string>
#include <stdint.h>

#include "HAPI/HAPI.h"
#include "HAPI/HAPI_Version.h"
#include "HAPI/HAPI_Common.h"

DECLARE_LOG_CATEGORY_EXTERN(LogHoudiniPlus, Log, All);

#ifndef HOUDINI_ENGINE_HFS_PATH_DEFINE
#define HOUDINI_ENGINE_HFS_PATH ""
#else
#define HOUDINI_ENGINE_STRINGIFY_HELPER(X) #X
#define HOUDINI_ENGINE_STRINGIFY(X) HOUDINI_ENGINE_STRINGIFY_HELPER(X)
#define HOUDINI_ENGINE_HFS_PATH HOUDINI_ENGINE_STRINGIFY(HOUDINI_ENGINE_HFS_PATH_DEFINE)
#endif