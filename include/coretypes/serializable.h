
#pragma once
#include <coretypes/serializer.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_serialization
 * @defgroup types_serializable Serializable
 * @{
 */

DECLARE_CQDAQ_INTERFACE(ISerializable, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) = 0;
    virtual ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
