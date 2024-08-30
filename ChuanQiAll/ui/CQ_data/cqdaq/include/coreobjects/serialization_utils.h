#pragma once
#include <coretypes/serialization.h>
#include <coreobjects/property_builder_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename T, typename Enable = void>
struct ValueType;

template <>
struct ValueType<IBaseObject>
{
    using Type = IBaseObject;
};

template <typename T>
struct ValueType<T, std::enable_if_t<IsDerivedFromTemplate<T, ObjectPtr>::Value>>
{
    using Type = typename CoreTypeHelper<typename IntfToCoreType<typename T::DeclaredInterface>::CoreType>::TrueType;
};

template <typename T>
struct ValueType<T, std::enable_if_t<!IsDerivedFromTemplate<T, ObjectPtr>::Value>>
{
    using Type = typename CoreTypeHelper<T>::TrueType;
};

template <typename ParamType, typename PropSetter = ErrCode (INTERFACE_FUNC IPropertyBuilder::*)(ParamType*)>
inline ErrCode deserializeMember(ISerializedObject* serialized,
                                 StringPtr memberName,
                                 IPropertyBuilder* info,
                                 [[maybe_unused]] IBaseObject* context,
                                 [[maybe_unused]] IFunction* factoryCallback,
                                 PropSetter functor)
{
    using RawType = typename ValueType<ParamType>::Type;
    using MemberType = std::conditional_t<std::is_fundamental_v<RawType>, RawType, typename InterfaceOrTypeToSmartPtr<RawType>::SmartPtr>;
    using CastType = std::conditional_t<std::is_enum_v<ParamType>, ParamType, MemberType>;

    MemberType memberValue{};
    ErrCode errCode = CQDAQ_ERR_GENERALERROR;
    if constexpr (std::is_same_v<RawType, std::string> || std::is_same_v<RawType, std::wstring> || std::is_same_v<ParamType, IString>)
    {
        errCode = serialized->readString(memberName, &memberValue);
    }
    else if constexpr (std::is_same_v<Bool, ParamType> || std::is_same_v<bool, ParamType>)
    {
        errCode = serialized->readBool(memberName, &memberValue);
    }
    else if constexpr (std::is_integral_v<RawType>)
    {
        errCode = serialized->readInt(memberName, &memberValue);
    }
    else if constexpr (std::is_floating_point_v<RawType>)
    {
        errCode = serialized->readFloat(memberName, &memberValue);
    }
    else if constexpr (std::is_abstract_v<ParamType>)
    {
        errCode = serialized->readObject(memberName, context, factoryCallback, &memberValue);
    }
    else
    {
        static_assert(DependentFalse<ParamType>::value, "Not implemented for this type.");
    }

    if (errCode != CQDAQ_ERR_NOTFOUND && CQDAQ_FAILED(errCode))
    {
        return errCode;
    }

    if (errCode != CQDAQ_ERR_NOTFOUND)
    {
        return (info->*functor)(CastType(memberValue));
    }
    return CQDAQ_SUCCESS;
}

using BaseObjectSetter = ErrCode (INTERFACE_FUNC IPropertyBuilder::*)(IBaseObject*);

template <>
inline ErrCode deserializeMember<BaseObjectPtr, BaseObjectSetter>(ISerializedObject* serialized,
                                                                  StringPtr memberName,
                                                                  IPropertyBuilder* info,
                                                                  IBaseObject* context,
                                                                  IFunction* factoryCallback,
                                                                  BaseObjectSetter functor)
{
    return deserializeMember<IBaseObject, BaseObjectSetter>(serialized, std::move(memberName), info, context, factoryCallback, functor);
}

#define DESERIALIZE_MEMBER_WITH_NAME(context, factoryCallback, name, key, setter)                                                    \
    errCode = deserializeMember<decltype(name)>(serializedObj, key, propObj, context, factoryCallback, &IPropertyBuilder::setter);    \
    if (CQDAQ_FAILED(errCode))                                                                                         \
    {                                                                                                               \
        return errCode;                                                                                             \
    }                                                                                                               \


#define DESERIALIZE_MEMBER(context, factoryCallback, name, setter) DESERIALIZE_MEMBER_WITH_NAME(context, factoryCallback, name, #name, setter)

inline ErrCode serializeMember(ISerializer* serializer, const char* name, const BaseObjectPtr& value)
{
    if (value.assigned())
    {
        ISerializable* serializable;
        ErrCode errCode = value->borrowInterface(ISerializable::Id, reinterpret_cast<void**>(&serializable));

        if (errCode == CQDAQ_ERR_NOINTERFACE)
        {
            return CQDAQ_ERR_NOT_SERIALIZABLE;
        }

        if (CQDAQ_FAILED(errCode))
        {
            return errCode;
        }

        serializer->key(name);
        errCode = serializable->serialize(serializer);
        if (CQDAQ_FAILED(errCode))
        {
            return errCode;
        }
    }
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
