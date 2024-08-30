
#pragma once
#include <cqdaq/server_type.h>
#include <cqdaq/device.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup structure_servers
 * @addtogroup structure_server Server
 * @{
 */

/*!
 * @brief Represents a server. The server provides access to the cqDAQ device.
 * Depend of the implementation, it can support configuring the device, reading configuration, and data streaming.
 *
 * We do not make the server directly. But through the instance and module manager. For that reason, the server must be uniquely
 * defined with "serverType". The server is than created with the current root device, context and configuration object.
 *
 * Configuration of the server can be done with custom property object.
 * The configuration object is created with the corresponding ServerType object (IServerType::createDefaultConfig method).
 * For example, with a configuration object, we can define connection timeout.
 */
DECLARE_CQDAQ_INTERFACE(IServer, IBaseObject)
{
    /*!
    * @brief Stops the server. This is called when we remove the server from the Instance or Instance is closing.
    */
    virtual ErrCode INTERFACE_FUNC stop() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
