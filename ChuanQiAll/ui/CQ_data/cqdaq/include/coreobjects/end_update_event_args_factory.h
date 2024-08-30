#pragma once
#include <coretypes/common.h>
#include <coreobjects/end_update_event_args_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline EndUpdateEventArgsPtr EndUpdateEventArgs(const ListPtr<IString>& properties, bool parentUpdating)
{
    return EndUpdateEventArgsPtr(EndUpdateEventArgs_Create(properties, parentUpdating));
}

END_NAMESPACE_CQDAQ
