

#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IDeviceInfo, GenericDeviceInfoPtr)]
 * [interfaceLibrary(IPropertyObject, "coreobjects")]
 */

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_device_info Device info internal
 * @{
 */

DECLARE_CQDAQ_INTERFACE(IDeviceInfoInternal, IBaseObject)
{

    /*!
     * @brief Adds a protocol to the list of supported capabilities.
     * @param serverCapability The supported protocol to add.
     */
    virtual ErrCode INTERFACE_FUNC addServerCapability(IServerCapability* serverCapability) = 0;

    /*!
     * @brief Removes a protocol from the list of supported capabilities.
     * @param protocolId The ID of the protocol to remove.
     */
    virtual ErrCode INTERFACE_FUNC removeServerCapability(IString* protocolId) = 0;

    /*!
     * @brief Removes all server streaming capabilities from the list of supported capabilities.
     */
    virtual ErrCode INTERFACE_FUNC clearServerStreamingCapabilities() = 0;

    virtual ErrCode INTERFACE_FUNC hasServerCapability(IString* protocolId, Bool* hasCapability) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
