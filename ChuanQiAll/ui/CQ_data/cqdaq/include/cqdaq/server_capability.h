
#pragma once
#include <cqdaq/context.h>
#include <coretypes/common.h>
#include <coretypes/stringobject.h>
#include <coretypes/enumeration.h>
#include <coreobjects/property_object.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_server_capbility Server capbility
 * @{
 */

enum class ProtocolType: uint32_t
{
    Unknown = 0,
    Configuration,
    Streaming,
    ConfigurationAndStreaming,
};

/*#
 * [templated(defaultAliasName: ServerCapabilityPtr)]
 * [interfaceSmartPtr(IServerCapability, GenericServerCapabilityPtr)]
 * [interfaceSmartPtr(IEnumeration, EnumerationPtr, "<coretypes/enumeration_ptr.h>")]
 * [interfaceLibrary(IPropertyObject, "coreobjects")]
 * [interfaceSmartPtr(IPropertyObject, GenericPropertyObjectPtr, "<coreobjects/property_object_ptr.h>")]
 */

/*!
 * @brief Represents standard information about a server's capability to support various protocols. 
 * The Server Capability object functions as a Property Object, facilitating the inclusion of custom properties of String, Int, Bool, or Float types.
 * This interface serves to store essential details regarding the supported protocol by a device. 
 * It adheres to a standardized set of properties, including methods to retrieve information such as 
 * the connection string, protocol name, protocol type, connection type, and core events enabled.
 * 
 * Additional String, Int, Bool, or Float-type properties can be added using the appropriate Property Object "add property" method. 
 * However, other property types are considered invalid for this interface.
 * 
 * The Server Capability object conforms to a standardized format, ensuring compatibility with communication standards. 
 * For instance, it provides methods to retrieve details like 
 * - the connection string (URL), 
 * - protocol name (e.g., "cqDAQ Native Streaming," "cqDAQ OpcUa"), 
 * - protocol type (e.g., "Configuration&Streaming," "Streaming"), 
 * - connection type (e.g., IPv4, IPv6),
 * - core events enabled (indicating communication mode).
*/
DECLARE_CQDAQ_INTERFACE(IServerCapability, IPropertyObject)
{
    /*!
     * @brief Gets the connection string of the device with the current protocol.
     * @param[out] connectionString The connection string of the device (URL to connect).
     */
    virtual ErrCode INTERFACE_FUNC getConnectionString(IString** connectionString) = 0;

    // [templateType(connectionStrings, IString)]
    /*!
     * @brief Gets the connection string of the device with the current protocol.
     * @param[out] connectionStrings The connection string of the device (URL to connect).
     */
    virtual ErrCode INTERFACE_FUNC getConnectionStrings(IList** connectionStrings) = 0;

    /*!
     * @brief Gets the name of the protocol supported by the device.
     * @param[out] protocolName The name of the protocol (e.g., "cqDAQ Native Streaming", "cqDAQ OpcUa", "cqDAQ LT Streaming").
     */
    virtual ErrCode INTERFACE_FUNC getProtocolName(IString** protocolName) = 0;

    /*!
     * @brief Gets the id of the protocol supported by the device. Should not contain spaces or special characters except for '_' and '-'.
     * @param[out] protocolId The id of the protocol.
     */
    virtual ErrCode INTERFACE_FUNC getProtocolId(IString** protocolId) = 0;

    /*!
     * @brief Gets the type of protocol supported by the device.
     * @param[out] type The type of protocol (Enumeration value reflecting protocol type: "ConfigurationAndStreaming", "Configuration", "Streaming", "ServerStreaming", "Unknown").
     */
    virtual ErrCode INTERFACE_FUNC getProtocolType(ProtocolType* type) = 0;

    /*!
     * @brief Gets the prefix of the connection string (eg. "daq.nd" or "daq.opcua")
     * @param prefix The connection string prefix
     */
    virtual ErrCode INTERFACE_FUNC getPrefix(IString** prefix) = 0;

    /*!
     * @brief Gets the type of connection supported by the device.
     * @param[out] type The type of connection (e.g., "TCP/IP").
     */
    virtual ErrCode INTERFACE_FUNC getConnectionType(IString** type) = 0;

    /*!
     * @brief Gets the client update method supported by the device.
     * @param[out] enabled The client update method (Boolean value indicating if core events are enabled for communication between server and client device).
     */
    virtual ErrCode INTERFACE_FUNC getCoreEventsEnabled(Bool* enabled) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
