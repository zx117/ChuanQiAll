
#pragma once
#include <coretypes/common.h>
#include <coretypes/errors.h>
#include <coretypes/factoryselectors.h>
#include <coretypes/macro_utils.h>
#include <coretypes/exceptions.h>
#include <new>

#define EXTRACT_ITEM_1(X1, ...) X1
#define EXTRACT_ITEM_2(X1, X2, ...) X2
#define EXTRACT_ITEM_3(X1, X2, X3, ...) X3
#define EXTRACT_ITEM_4(X1, X2, X3, X4, ...) X4
#define EXTRACT_ITEM_5(X1, X2, X3, X4, X5, ...) X5
#define EXTRACT_ITEM_6(X1, X2, X3, X4, X5, X6, ...) X6
#define EXTRACT_ITEM_7(X1, X2, X3, X4, X5, X6, X7, ...) X7

#define FACTORY_TYPE_NAME_int8_t int8
#define FACTORY_TYPE_NAME_uint8_t byte
#define FACTORY_TYPE_NAME_int16_t int16
#define FACTORY_TYPE_NAME_int32_t int32
#define FACTORY_TYPE_NAME_int64_t int64
#define FACTORY_TYPE_NAME_float float
#define FACTORY_TYPE_NAME_double double
#define FACTORY_TYPE_NAME_RangeType64 RangeType
#define FACTORY_TYPE_NAME_ComplexFloat32 ComplexFloat32
#define FACTORY_TYPE_NAME_ComplexFloat64 ComplexFloat64
#define FACTORY_TYPE_NAME_BinarySample Binary
#define FACTORY_TYPE_NAME_void
#define FACTORY_TYPE_NAME_RawPtr Raw
#define FACTORY_TYPE_NAME_Unscaled unscaled

#define FACTORY_TYPE_NAME(Type) FACTORY_TYPE_NAME_##Type

#define CQDAQ_IF(cond) CQDAQ__CONCATENATE(CQDAQ__IF_, cond)
#define CQDAQ__IF_0(t, f) f
#define CQDAQ__IF_1(t, f) t

#define CQDAQ_EQ_0(x) CQDAQ__CONCATENATE(CQDAQ__RES_EQ_0_, x)
#define CQDAQ__RES_EQ_0_0 1
#define CQDAQ__RES_EQ_0_1 0
#define CQDAQ__RES_EQ_0_2 0

#define CQDAQ_EQ_1(x) CQDAQ__CONCATENATE(CQDAQ__RES_EQ_1_, x)
#define CQDAQ__RES_EQ_1_0 0
#define CQDAQ__RES_EQ_1_1 1
#define CQDAQ__RES_EQ_1_2 0

#define CQDAQ_EQ_2(x) CQDAQ__CONCATENATE(CQDAQ__RES_EQ_2_, x)
#define CQDAQ__RES_EQ_2_0 0
#define CQDAQ__RES_EQ_2_1 0
#define CQDAQ__RES_EQ_2_2 1

#define CQDAQ_SAMPLE_TYPES(...) __VA_ARGS__
#define CQDAQ_FACTORY_PARAMS(...) __VA_ARGS__
#define CQDAQ_FACTORY_INFO(Accessibility, ImplementationObject, Interface) (Accessibility, ImplementationObject, Interface)
#define CQDAQ_FACTORY_INFO_IMPL(Accessibility, ImplementationObject, FactoryName, Interface) (Accessibility, ImplementationObject, Interface, FactoryName)
#define CQDAQ_FUNC_NO_PARAMS

#define CQDAQ__CALL_MACRO(Macro, ...) CQDAQ__EXPAND(Macro(__VA_ARGS__))

#define CQDAQ__TEMPLATED_CREATE_FUNC_(Name, Type) create##Name##_##Type
#define CQDAQ__TEMPLATED_CREATE_FUNC(Name, Type) CQDAQ__TEMPLATED_CREATE_FUNC_(Name, Type)

