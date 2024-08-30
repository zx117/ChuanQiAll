
#pragma once
#include <coretypes/errorinfo.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ObjectPtr<IErrorInfo> ErrorInfo()
{
    ObjectPtr<IErrorInfo> obj(ErrorInfo_Create());
    return obj;
}

using ErrorInfoPtr = ObjectPtr<IErrorInfo>;

END_NAMESPACE_CQDAQ
