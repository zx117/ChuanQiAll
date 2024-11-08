#pragma once

#include <common.h>
#include <cqdaq/function_block_impl.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_SAVE_MODULE

DECLARE_CQDAQ_INTERFACE(ICommunication, IBaseObject)
{
public:
    virtual void startSaving() = 0;
    virtual void pauseSaving() = 0;
    virtual void continueSaving() = 0;
    virtual void stopSaving() = 0;

};

END_NAMESPACE_SAVE_MODULE
