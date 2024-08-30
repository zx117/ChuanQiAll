
#pragma once
#include <coretypes/boolean.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ObjectPtr<IBoolean> Boolean(const Bool value)
{
    ObjectPtr<IBoolean> obj(Boolean_Create(value));
    return obj;
}

using BoolPtr = ObjectPtr<IBoolean>;
using BooleanPtr = ObjectPtr<IBoolean>;

END_NAMESPACE_CQDAQ
