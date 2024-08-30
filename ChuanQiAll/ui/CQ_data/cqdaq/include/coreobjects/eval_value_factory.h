#pragma once
#include <coreobjects/eval_value_ptr.h>
#include <coretypes/listobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

inline EvalValuePtr EvalValue(const StringPtr& eval)
{
    EvalValuePtr obj(EvalValue_Create(eval));
    checkErrorInfo(obj->getParseErrorCode());
    return obj;
}

inline EvalValuePtr EvalValueFunc(const StringPtr& eval, const FunctionPtr& func)
{
    EvalValuePtr obj(EvalValueFunc_Create(eval, func));
    checkErrorInfo(obj->getParseErrorCode());
    return obj;
}

template <typename... TArgs>
EvalValuePtr EvalValue(StringPtr eval, TArgs&&... args)
{
    EvalValuePtr obj(EvalValueArgs_Create(eval, List<IBaseObject>(std::forward<decltype(args)>(args)...)));
    checkErrorInfo(obj->getParseErrorCode());
    return obj;
}

inline EvalValuePtr Bind(const std::string& propertyName, const PropertyObjectPtr& propObj)
{
    return EvalValue(std::string("{0}.$") + propertyName, propObj);
}

inline EvalValuePtr operator""_eval(const char* eval, std::size_t /*size*/)
{
    return EvalValue(eval);
}

END_NAMESPACE_CQDAQ
