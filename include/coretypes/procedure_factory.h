
#pragma once
#include <coretypes/procedure_impl.h>
#include <coretypes/procedure_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline ProcedurePtr CustomProcedure(ProcCall proc)
{
    ProcedurePtr obj(Procedure_Create(proc));
    return obj;
}

template <typename TFunctor>
ProcedurePtr Procedure(TFunctor value)
{
    ProcedurePtr obj(ProcedureWrapper_Create<TFunctor>(std::move(value)));
    return obj;
}

template <typename TFunctor>
ProcedurePtr Procedure(TFunctor* value)
{
    ProcedurePtr obj(ProcedureWrapper_Create<TFunctor>(value));
    return obj;
}

template <typename... Params>
ErrCode wrapHandler(ProcedurePtr handler, Params... params)
{
    try
    {
        (handler)(params...);
        return CQDAQ_SUCCESS;
    }
    catch (const DaqException& e)
    {
        return errorFromException(e);
    }
    catch (const std::exception& e)
    {
        return makeErrorInfo(CQDAQ_ERR_GENERALERROR, e.what(), nullptr);
    }
    catch (...)
    {
        return CQDAQ_ERR_GENERALERROR;
    }
}

END_NAMESPACE_CQDAQ
