
#pragma once
#include <coretypes/function_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline FunctionPtr CustomFunction(FuncCall func)
{
    return FunctionPtr(Function_Create(func));
}

END_NAMESPACE_CQDAQ
