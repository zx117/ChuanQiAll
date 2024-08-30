
#pragma once
#include <cqdaq/instance_builder_ptr.h>
#include <cqdaq/instance_ptr.h>
#include <cqdaq/scheduler_factory.h>
#include <cqdaq/logger_factory.h>
#include <cqdaq/context_factory.h>
#include <cqdaq/module_manager_factory.h>
#include <coretypes/type_manager_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_instance
 * @addtogroup cqdaq_instance_factories Factories
 * @{
 */

/*!
 * @brief Creates a new Instance with the provided Context.
 * @param context The Context.
 * @param localId The instance local id.
 */
inline InstancePtr InstanceCustom(const ContextPtr& context,
                                  const StringPtr& localId)
{
    InstancePtr obj(Instance_Create(context, localId));
    return obj;
}

/*!
 * @brief Creates a InstanceBuilder with no parameters configured.
 */
inline InstanceBuilderPtr InstanceBuilder()
{
    InstanceBuilderPtr obj(InstanceBuilder_Create());
    return obj;
}

/*!
 * @brief Creates a Instance with Builder
 * @param builder Instance Builder
 */
inline InstancePtr InstanceFromBuilder(const InstanceBuilderPtr& builder)
{
    InstancePtr obj(InstanceFromBuilder_Create(builder));
    return obj;
}

/*!
 * @brief Creates a new Instance, using the default logger and module manager. The module manager
 * searches for module shared libraries at the given module path, using the executable directory if left empty.
 * @param modulePath The module search path to be used by the Module manager.
 * @param localId The local id of the instance.
 *
 * If localId is empty, the local id will be set to the CQDAQ_INSTANCE_ID environment variable if available. Otherwise
 * a random UUID will be generated for the local id.
 */
inline InstancePtr Instance(const std::string& modulePath = "", const std::string& localId = "")
{
    auto builder = InstanceBuilder().setModulePath(modulePath).setDefaultRootDeviceLocalId(localId);
    return InstanceFromBuilder(builder);
}

/*!
 * @brief Creates a Client implementation of a device.
 * @param context The Context to be used by the client.
 * @param localId The local id of the instance.
 * @param defaultDeviceInfo The DeviceInfo to be used by the client device.
 * @param parent The parent component of the client.
 *
 * When creating an Instance, it by default creates a Client and sets it as the root device.
 * The Client supports adding function blocks and connecting to devices. The array of function blocks
 * and supported devices depends on the modules loaded by the Module manager.
 */
inline DevicePtr Client(const ContextPtr& context, const StringPtr& localId, const DeviceInfoPtr& defaultDeviceInfo = nullptr, const ComponentPtr& parent = nullptr)
{
    DevicePtr obj(Client_Create(context, localId, defaultDeviceInfo, parent));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
