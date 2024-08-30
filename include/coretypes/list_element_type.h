
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @brief Interface enabling introspection into the expected element type of the list.
 */
DECLARE_CQDAQ_INTERFACE(IListElementType, IBaseObject)
{
    /*!
     * @brief Returns the interface id of the expected list element type.
     * @param[out] id The interface id of the expected element type otherwise returns the id of `IUnknown`.
     */
    virtual ErrCode INTERFACE_FUNC getElementInterfaceId(IntfID* id) = 0;
};

END_NAMESPACE_CQDAQ
