
#pragma once
#include <coretypes/integer.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ObjectPtr<IInteger> Integer(const Int value)
{
    ObjectPtr<IInteger> obj(Integer_Create(value));
    return obj;
}

using IntPtr = ObjectPtr<IInteger>;
using IntegerPtr = ObjectPtr<IInteger>;

END_NAMESPACE_CQDAQ
