
#pragma once
#include <coretypes/event_args_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TArgs = IEventArgs>
EventArgsPtr<TArgs> EventArgs(Int id, const StringPtr& name)
{
    return EventArgsPtr<TArgs>(EventArgs_Create(id, name));
}

END_NAMESPACE_CQDAQ