#define CQDAQ_GET_FUNC_ACCESS(Params) CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params)
#define CQDAQ_GET_FUNC_INTF(Params) CQDAQ__CALL_MACRO(EXTRACT_ITEM_3, CQDAQ__STRIP_PAR Params)
#define CQDAQ_GET_FUNC_IMPLOBJ(Params) CQDAQ__CALL_MACRO(EXTRACT_ITEM_2, CQDAQ__STRIP_PAR Params)
#define CQDAQ_GET_FUNC_FACTORY(Params) CQDAQ__CALL_MACRO(EXTRACT_ITEM_4, CQDAQ__STRIP_PAR Params)

#define CQDAQ__GET_TYPE_ITEM(Desc, Item) CQDAQ__CALL_MACRO(CQDAQ__CONCATENATE(EXTRACT_ITEM_, Item), CQDAQ__STRIP_PAR Desc)

#define CQDAQ__NO_ARG      0
#define CQDAQ__ARG_T       1
#define CQDAQ__ARG_U       2

#define CQDAQ__IS_TEMPLATED_TYPE    1
#define CQDAQ__IS_TYPE              1
#define CQDAQ__IS_TEMPLATE          0

#define CQDAQ__TYPE_FLAGS_NONE      0
#define CQDAQ__TYPE_FLAGS_PTR       1
#define CQDAQ__TYPE_FLAGS_SMARTPTR  2

#define CQDAQ__TEMPLATED_TYPE_TWO_ARGS(Name, Arg1, Arg2, Flags)  (CQDAQ__IS_TEMPLATED_TYPE, Name, Arg1, Arg2, Flags)
#define CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, Arg, Flags)          (CQDAQ__IS_TEMPLATED_TYPE, Name, Arg, CQDAQ__NO_ARG, Flags)
#define CQDAQ__TEMPLATE(Arg, Flags)                              (CQDAQ__IS_TEMPLATE, , Arg, CQDAQ__NO_ARG, Flags)
#define CQDAQ__TYPE(Name, Flags)                                 (CQDAQ__IS_TYPE, Name, CQDAQ__NO_ARG, CQDAQ__NO_ARG, Flags)

#define CQDAQ_TYPE(Name)                                  CQDAQ__TYPE(Name, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_SMARTPTR(Name)                              CQDAQ__TYPE(Name, CQDAQ__TYPE_FLAGS_SMARTPTR)
#define CQDAQ_TEMPLATED_TYPE_T(Name)                      CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_TEMPLATED_TYPE_U(Name)                      CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_TEMPLATED_TYPE_T_U(Name)                    CQDAQ__TEMPLATED_TYPE_TWO_ARGS(Name, CQDAQ__ARG_T, CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_TEMPLATED_TYPE_U_T(Name)                    CQDAQ__TEMPLATED_TYPE_TWO_ARGS(Name, CQDAQ__ARG_U, CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_TEMPLATE_T                                  CQDAQ__TEMPLATE(CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_NONE)
#define CQDAQ_TEMPLATE_U                                  CQDAQ__TEMPLATE(CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_NONE)

#define CQDAQ_TEMPLATED_SMARTPTR_T(Name)                  CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_SMARTPTR)

#define CQDAQ_PTR(Name)                                   CQDAQ__TYPE(Name, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATED_PTR_T(Name)                       CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATED_PTR_U(Name)                       CQDAQ__TEMPLATED_TYPE_ONE_ARG(Name, CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATED_PTR_T_U(Name)                     CQDAQ__TEMPLATED_TYPE_TWO_ARGS(Name, CQDAQ__ARG_T, CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATED_PTR_U_T(Name)                     CQDAQ__TEMPLATED_TYPE_TWO_ARGS(Name, CQDAQ__ARG_U, CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATE_PTR_T                              CQDAQ__TEMPLATE(CQDAQ__ARG_T, CQDAQ__TYPE_FLAGS_PTR)
#define CQDAQ_TEMPLATE_PTR_U                              CQDAQ__TEMPLATE(CQDAQ__ARG_U, CQDAQ__TYPE_FLAGS_PTR)

