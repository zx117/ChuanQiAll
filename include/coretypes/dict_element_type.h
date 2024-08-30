#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @brief Interface enabling introspection into the expected key and value types of the dictionary.
 */
DECLARE_CQDAQ_INTERFACE(IDictElementType, IBaseObject)
{
    /*!
     * @brief Returns the interface id of the expected key type.
     * @param[out] id The interface id of the expected key type otherwise returns the id of `IUnknown`.
     */
    virtual ErrCode INTERFACE_FUNC getKeyInterfaceId(IntfID* id) = 0;

    /*!
     * @brief Returns the interface id of the expected value type.
     * @param[out] id The interface id of the expected value type otherwise returns the id of `IUnknown`.
     */
    virtual ErrCode INTERFACE_FUNC getValueInterfaceId(IntfID* id) = 0;
};

END_NAMESPACE_CQDAQ
