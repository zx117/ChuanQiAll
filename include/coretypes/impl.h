
#pragma once
#include <coretypes/common.h>
#include <coretypes/errors.h>
#include <coretypes/ctutils.h>
#include <coretypes/intfs.h>
#include <coretypes/customalloc.h>
#include <coretypes/bb_exception.h>
#include <coretypes/factoryselectors.h>

BEGIN_NAMESPACE_CQDAQ

template <typename T>
T* addRefIfNotNull(T* obj)
{
    if (obj != nullptr)
        obj->addRef();
    return obj;
}

template <typename T>
void releaseRefIfNotNull(T* obj)
{
    if (obj != nullptr)
        obj->releaseRef();
}

template <typename T>
void setRef(T*& obj, T* newObj)
{
    releaseRefIfNotNull(obj);
    obj = addRefIfNotNull(newObj);
}

template <class Interface, class Impl, class... Params>
ErrCode createObjectForwarding(Interface** intf, Params... params)
{
    if (!intf)
        return CQDAQ_ERR_ARGUMENT_NULL;

    Impl* impl;
    try
    {
        impl = new Impl(std::forward<Params>(params)...);
    }
    catch (const DaqException& e)
    {
        setErrorInfoWithSource(nullptr, e.what());
        return e.getErrCode();
    }
    catch (const std::bad_alloc&)
    {
        return CQDAQ_ERR_NOMEMORY;
    }
    catch (const std::exception&)
    {
        return CQDAQ_ERR_GENERALERROR;
    }

    ErrCode errCode;
    if (impl->getRefAdded())
        errCode = impl->borrowInterface(Interface::Id, reinterpret_cast<void**>(intf));
    else
        errCode = impl->queryInterface(Interface::Id, reinterpret_cast<void**>(intf));

    if (CQDAQ_FAILED(errCode))
    {
        delete impl;
    }

    return errCode;
}

template <class Interface, class Impl, class... Params>
ErrCode createObject(Interface** intf, Params... params)
{
    if (!intf)
        return CQDAQ_ERR_ARGUMENT_NULL;

    Impl* impl;
    try
    {
        impl = new Impl(params...);
    }
    catch (const DaqException& e)
    {
        setErrorInfoWithSource(nullptr, e.what());
        return e.getErrCode();
    }
    catch (const std::bad_alloc&)
    {
        return CQDAQ_ERR_NOMEMORY;
    }
    catch (const std::exception& e)
    {
        return errorFromException(e);
    }

    ErrCode errCode;
    if (impl->getRefAdded())
        errCode = impl->borrowInterface(Interface::Id, reinterpret_cast<void**>(intf));
    else
        errCode = impl->queryInterface(Interface::Id, reinterpret_cast<void**>(intf));

    if (CQDAQ_FAILED(errCode))
    {
        delete impl;
    }
    return errCode;
}

template <typename TInterface>
struct ObjectCreator;

template <typename TInterface>
struct ObjectCreator
{
    static_assert(daq::DependentFalse<TInterface>::value, "Must specialize to enable custom factory");

    template <typename... TArgs>
    static ErrCode Create(TInterface** obj, TArgs... args) noexcept
    {
        return CQDAQ_ERR_NOTIMPLEMENTED;
    }
};

#define CQDAQ_DEFINE_CLASS_INTERFACE_FACTORY(EXPIMP, obj, intf)   \
    extern "C"                                                 \
    ErrCode EXPIMP create##obj(##intf** obj)                   \
    {                                                          \
        if (!obj)                                              \
            return CQDAQ_ERR_INVALIDPARAMETER;                    \
                                                               \
        ##intf* object;                                        \
        object = new (std::nothrow) obj##Impl();               \
        if (!object)                                           \
            return CQDAQ_ERR_NOMEMORY;                            \
                                                               \
        object->addRef();                                      \
                                                               \
        *obj = object;                                         \
                                                               \
        return CQDAQ_SUCCESS;                                     \
    }

