
#pragma once
#include <coretypes/procedure.h>
#include <coretypes/coretype.h>
#include <coretypes/intfs.h>
#include <type_traits>
#include <utility>

BEGIN_NAMESPACE_CQDAQ

template <typename F>
class CustomProcedureImpl : public ImplementationOf<IProcedure, ICoreType>
{
public:
    explicit CustomProcedureImpl(F proc);
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;
    ErrCode INTERFACE_FUNC dispatch(IBaseObject* params) override;

private:
    F proc;
};

template <typename F>
CustomProcedureImpl<F>::CustomProcedureImpl(F proc)
    : proc(std::move(proc))
{
}

template <typename F>
ErrCode CustomProcedureImpl<F>::getCoreType(CoreType* coreType)
{
    if (!coreType)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *coreType = ctProc;
    return CQDAQ_SUCCESS;
}

template <typename F>
ErrCode CustomProcedureImpl<F>::toString(CharPtr* str)
{
    if (str == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    return daqDuplicateCharPtr("Procedure", str);
}

template <typename F>
ErrCode CustomProcedureImpl<F>::dispatch(IBaseObject* params)
{
    if constexpr (!std::is_same_v<F, std::nullptr_t>)
    {
        if (!this->proc)
        {
            return CQDAQ_ERR_NOTASSIGNED;
        }

        try
        {
            return this->proc(params);
        }
        catch (const DaqException& e)
        {
            return errorFromException(e);
        }
        catch (...)
        {
            return CQDAQ_ERR_CALLFAILED;
        }
    }
    else
    {
        return CQDAQ_ERR_NOTASSIGNED;
    }
}

END_NAMESPACE_CQDAQ
