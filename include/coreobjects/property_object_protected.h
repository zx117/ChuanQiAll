#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_property_object
 * @addtogroup objects_property_object_protected PropertyObjectProtected
 * @{
 */

/*!
 * @brief Provides protected access that allows changing read-only property values of a Property object.
 */
DECLARE_CQDAQ_INTERFACE(IPropertyObjectProtected, IBaseObject)
{
    /*!
     * @brief Sets a property value. Does not fail if the property is read-only.
     * @param propertyName The name of the Property of which value the function should set.
     * @param value The property value to set.
     */
    virtual ErrCode INTERFACE_FUNC setProtectedPropertyValue(IString* propertyName, IBaseObject* value) = 0;

    /*!
     * @brief Clears a property value. Does not fail if the property is read-only.
     * @param propertyName The name of the Property of which value the function should be cleared.
     */
    virtual ErrCode INTERFACE_FUNC clearProtectedPropertyValue(IString* propertyName) = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
