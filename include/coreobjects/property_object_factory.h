#pragma once
#include <coretypes/common.h>
#include <coreobjects/property_object_ptr.h>
#include <coretypes/type_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_property_object_obj
 * @addtogroup objects_property_object_obj_factories Factories
 * @{
 */

/*!
 * @brief Creates a empty Property object with no class.
 *
 * The Type Manager is usually obtained from the cqDAQ Context object.
 */
inline PropertyObjectPtr PropertyObject()
{
    return {PropertyObject_Create()};
}

/*!
 * @brief Creates a Property object that inherits the properties of a class added to the Type manager with the specified name.
 * @param manager The Type manager.
 * @param className The name of the class from which the Property object inherits its properties.
 */
inline PropertyObjectPtr PropertyObject(const TypeManagerPtr& manager,
                                        const StringPtr& className)
{
    return {PropertyObjectWithClassAndManager_Create(manager, className)};
}

/*!@}*/

END_NAMESPACE_CQDAQ
