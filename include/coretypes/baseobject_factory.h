
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ObjectPtr<IBaseObject> BaseObject()
{
    ObjectPtr<IBaseObject> obj(BaseObject_Create());
    return obj;
}

using BaseObjectPtr = ObjectPtr<IBaseObject>;

END_NAMESPACE_CQDAQ
