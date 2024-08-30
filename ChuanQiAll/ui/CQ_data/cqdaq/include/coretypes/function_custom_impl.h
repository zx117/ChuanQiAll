
#pragma once
#include <coretypes/function.h>
#include <coretypes/coretype.h>
#include <coretypes/intfs.h>
#include <utility>

BEGIN_NAMESPACE_CQDAQ

template <typename TFunctor>
class CustomFunctionImpl : public ImplementationOf<IFunction, ICoreType>
{
public:
    CustomFunctionImpl(TFunctor value); // NOLINT(google-explicit-constructor)

    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;
    ErrCode INTERFACE_FUNC call(IBaseObject* params, IBaseObject** result) override;

    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

private:
    TFunctor functor;
};

template <typename TFunctor>
CustomFunctionImpl<TFunctor>::CustomFunctionImpl(TFunctor value)
    : functor(std::move(value))
{
}

template <typename TFunctor>
ErrCode CustomFunctionImpl<TFunctor>::call(IBaseObject* params, IBaseObject** result)
{
    if (!result)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (!functor)
        return CQDAQ_ERR_NOTASSIGNED;

    try
    {
        const auto err = functor(params, result);
        return err;
    }
    catch (const std::exception& e)
    {
        return errorFromException(e, nullptr,  CQDAQ_ERR_CALLFAILED);
    }
    catch (...)
    {
        return CQDAQ_ERR_CALLFAILED;
    }
}

template <typename TFunctor>
ErrCode CustomFunctionImpl<TFunctor>::getCoreType(CoreType* coreType)
{
    if (!coreType)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *coreType = ctFunc;
    return CQDAQ_SUCCESS;
}

template <typename TFunctor>
ErrCode CustomFunctionImpl<TFunctor>::toString(CharPtr* str)
{
    if (str == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    return daqDuplicateCharPtr("Function", str);
}

END_NAMESPACE_CQDAQ
