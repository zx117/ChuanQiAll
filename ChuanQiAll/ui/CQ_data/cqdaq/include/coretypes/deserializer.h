
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>
#include <coretypes/serialized_object.h>
#include <coretypes/serialized_list.h>
#include <coretypes/updatable.h>
#include <coretypes/function.h>
#include <coretypes/procedure.h>

BEGIN_NAMESPACE_CQDAQ

typedef ErrCode (*daqDeserializerFactory)(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** deserialized);

/*!
 * @ingroup types_serialization
 * @defgroup types_deserializer Deserializer
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IDeserializer, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC deserialize(IString* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** object) = 0;
    virtual ErrCode INTERFACE_FUNC update(IUpdatable * updatable, IString * serialized) = 0;

    // customDeserialize should accept ISerializedObject* as parameter
    virtual ErrCode INTERFACE_FUNC callCustomProc(IProcedure* customDeserialize, IString* serialized) = 0;
};

/*!
 * @}
 */

extern "C"
ErrCode PUBLIC_EXPORT daqRegisterSerializerFactory(ConstCharPtr id, daqDeserializerFactory factory);

extern "C"
ErrCode PUBLIC_EXPORT daqUnregisterSerializerFactory(ConstCharPtr id);

extern "C"
ErrCode PUBLIC_EXPORT daqGetSerializerFactory(ConstCharPtr id, daqDeserializerFactory* factory);

#define CQDAQ_REGISTER_DESERIALIZE_FACTORY(type)                                        \
    class type##Factory                                                              \
    {                                                                                \
    public:                                                                          \
        type##Factory()                                                              \
        {                                                                            \
            daq::daqRegisterSerializerFactory(type::SerializeId(), type::Deserialize); \
        }                                                                            \
    };                                                                               \
    static type##Factory g##type##Factory;

//// TEMPLATED <T>

#define CQDAQ__CALL_TEMPLATED_T_DESERIALIZE_HANDLER(Params, ImplObj, Type1) \
    daq::daqRegisterSerializerFactory(ImplObj##Impl<Type1>::SerializeId(), \
                                    ImplObj##Impl<Type1>::Deserialize);

#define CQDAQ__CREATE_DESERIALIZE_HANDLERS_TEMPLATED_T(ImplName, Info, Types)                       \
class ImplName##Factory                                                                          \
{                                                                                                \
public:                                                                                          \
    ImplName##Factory()                                                                          \
    {                                                                                            \
        FOR_EACH_1P(                                                                             \
            CQDAQ__CALL_TEMPLATED_T_DESERIALIZE_HANDLER,                                            \
            CQDAQ_FACTORY_INFO(LIBRARY_FACTORY, CQDAQ_GET_FUNC_IMPLOBJ(Info), CQDAQ_GET_FUNC_INTF(Info)), \
            CQDAQ_GET_FUNC_IMPLOBJ(Info),                                                           \
            Types                                                                                \
        )                                                                                        \
    }                                                                                            \
};                                                                                               \
static ImplName##Factory ImplName##FactoryRegistrator;

//// TEMPLATED <T, U>

#define CQDAQ__CALL_TEMPLATED_T_U_DESERIALIZE_HANDLER(Params, FuncParams, ImplObj, Type1, Type2)                             \
    daq::daqRegisterSerializerFactory(ImplObj##Impl<Type1, Type2>::SerializeId(), ImplObj##Impl<Type1, Type2>::Deserialize);

#define CQDAQ__CREATE_DESERIALIZE_HANDLERS_TEMPLATED_T_U(ImplName, Info, Types)                                              \
    class ImplName##Factory                                                                                               \
    {                                                                                                                     \
    public:                                                                                                               \
        ImplName##Factory()                                                                                               \
        {                                                                                                                 \
            FOR_EACH_2P(CQDAQ__CALL_TEMPLATED_T_U_DESERIALIZE_HANDLER,                                                       \
                        CQDAQ__NO_DELIM,                                                                                     \
                        CQDAQ_FACTORY_INFO(LIBRARY_FACTORY, CQDAQ_GET_FUNC_IMPLOBJ(Info), CQDAQ_GET_FUNC_INTF(Info)),              \
                        (),                                                                                               \
                        CQDAQ_GET_FUNC_IMPLOBJ(Info),                                                                        \
                        Types)                                                                                            \
        }                                                                                                                 \
    };                                                                                                                    \
    static ImplName##Factory ImplName##FactoryRegistrator;

//// TEMPLATED FUNCTION <T, U>

#define CQDAQ__CALL_TEMPLATED_T_U_DESERIALIZE_HANDLER_FUNC(Params, FuncName, ImplObj, Type1, Type2)                          \
    daq::daqRegisterSerializerFactory(ImplObj##Impl<Type1, Type2>::SerializeId(), &FuncName<Type1, Type2>);

#define CQDAQ__CREATE_DESERIALIZE_HANDLERS_TEMPLATED_T_U_FUNC(ImplName, Info, Types, FuncName)                               \
    class ImplName##Factory                                                                                               \
    {                                                                                                                     \
    public:                                                                                                               \
        ImplName##Factory()                                                                                               \
        {                                                                                                                 \
            FOR_EACH_2P(CQDAQ__CALL_TEMPLATED_T_U_DESERIALIZE_HANDLER_FUNC,                                                  \
                        CQDAQ__NO_DELIM,                                                                                     \
                        CQDAQ_FACTORY_INFO(LIBRARY_FACTORY, CQDAQ_GET_FUNC_IMPLOBJ(Info), CQDAQ_GET_FUNC_INTF(Info)),              \
                        FuncName,                                                                                         \
                        CQDAQ_GET_FUNC_IMPLOBJ(Info),                                                                        \
                        Types)                                                                                            \
        }                                                                                                                 \
    };                                                                                                                    \
    static ImplName##Factory ImplName##FactoryRegistrator;

//// FUNCTION

#define CQDAQ_REGISTER_DESERIALIZE_FACTORY_FUNC(type, func)                                                                  \
    class type##Factory                                                                                                   \
    {                                                                                                                     \
    public:                                                                                                               \
        type##Factory()                                                                                                   \
        {                                                                                                                 \
            daq::daqRegisterSerializerFactory(##type::SerializeId(), func);                                                 \
        }                                                                                                                 \
    };                                                                                                                    \
    static type##Factory g##type##Factory;

END_NAMESPACE_CQDAQ
