#pragma once
#include <coreobjects/property_object_class_builder_ptr.h>
#include <coretypes/type_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_property_object_class
 * @addtogroup objects_property_object_class_factories Factories
 * @{
 */

/*!
 * @brief Creates a property object class builder object with a given name.
 * @param name The name of the class.
 */
inline PropertyObjectClassBuilderPtr PropertyObjectClassBuilder(const StringPtr& name)
{
    PropertyObjectClassBuilderPtr obj(PropertyObjectClassBuilder_Create(name));
    return obj;
}

/*!
 * @brief Creates a Property object class builder object with a given name, and a reference to the Property object class manager.
 * @param manager The Property object class manager object.
 * @param name The name of the class.
 */
inline PropertyObjectClassBuilderPtr PropertyObjectClassBuilder(const TypeManagerPtr& manager, const StringPtr& name)
{
    PropertyObjectClassBuilderPtr obj(PropertyObjectClassBuilderWithManager_Create(manager, name));
    return obj;
}

/*!
 * @brief Creates a PropertyObjectClass using Builder
 * @param builder PropertyObjectClass Builder
 */
inline PropertyObjectClassPtr PropertyObjectClassFromBuilder(const PropertyObjectClassBuilderPtr& builder)
{
    PropertyObjectClassPtr obj(PropertyObjectClassFromBuilder_Create(builder));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
