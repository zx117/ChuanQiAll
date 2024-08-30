
#pragma once
#include <cqdaq/context_ptr.h>
#include <cqdaq/device_info_config_ptr.h>
#include <cqdaq/server_capability_config_ptr.h>

BEGIN_NAMESPACE_CQDAQ
/*!
 * @ingroup cqdaq_device_info
 * @addtogroup cqdaq_device_info_factories Factories
 * @{
 */

/*!
 * @brief Creates a DeviceInfoConfig with a connection string and optional name.
 * @param connectionString String used to connect to the device.
 * @param name The name of the device. Optional parameter.
 * @param customSdkVersion Used when the device uses a custom SDK version. Optional parameter.
 */
inline DeviceInfoConfigPtr DeviceInfo(const StringPtr& connectionString, const StringPtr& name = "", const StringPtr& customSdkVersion = nullptr)
{
    DeviceInfoConfigPtr obj(DeviceInfoConfigWithCustomSdkVersion_Create(name, connectionString, customSdkVersion));
    return obj;
}

inline ServerCapabilityConfigPtr ServerCapability(const StringPtr& protocolId, const StringPtr& protocolName, ProtocolType protocolType)
{
    ServerCapabilityConfigPtr obj(ServerCapability_Create(protocolId, protocolName, protocolType));
    return obj;
}

/*!@}*/
END_NAMESPACE_CQDAQ