#define CQDAQ__GET_TYPE_TYPE(TypeDesc)  CQDAQ__GET_TYPE_ITEM(TypeDesc, 1)
#define CQDAQ__GET_TYPE_NAME(TypeDesc)  CQDAQ__GET_TYPE_ITEM(TypeDesc, 2)
#define CQDAQ__GET_TYPE_ARG_1(TypeDesc) CQDAQ__GET_TYPE_ITEM(TypeDesc, 3)
#define CQDAQ__GET_TYPE_ARG_2(TypeDesc) CQDAQ__GET_TYPE_ITEM(TypeDesc, 4)
#define CQDAQ__GET_TYPE_FLAGS(TypeDesc) CQDAQ__GET_TYPE_ITEM(TypeDesc, 5)


#define CQDAQ__BUILD_TEMPLATED_TYPE_HAS_ONLY_FIRST_PARAM(TypeDesc, TemplateParam1, TemplateParam2)       \
    CQDAQ__GET_TYPE_NAME(TypeDesc) CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(<TemplateParam1>, <TemplateParam2>)

#define CQDAQ__BUILD_TEMPLATED_TYPE_HAS_FIRST_AND_SECOND_PARAM(TypeDesc, TemplateParam1, TemplateParam2) \
    CQDAQ__GET_TYPE_NAME(TypeDesc) CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(<TemplateParam1 CQDAQ__COMMA TemplateParam2>, <TemplateParam2 CQDAQ__COMMA TemplateParam1>)

#define CQDAQ__BUILD_TEMPLATED_TYPE_HAS_FIRST_PARAM(TypeDesc, TemplateParam1, TemplateParam2)            \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_2(TypeDesc)))(                                                   \
        CQDAQ__BUILD_TEMPLATED_TYPE_HAS_ONLY_FIRST_PARAM(TypeDesc, TemplateParam1, TemplateParam2),      \
        CQDAQ__BUILD_TEMPLATED_TYPE_HAS_FIRST_AND_SECOND_PARAM(TypeDesc, TemplateParam1, TemplateParam2) \
    )

#define CQDAQ__OUTPUT_IF_SMARTPTR(TypeDesc, Str) CQDAQ_IF(CQDAQ_EQ_2(CQDAQ__GET_TYPE_FLAGS(TypeDesc))) (Str,)
#define CQDAQ__OUTPUT_IF_PTR(TypeDesc, Str) CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_FLAGS(TypeDesc))) (Str,)

#define CQDAQ__BUILD_TEMPLATED_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                            \
    CQDAQ__OUTPUT_IF_SMARTPTR(TypeDesc, const)                                                           \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        CQDAQ__GET_TYPE_NAME(TypeDesc),                                                                  \
        CQDAQ__BUILD_TEMPLATED_TYPE_HAS_FIRST_PARAM(TypeDesc, TemplateParam1, TemplateParam2)            \
    ) CQDAQ__OUTPUT_IF_SMARTPTR(TypeDesc, &) CQDAQ__OUTPUT_IF_PTR(TypeDesc, *)

#define CQDAQ__BUILD_RAW_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                                  \
    CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc))) (TemplateParam1, TemplateParam2)

#define CQDAQ__BUILD_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                                      \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_TYPE(TypeDesc)))(                                                      \
        CQDAQ__BUILD_RAW_TYPE(TypeDesc, TemplateParam1, TemplateParam2),                                 \
        CQDAQ__BUILD_TEMPLATED_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                            \
    )

#define CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                       \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        ,                                                                                             \
        CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_INTERNAL(TypeDesc, TemplateParam1, TemplateParam2)              \
    )

#define CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_INTERNAL(TypeDesc, TemplateParam1, TemplateParam2)              \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_2(TypeDesc)))(                                                     \
        CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_SINGLE_PARAM(TypeDesc, TemplateParam1, TemplateParam2),         \
        CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_DUAL_PARAM(TypeDesc, TemplateParam1, TemplateParam2)            \
    )

