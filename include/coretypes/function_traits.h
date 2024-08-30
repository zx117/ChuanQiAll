
#pragma once
#include <coretypes/common.h>
#include <coretypes/arguments.h>
#include <type_traits>

BEGIN_NAMESPACE_CQDAQ

template <typename T>
struct FunctionTraits : public FunctionTraits<decltype(&T::operator())>
{
};

// For free functions
template <typename TReturnType, typename... TArgs>
struct FunctionTraits<TReturnType(TArgs...)>
{
    using ResultType = TReturnType;
    using ArgTuple = Args<TArgs...>;
    static constexpr auto Arity = sizeof...(TArgs);
};

// For lambdas
template <typename TClassType, typename TReturnType, typename... TArgs>
struct FunctionTraits<TReturnType (TClassType::*)(TArgs...) const>
{
    using ResultType = TReturnType;
    using ArgTuple = Args<TArgs...>;
    static constexpr auto Arity = sizeof...(TArgs);
};

template <typename TClassType, typename TReturnType, typename... TArgs>
struct FunctionTraits<TReturnType (TClassType::*)(TArgs...)>
{
    using ResultType = TReturnType;
    using ArgTuple = Args<TArgs...>;
    static constexpr auto Arity = sizeof...(TArgs);
};

// Enable / disable method depending on if it returns ErrCode or not
template <typename TFunctor, bool IsTrue>
using ReturnsErrorCode = typename std::enable_if<std::is_same<typename FunctionTraits<TFunctor>::ResultType, ErrCode>::value == IsTrue>;

END_NAMESPACE_CQDAQ
