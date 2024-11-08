#pragma once

#include <common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(ICommunication, IBaseObject)
{
public:
    virtual void startSaving() = 0;
    virtual void pauseSaving() = 0;
    virtual void continueSaving() = 0;
    virtual void stopSaving() = 0;

};

END_NAMESPACE_CQDAQ