template <class T, class ImplT>
static ErrCode GetSingletonObject(T** singletonStorage, T** resIntf)
{
    if (singletonStorage == nullptr || resIntf == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (*singletonStorage == nullptr)
    {
        *singletonStorage = new(std::nothrow) ImplT();
        if (*singletonStorage == nullptr)
            return CQDAQ_ERR_NOMEMORY;
        (*singletonStorage)->addRef();  // this prevents destruction of singleton object
    }

    *resIntf = *singletonStorage;
    (*resIntf)->addRef();

    return CQDAQ_SUCCESS;
}

template <class T>
struct GenericSingletonStruct
{
    T* intf;

    GenericSingletonStruct()
        : intf(nullptr)
    {
        // ensure proper creation order (Scott Meyers, Effective C++, 3rd edition, item 3)
        // heap must be created before singleton object, which means that heap will be destroyed after singleton object
        daqPrepareHeapAlloc();
    }

    ~GenericSingletonStruct()
    {
        releaseRefIfNotNull(intf);
    }

    void release()
    {
        releaseRefIfNotNull(intf);
        intf = nullptr;
    }
};

#define CQDAQ_CHECK_INTERFACE(intf, ptr)         \
    if (!ptr)                                 \
        return CQDAQ_ERR_INVALIDPARAMETER;       \
                                              \
    if (id == intf::Id)                       \
    {                                         \
        intf* obj = static_cast<intf*>(this); \
        obj->addRef();                        \
        *ptr = obj;                           \
        return CQDAQ_SUCCESS;                    \
    }

#if !defined(BUILDING_STATIC_LIBRARY)

#define CQDAQ_DEFINE_CLASS_SINGLETON_FACTORY(EXPIMP, obj)                                                   \
    static GenericSingletonStruct<I##obj> I##obj##Singleton;                                             \
                                                                                                         \
    extern "C"                                                                                           \
    ErrCode EXPIMP create##obj(I##obj** intf)                                                            \
    {                                                                                                    \
        return daq::GetSingletonObject<I##obj, obj##Impl>(&I##obj##Singleton.intf, intf); \
    }

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(EXPIMP, obj, intf, createFunc, ...)           \
    extern "C"                                                                                                  \
    daq::ErrCode EXPIMP createFunc(intf** objTmp CQDAQ_FACTORY_TYPES_AND_NAMES(__VA_ARGS__))                        \
    {                                                                                                           \
        return daq::createObject<intf, obj CQDAQ_FACTORY_TYPES(__VA_ARGS__)>(objTmp CQDAQ_FACTORY_NAMES(__VA_ARGS__)); \
    }

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_TEMPLATE(EXPIMP, obj, intf, createFunc, ...)  \
    template class obj;                                                                                         \
                                                                                                                \
    extern "C"                                                                                                  \
    daq::ErrCode EXPIMP createFunc(intf ** objTmp CQDAQ_FACTORY_TYPES_AND_NAMES(__VA_ARGS__))                       \
    {                                                                                                           \
        return daq::createObject<intf, obj CQDAQ_FACTORY_TYPES(__VA_ARGS__)>(objTmp CQDAQ_FACTORY_NAMES(__VA_ARGS__)); \
    }

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(EXPIMP, obj, intf, createFunc, ...)                         \
    template class obj;                                                                                                           \
                                                                                                                                  \
    extern "C"                                                                                                                    \
    daq::ErrCode EXPIMP createFunc(CQDAQ__STRIP_PAR intf ** objTmp CQDAQ_FACTORY_TYPES_AND_NAMES_PAR(__VA_ARGS__))                       \
    {                                                                                                                             \
        return daq::createObject<CQDAQ__STRIP_PAR intf, obj CQDAQ_FACTORY_TYPES_PAR(__VA_ARGS__)>(objTmp CQDAQ_FACTORY_NAMES(__VA_ARGS__)); \
    }

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, obj, intf, createFunc, ...)               \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(EXPIMP, obj##Impl, intf, createFunc, __VA_ARGS__)

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE(EXPIMP, obj, intf, ...) \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, obj, intf, create##obj, __VA_ARGS__)

#define CQDAQ_DEFINE_CLASS_FACTORY(EXPIMP, obj, ...) CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE(EXPIMP, obj, I##obj, __VA_ARGS__)

#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE(Params, FuncParams, Type) \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_TEMPLATE(                     \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                               \
        CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Params), Impl) <Type>,                          \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type, Unused),                             \
        CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params), FACTORY_TYPE_NAME(Type)),    \
        CQDAQ__BUILD_ARGS(Type, CQDAQ__STRIP_PAR FuncParams))

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T(Params, Types, FuncParams)                             \
    FOR_EACH_1P(CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE, Params, (FuncParams), Types)

#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2)    \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(                                               \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                                    \
        CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Params), Impl) <Type1 CQDAQ__COMMA Type2>,                              \
        (CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2)),                                                \
         CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                  \
                                   CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))), \
        CQDAQ__BUILD_ARGS_2(Type1, Type2, CQDAQ__STRIP_PAR FuncParams))


#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U(Params, Types, FuncParams)                          \
    FOR_EACH_2P(CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE, (), Params, (FuncParams), , Types)

//

#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_SINGLE(Params, FuncParams, Type) \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(                                   \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                    \
        CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Params), Impl) <Type>,                               \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type, Unused),                                  \
        CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_FACTORY(Params), FACTORY_TYPE_NAME(Type)),         \
        CQDAQ__BUILD_ARGS(Type, CQDAQ__STRIP_PAR FuncParams))

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T(Params, Types, FuncParams)                          \
    FOR_EACH_1P(CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_SINGLE, Params, (FuncParams), Types)

