//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:43.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/server_capability.h"
#include <coreobjects/property_object_ptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/list_ptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IServerCapability>
class GenericServerCapabilityPtr;

using ServerCapabilityPtr = daq::GenericServerCapabilityPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IServerCapability>
{
    using SmartPtr = daq::GenericServerCapabilityPtr<daq::IServerCapability>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_server_capbility Server capbility
 * @{

 */


/*!
 * @brief Represents standard information about a server's capability to support various protocols. 
 * The Server Capability object functions as a Property Object, facilitating the inclusion of custom properties of String, Int, Bool, or Float types.
 * This interface serves to store essential details regarding the supported protocol by a device. 
 * It adheres to a standardized set of properties, including methods to retrieve information such as 
 * the connection string, protocol name, protocol type, connection type, and core events enabled.

 * Additional String, Int, Bool, or Float-type properties can be added using the appropriate Property Object "add property" method.
 * However, other property types are considered invalid for this interface.
 * The Server Capability object conforms to a standardized format, ensuring compatibility with communication standards.
 * For instance, it provides methods to retrieve details like
 * - the connection string (URL),
 * - protocol name (e.g., "cqDAQ Native Streaming," "cqDAQ OpcUa"),
 * - protocol type (e.g., "Configuration&Streaming," "Streaming"),
 * - connection type (e.g., IPv4, IPv6),
 * - core events enabled (indicating communication mode).
 */
template <typename InterfaceType>
class GenericServerCapabilityPtr : public GenericPropertyObjectPtr<InterfaceType>
{
public:
    using GenericPropertyObjectPtr<InterfaceType>::GenericPropertyObjectPtr;
    //using GenericPropertyObjectPtr<InterfaceType>::operator=;



    GenericServerCapabilityPtr()
        : GenericPropertyObjectPtr<InterfaceType>()

    {
    }

    GenericServerCapabilityPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : GenericPropertyObjectPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericServerCapabilityPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : GenericPropertyObjectPtr<InterfaceType>(ptr)

    {
    }

    GenericServerCapabilityPtr(const ServerCapabilityPtr& other)
        : GenericPropertyObjectPtr<InterfaceType>(other)

    {
    }

    GenericServerCapabilityPtr(ServerCapabilityPtr&& other) noexcept
        : GenericPropertyObjectPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericServerCapabilityPtr& operator=(const ServerCapabilityPtr& other)
    {
        if (this == &other)
            return *this;

        GenericPropertyObjectPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericServerCapabilityPtr& operator=(ServerCapabilityPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericPropertyObjectPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the connection string of the device with the current protocol.

     * @returns The connection string of the device (URL to connect).
     */
    daq::StringPtr getConnectionString() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr connectionString;
        auto errCode = this->object->getConnectionString(&connectionString);
        daq::checkErrorInfo(errCode);

        return connectionString;
    }


    /*!
     * @brief Gets the connection string of the device with the current protocol.

     * @returns The connection string of the device (URL to connect).
     */
    daq::ListPtr<daq::IString> getConnectionStrings() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ListPtr<daq::IString> connectionStrings;
        auto errCode = this->object->getConnectionStrings(&connectionStrings);
        daq::checkErrorInfo(errCode);

        return connectionStrings;
    }


    /*!
     * @brief Gets the name of the protocol supported by the device.

     * @returns The name of the protocol (e.g., "cqDAQ Native Streaming", "cqDAQ OpcUa", "cqDAQ LT Streaming").
     */
    daq::StringPtr getProtocolName() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr protocolName;
        auto errCode = this->object->getProtocolName(&protocolName);
        daq::checkErrorInfo(errCode);

        return protocolName;
    }


    /*!
     * @brief Gets the id of the protocol supported by the device. Should not contain spaces or special characters except for '_' and '-'.

     * @returns The id of the protocol.
     */
    daq::StringPtr getProtocolId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr protocolId;
        auto errCode = this->object->getProtocolId(&protocolId);
        daq::checkErrorInfo(errCode);

        return protocolId;
    }


    /*!
     * @brief Gets the type of protocol supported by the device.

     * @returns The type of protocol (Enumeration value reflecting protocol type: "ConfigurationAndStreaming", "Configuration", "Streaming", "ServerStreaming", "Unknown").
     */
    daq::ProtocolType getProtocolType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ProtocolType type;
        auto errCode = this->object->getProtocolType(&type);
        daq::checkErrorInfo(errCode);

        return type;
    }


    /*!
     * @brief Gets the prefix of the connection string (eg. "daq.nd" or "daq.opcua")

     * @returns The connection string prefix
     */
    daq::StringPtr getPrefix() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr prefix;
        auto errCode = this->object->getPrefix(&prefix);
        daq::checkErrorInfo(errCode);

        return prefix;
    }


    /*!
     * @brief Gets the type of connection supported by the device.

     * @returns The type of connection (e.g., "TCP/IP").
     */
    daq::StringPtr getConnectionType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr type;
        auto errCode = this->object->getConnectionType(&type);
        daq::checkErrorInfo(errCode);

        return type;
    }


    /*!
     * @brief Gets the client update method supported by the device.

     * @returns The client update method (Boolean value indicating if core events are enabled for communication between server and client device).
     */
    daq::Bool getCoreEventsEnabled() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool enabled;
        auto errCode = this->object->getCoreEventsEnabled(&enabled);
        daq::checkErrorInfo(errCode);

        return enabled;
    }

#if __has_include(<cqdaq/server_capability_ptr.custom.h>)
    #include <cqdaq/server_capability_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