#define CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_SINGLE_PARAM(TypeDesc, TemplateParam1, TemplateParam2)          \
    CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        template <typename TemplateParam1>,                                                                \
        template <typename TemplateParam2>                                                                 \
    )

#define CQDAQ__OUTPUT_TEMPLATE_FROM_TYPE_DUAL_PARAM(TypeDesc, TemplateParam1, TemplateParam2)            \
    CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        template <typename TemplateParam1 CQDAQ__COMMA typename TemplateParam2>,                         \
        template <typename TemplateParam2 CQDAQ__COMMA typename TemplateParam1>                          \
    )

#define CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE(TypeDesc, TemplateParam1, TemplateParam2)                \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        ,                                                                                                  \
        CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_INTERNAL(TypeDesc, TemplateParam1, TemplateParam2)       \
    )

#define CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_INTERNAL(TypeDesc, TemplateParam1, TemplateParam2)       \
    CQDAQ_IF(CQDAQ_EQ_0(CQDAQ__GET_TYPE_ARG_2(TypeDesc)))(                                                     \
        CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_SINGLE_PARAM(TypeDesc, TemplateParam1, TemplateParam2),  \
        CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_DUAL_PARAM(TypeDesc, TemplateParam1, TemplateParam2)     \
    )

#define CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_SINGLE_PARAM(TypeDesc, TemplateParam1, TemplateParam2)   \
    CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        <TemplateParam1>,                                                                                  \
        <TemplateParam2>                                                                                   \
    )

#define CQDAQ__OUTPUT_TEMPLATE_PARAMS_FROM_TYPE_DUAL_PARAM(TypeDesc, TemplateParam1, TemplateParam2)     \
    CQDAQ_IF(CQDAQ_EQ_1(CQDAQ__GET_TYPE_ARG_1(TypeDesc)))(                                                     \
        <TemplateParam1 CQDAQ__COMMA TemplateParam2>,                                                    \
        <TemplateParam2 CQDAQ__COMMA TemplateParam1>                                                     \
    )

#define CQDAQ__BUILD_ARGS_SINGLE(TemplatedType, Unused2, Unused3, Type, Name)          CQDAQ__BUILD_TYPE(Type, TemplatedType,  Unused), Name
#define CQDAQ__BUILD_ARGS_SINGLE_2(TemplatedType1, TemplatedType2, Param3, Type, Name) (CQDAQ__BUILD_TYPE(Type, TemplatedType1, TemplatedType2)), Name

#define CQDAQ__BUILD_ARGS(TemplatedType, ...)                    _FOR_EACH_2P(CQDAQ__BUILD_ARGS_SINGLE,   CQDAQ__COMMA_DELIM,  TemplatedType,  unused2,         unused3, __VA_ARGS__)
#define CQDAQ__BUILD_ARGS_2(TemplatedType1, TemplatedType2, ...) _FOR_EACH_2P(CQDAQ__BUILD_ARGS_SINGLE_2, CQDAQ__COMMA_DELIM , TemplatedType1, TemplatedType2, _unused3, __VA_ARGS__)

#define CQDAQ__CALL_TEMPLATED_CREATE_FUNCTION(Params, FuncParams, Type)                                                        \
    if constexpr (std::is_same_v<T, Type>)                                                                                       \
    {                                                                                                                            \
        res = CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params), FACTORY_TYPE_NAME(Type))(                              \
            &obj CQDAQ_FACTORY_NAMES_EX(CQDAQ__STRIP_PAR FuncParams));                                                            \
    } else

#define CQDAQ__CALL_TEMPLATED_2_CREATE_FUNCTION(Params, FuncParams, Unused, Type1, Type2)                                      \
    if constexpr (std::is_same_v<T, Type1> && std::is_same_v<U, Type2>)                                                          \
    {                                                                                                                            \
        res = CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                        \
                                          CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2)))      \
              (&obj CQDAQ_FACTORY_NAMES_EX(CQDAQ__STRIP_PAR FuncParams));                                                         \
    } else