#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2) \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(                                                 \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                                      \
        CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Params), Impl) <Type1 CQDAQ__COMMA Type2>,                                \
        (CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2)),                                                  \
         CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_FACTORY(Params),                                                    \
                                   CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))),   \
        CQDAQ__BUILD_ARGS_2(Type1, Type2, CQDAQ__STRIP_PAR FuncParams))

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_U(Params, Types, FuncParams)                         \
    FOR_EACH_2P(CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_U_SINGLE, (), Params, (FuncParams), , Types)

//
// Custom
//

//
// T, U
//

#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(EXPIMP, intf, createFunc, ...) \
    extern "C"                                                                                              \
    daq::ErrCode EXPIMP createFunc(CQDAQ__STRIP_PAR intf ** objTmp CQDAQ_FACTORY_TYPES_AND_NAMES_PAR(__VA_ARGS__)) \
    {                                                                                                       \
        return daq::ObjectCreator<CQDAQ__STRIP_PAR intf>::Create(objTmp CQDAQ_FACTORY_NAMES(__VA_ARGS__));         \
    }

#define CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2) \
    CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(                                            \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                                        \
        (CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2)),                                                    \
         CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                      \
                                     CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2))),   \
        CQDAQ__BUILD_ARGS_2(Type1, Type2, CQDAQ__STRIP_PAR FuncParams))

#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U(Params, Types, FuncParams)                         \
    FOR_EACH_2P(CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE, (), Params, (FuncParams), , Types)

//
// T, U (No params)
//

#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO(Params, FuncParams, Unused, Type1, Type2)   \
    CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(                                            \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                                 \
        CQDAQ__CONCATENATE(CQDAQ_GET_FUNC_IMPLOBJ(Params), Impl) <Type1 CQDAQ__COMMA Type2>,                           \
        (CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type1, Type2)),                                             \
        CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params),                                                \
                                  CQDAQ_CONCATENATE_DELIM(_, FACTORY_TYPE_NAME(Type1), FACTORY_TYPE_NAME(Type2)) \
        )                                                                                                     \
    )

#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO(Params, Types, FuncParams)                   \
    FOR_EACH_2P(CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO, (), Params, (FuncParams), , Types)

//
// T
//

#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(EXPIMP, intf, createFunc, ...) \
    extern "C"                                                                                          \
    daq::ErrCode EXPIMP createFunc(intf** objTmp CQDAQ_FACTORY_TYPES_AND_NAMES(__VA_ARGS__))                \
    {                                                                                                   \
        return daq::ObjectCreator<intf>::Create(objTmp CQDAQ_FACTORY_NAMES(__VA_ARGS__));                   \
    }

#define CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE(Params, FuncParams, Type) \
    CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(                              \
        CQDAQ__CALL_MACRO(EXTRACT_ITEM_1, CQDAQ__STRIP_PAR Params),                                      \
        CQDAQ__BUILD_TYPE(CQDAQ_GET_FUNC_INTF(Params), Type, Unused),                                    \
        CQDAQ__TEMPLATED_CREATE_FUNC(CQDAQ_GET_FUNC_IMPLOBJ(Params), FACTORY_TYPE_NAME(Type)),           \
        CQDAQ__BUILD_ARGS(Type, CQDAQ__STRIP_PAR FuncParams)                                             \
    )

#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T(Params, Types, FuncParams)                    \
    FOR_EACH_1P(CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE, Params, (FuncParams), Types)

#else

#define CQDAQ_DEFINE_CLASS_SINGLETON_FACTORY(EXPIMP, obj)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(EXPIMP, obj, intf, createFunc, ...)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_TEMPLATE(EXPIMP, obj, intf, createFunc, ...)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(EXPIMP, obj, intf, createFunc, ...)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC(EXPIMP, obj, intf, createFunc, ...)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE(EXPIMP, obj, intf, ...)
#define CQDAQ_DEFINE_CLASS_FACTORY(EXPIMP, obj, ...)
#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE(Params, FuncParams, Type)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T(Params, Types, FuncParams)
#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U(Params, Types, FuncParams)
#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_SINGLE(Params, FuncParams, Type)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T(Params, Types, FuncParams)
#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_IMPL_T_U(Params, Types, FuncParams)
#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ_PAR(EXPIMP, intf, createFunc, ...)
#define CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_SINGLE(Params, FuncParams, Unused, Type1, Type2)
#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U(Params, Types, FuncParams)
#define CQDAQ__DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO(Params, FuncParams, Unused, Type1, Type2)
#define CQDAQ_DEFINE_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_U_ZERO(Params, Types, FuncParams)
#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_AND_CREATEFUNC_OBJ(EXPIMP, intf, createFunc, ...)
#define CQDAQ__DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T_SINGLE(Params, FuncParams, Type)
#define CQDAQ_DEFINE_CUSTOM_CLASS_FACTORY_WITH_INTERFACE_TEMPLATE_T(Params, Types, FuncParams)

#endif

END_NAMESPACE_CQDAQ
