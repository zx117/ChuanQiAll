
#pragma once
#include <coreobjects/component_type.h>

BEGIN_NAMESPACE_CQDAQ

/*#
* [templated(defaultAliasName: DeviceTypePtr)]
* [interfaceSmartPtr(IDeviceType, GenericDeviceTypePtr)]
* [interfaceSmartPtr(IComponentType, GenericComponentTypePtr, "<coreobjects/component_type_ptr.h>")]
* [interfaceLibrary(IComponentType, "coreobjects")]
*/

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_device_type Device type
 * @{
 */

/*!
 * @brief Provides information about the device type.
 */

DECLARE_CQDAQ_INTERFACE(IDeviceType, IComponentType)
{
};
/*!@}*/

/*!
 * @ingroup cqdaq_device_type
 * @addtogroup cqdaq_device_type_factories Factories
 * @{
 */

/*!
 * @brief Creates a Device type object, with the id, name, description and
 * optional createDefaultConfigCallback.
 * @param id The unique type ID of the device.
 * @param name The name of the device type.
 * @param description A short description of the device type.
 * @param createDefaultConfigCallback The callback, which is called, when user want to create
 * new default configuration object.
 * Function needs to create and return property object. On each call, we need to create new object,
 * because we want that each instance of the device has its own configuration object.
 */
CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, DeviceType,
    IString*, id,
    IString*, name,
    IString*, description,
    IFunction*, createDefaultConfigCallback
)

/*!@}*/
END_NAMESPACE_CQDAQ
