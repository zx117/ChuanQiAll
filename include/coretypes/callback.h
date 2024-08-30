#pragma once
#include <coretypes/common.h>
#include <coretypes/function_factory.h>
#include <coretypes/procedure_factory.h>

BEGIN_NAMESPACE_CQDAQ

namespace Detail
{
    template <typename TFunctor>
    inline auto Callback(TFunctor functor)
    {
        using Traits = FunctionTraits<TFunctor>;
        using ResultType = typename Traits::ResultType;

        if constexpr (std::is_same_v<ResultType, void>)
        {
            return Procedure(std::forward<decltype(functor)>(functor));
        }
        else if constexpr (std::is_same_v<ResultType, ErrCode>)
        {
            if constexpr (Traits::Arity == 1)
            {
                return Procedure(std::forward<decltype(functor)>(functor));
            }
            else
            {
                return Function(std::forward<decltype(functor)>(functor));
            }
        }
        else
        {
            return Function(std::move(functor));
        }
    }
}

template <typename TFunctor>
inline auto Callback(TFunctor functor)
{
    return Detail::Callback(std::forward<decltype(functor)>(functor));
}

template <typename TFunctor>
inline auto Callback(TFunctor* functor)
{
    return Detail::Callback<TFunctor>(std::forward<decltype(functor)>(functor));
}

END_NAMESPACE_CQDAQ