#define CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_ARG(EXPIMP, IntfName, CreateFunc, TemplateType, ...) \
    extern "C" daq::ErrCode EXPIMP CreateFunc(IntfName** obj CQDAQ__CALL_MACRO(CQDAQ_FACTORY_TYPES_AND_NAMES, CQDAQ__BUILD_ARGS(TemplateType, __VA_ARGS__)));

#define CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_2_ARG(EXPIMP, IntfName, CreateFunc, Type1, Type2, ...) \
    extern "C" daq::ErrCode EXPIMP CreateFunc(IntfName** obj CQDAQ__CALL_MACRO(CQDAQ_FACTORY_TYPES_AND_NAMES_PAR, CQDAQ__BUILD_ARGS_2(Type1, Type2, __VA_ARGS__)));

#define CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE(Params, FuncParams, Type)                                \
    CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_ARG(CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                         \
                             CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type, Unused),                                        \
                             CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params), FACTORY_TYPE_NAME(Type)),               \
                             Type,                                                                                               \
                             CQDAQ__STRIP_PAR FuncParams)

#define CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2)              \
    CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_2_ARG(CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                       \
                             CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2),                                        \
                                              CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                        \
                                              CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))), \
                             Type1,                                                                                              \
                             Type2,                                                                                              \
                             CQDAQ__STRIP_PAR FuncParams)


//////////////////////////////

#define CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T(Info, Types, FuncParams)                                         \
    FOR_EACH_1P(CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE, Info, (FuncParams), Types)                      \
                                                                                                                            \
    template <typename T>                                                                                                   \
    CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U) * CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Info),                               \
      _Create(CQDAQ__CALL_MACRO(CQDAQ_FACTORY_CM_TYPES_AND_NAMES, CQDAQ__BUILD_ARGS(T, FuncParams))))                                \
    {                                                                                                                       \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U) * obj;                                                                 \
        daq::ErrCode res = CQDAQ_ERR_NOTIMPLEMENTED;                                                                            \
        FOR_EACH_1P(CQDAQ__CALL_TEMPLATED_CREATE_FUNCTION, Info, (FuncParams), Types)                                          \
            static_assert(daq::DependentFalse<T>::value, "Type not supported");                                              \
                                                                                                                            \
        daq::checkErrorInfo(res);                                                                                            \
        return obj;                                                                                                         \
    }

#define CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U(Info, Types, FuncParams)                                       \
    FOR_EACH_2P(CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE, CQDAQ__NO_DELIM, Info, (FuncParams), , Types)    \
                                                                                                                                 \
    template <typename T, typename U>                                                                                            \
    CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U) * CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Info),                          \
      _Create(CQDAQ__CALL_MACRO(CQDAQ_FACTORY_CM_TYPES_AND_NAMES_PAR, CQDAQ__BUILD_ARGS_2(T, U, FuncParams))))                       \
    {                                                                                                                            \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U) * obj;                                                                 \
        daq::ErrCode res = CQDAQ_ERR_NOTIMPLEMENTED;                                                                           \
        FOR_EACH_2P(CQDAQ__CALL_TEMPLATED_2_CREATE_FUNCTION, CQDAQ__NO_DELIM , Info, (FuncParams), , Types)                       \
            static_assert(daq::DependentFalse<std::pair<T, U>>::value, "Type not supported");                                     \
                                                                                                                                 \
        daq::checkErrorInfo(res);                                                                                                 \
        return obj;                                                                                                              \
    }

