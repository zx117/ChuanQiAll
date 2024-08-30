
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/serialized_object.h>
#include <coretypes/serializer.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_utility
 * @defgroup types_updatable Updatable
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IUpdatable, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC update(ISerializedObject* update) = 0;
    virtual ErrCode INTERFACE_FUNC serializeForUpdate(ISerializer* serializer) = 0;
    virtual ErrCode INTERFACE_FUNC updateEnded() = 0;
};

/*!
 * @}
 */

template <typename T>
using IsEnumTypeEnum = std::enable_if<std::is_enum_v<T> &&
                                      std::is_same_v<std::underlying_type_t<T>, EnumType>,
                                      int>;

template <typename T, typename IsEnumTypeEnum<T>::type = 0>
T operator|(T lhs, T rhs)
{
    return T(EnumType(lhs) | EnumType(rhs));
}

template <typename T, typename IsEnumTypeEnum<T>::type = 0>
bool operator&(T lhs, T rhs)
{
    return EnumType(lhs) & EnumType(rhs);
}

END_NAMESPACE_CQDAQ
