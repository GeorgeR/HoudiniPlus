#pragma once

#include "ModuleInterface.h"
#include "HAPI/HAPI_Common.h"

class IHoudiniPlusModule
    : public IModuleInterface
{
public:
    virtual bool CheckHapiVersionMismatch() const = 0;

    virtual HAPI_Result GetHapiState() const = 0;
    virtual void SetHapiState(HAPI_Result Result) = 0;

    virtual const HAPI_Session* GetSession() = 0;
};