#define CQDAQ_DEFINE_CLASS_FACTORY_HELPER_WITH_INTERFACE_AND_CREATEFUNC(ObjName, IntfName, CreateFunc, ...)                    \
    inline IntfName* ObjName##_Create(CQDAQ_FACTORY_CM_TYPES_AND_NAMES(__VA_ARGS__))                                                \
    {                                                                                                                            \
        IntfName* obj;                                                                                                           \
        daq::ErrCode res = CreateFunc(&obj CQDAQ_FACTORY_NAMES(__VA_ARGS__));                                                   \
        daq::checkErrorInfo(res);                                                                                                 \
        return obj;                                                                                                              \
    }

#define CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, ObjName, IntfName, CreateFunc, ...)                  \
    extern "C"                                                                                                                   \
    daq::ErrCode EXPIMP CreateFunc(IntfName** obj CQDAQ_FACTORY_TYPES_AND_NAMES(__VA_ARGS__));                                  \
                                                                                                                                 \
    CQDAQ_DEFINE_CLASS_FACTORY_HELPER_WITH_INTERFACE_AND_CREATEFUNC(ObjName, IntfName, CreateFunc, __VA_ARGS__)

#define CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(EXPIMP, ObjName, IntfName, ...)                                             \
    CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, ObjName, IntfName, create##ObjName, __VA_ARGS__)

#define CQDAQ_DECLARE_CLASS_FACTORY(EXPIMP, ObjName, ...)                                                                      \
    CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, ObjName, I##ObjName, create##ObjName, __VA_ARGS__)

#define CQDAQ_DECLARE_CREATE_FUNC(EXPIMP, IntfName, CreateFunc, ...)                                                           \
    extern "C"                                                                                                                   \
    daq::ErrCode EXPIMP CreateFunc(IntfName** obj CQDAQ_FACTORY_TYPES_AND_NAMES(__VA_ARGS__));

#define CQDAQ_DECLARE_CLASS_FACTORY_FUNC_WITH_INTERFACE(EXPIMP, Name, Interface, ...)                                          \
    CQDAQ_DECLARE_CREATE_FUNC(EXPIMP, Interface, create##Name, __VA_ARGS__)

//////////////
//// No params
//////////////

#define CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_2_ARG_ZERO(EXPIMP, IntfName, CreateFunc, Type1, Type2) \
    extern "C" daq::ErrCode EXPIMP CreateFunc(IntfName** obj);

#define CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE_ZERO(Params, FuncParams, Unused, Type1, Type2) \
    CQDAQ__DECLARE_CREATE_FUNC_TEMPLATE_2_ARG_ZERO(                                                                    \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                                  \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2),                                                     \
        CQDAQ__TEMPLATED_CREATE_FUNC(                                                                                  \
            CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                                            \
            CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))                             \
        ),                                                                                                               \
        Type1,                                                                                                           \
        Type2                                                                                                            \
    )

#define CQDAQ__CALL_TEMPLATED_2_CREATE_FUNCTION_ZERO(Params, FuncParams, Unused, Type1, Type2)                          \
    if constexpr (std::is_same_v<T, Type1> && std::is_same_v<U, Type2>)                                                   \
    {                                                                                                                     \
        res = CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                 \
                                        CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))) \
              (&obj CQDAQ_FACTORY_NAMES_EX());                                                                          \
    } else

#define CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO(Info, Types, FuncParams)                                    \
    FOR_EACH_2P(CQDAQ__DECLARE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE_ZERO, CQDAQ__NO_DELIM, Info, (FuncParams), , Types) \
                                                                                                                                   \
    template <typename T, typename U>                                                                                              \
    CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U)* CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Info), _Create())                  \
    {                                                                                                                              \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Info), T, U) * obj;                                                                   \
        daq::ErrCode res = CQDAQ_ERR_NOTIMPLEMENTED;                                                                             \
        FOR_EACH_2P(CQDAQ__CALL_TEMPLATED_2_CREATE_FUNCTION_ZERO, CQDAQ__NO_DELIM , Info, (), , Types)                              \
            static_assert(daq::DependentFalse<std::pair<T, U>>::value, "Type not supported");                                       \
                                                                                                                                   \
        daq::checkErrorInfo(res);                                                                                                   \
        return obj;                                                                                                                \
    }
