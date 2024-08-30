

#pragma once
#include <coretypes/float.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ObjectPtr<IFloat> Floating(const Float value)
{
    ObjectPtr<IFloat> obj(Float_Create(value));
    return obj;
}

using FloatPtr = ObjectPtr<IFloat>;

END_NAMESPACE_CQDAQ
