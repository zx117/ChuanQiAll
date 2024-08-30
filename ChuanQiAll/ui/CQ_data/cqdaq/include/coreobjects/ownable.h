#pragma once
#include <coretypes/coretypes.h>
#include <coreobjects/property_object.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_utility
 * @addtogroup objects_ownable Ownable
 * @{
 */

/*!
 * @brief An ownable object can have IPropertyObject as the owner.
 *
 * An object can declare itself ownable. When a parent object that supports a concept of ownership
 * calls the` setOwner` method, it becomes the owner of the object. It's up to the object's implementation
 * to decide what actions should it forward to the owner.
 *
 * For example, a property object that is a child of another property object will look up property values 
 * in their owner's dictionary if the property is not set locally.
 */

/*#
 * [includeHeader("<coreobjects/property_object_ptr.h>")]
 */
DECLARE_CQDAQ_INTERFACE(IOwnable, IBaseObject)
{
    /*!
     * @brief Sets the owner of the object.
     * @param owner The object that will own this object.
     */
    virtual ErrCode INTERFACE_FUNC setOwner(IPropertyObject* owner) = 0;
};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
