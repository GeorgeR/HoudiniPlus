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

/** Names of HAPI libraries on different platforms. **/
#define HAPI_LIB_OBJECT_WINDOWS         TEXT( "libHAPIL.dll" )
#define HAPI_LIB_OBJECT_MAC             TEXT( "libHAPIL.dylib" )
#define HAPI_LIB_OBJECT_LINUX           TEXT( "libHAPIL.so" )

/** HFS subfolder containing HAPI lib. **/
#define HAPI_HFS_SUBFOLDER_WINDOWS      TEXT( "bin" )
#define HAPI_HFS_SUBFOLDER_MAC          TEXT( "dsolib" )
#define HAPI_HFS_SUBFOLDER_LINUX        TEXT( "dsolib" )