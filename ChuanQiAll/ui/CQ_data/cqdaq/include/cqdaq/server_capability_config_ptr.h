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
#include "cqdaq/server_capability_config.h"
#include "server_capability_ptr.h"
#include <cqdaq/server_capability_ptr.h>
#include <coretypes/string_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ServerCapabilityConfigPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IServerCapabilityConfig>
{
    using SmartPtr = daq::ServerCapabilityConfigPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ




class ServerCapabilityConfigPtr : public GenericServerCapabilityPtr<IServerCapabilityConfig>
{
public:
    using GenericServerCapabilityPtr<IServerCapabilityConfig>::GenericServerCapabilityPtr;
    //using GenericServerCapabilityPtr<IServerCapabilityConfig>::operator=;



    ServerCapabilityConfigPtr()
        : GenericServerCapabilityPtr<IServerCapabilityConfig>()

    {
    }

    ServerCapabilityConfigPtr(daq::ObjectPtr<IServerCapabilityConfig>&& ptr)
        : GenericServerCapabilityPtr<IServerCapabilityConfig>(std::move(ptr))

    {
    }

    ServerCapabilityConfigPtr(const daq::ObjectPtr<IServerCapabilityConfig>& ptr)
        : GenericServerCapabilityPtr<IServerCapabilityConfig>(ptr)

    {
    }

    ServerCapabilityConfigPtr(const ServerCapabilityConfigPtr& other)
        : GenericServerCapabilityPtr<IServerCapabilityConfig>(other)

    {
    }

    ServerCapabilityConfigPtr(ServerCapabilityConfigPtr&& other) noexcept
        : GenericServerCapabilityPtr<IServerCapabilityConfig>(std::move(other))

    {
    }
    
    ServerCapabilityConfigPtr& operator=(const ServerCapabilityConfigPtr& other)
    {
        if (this == &other)
            return *this;

        GenericServerCapabilityPtr<IServerCapabilityConfig>::operator =(other);


        return *this;
    }

    ServerCapabilityConfigPtr& operator=(ServerCapabilityConfigPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericServerCapabilityPtr<IServerCapabilityConfig>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Sets the connection string of device with current protocol

     * @param connectionString The connection string of device
     */
    ServerCapabilityConfigPtr setConnectionString(const daq::StringPtr& connectionString) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setConnectionString(connectionString);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the connection string of device with current protocol

     * @param connectionString The connection string of device
     */
    ServerCapabilityConfigPtr addConnectionString(const daq::StringPtr& connectionString) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->addConnectionString(connectionString);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the ID of protocol

     * @param protocolId The ID of protocol
     */
    ServerCapabilityConfigPtr setProtocolId(const daq::StringPtr& protocolId) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setProtocolId(protocolId);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the name of protocol

     * @param protocolName The name of protocol
     */
    ServerCapabilityConfigPtr setProtocolName(const daq::StringPtr& protocolName) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setProtocolName(protocolName);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the type of protocol

     * @param type The type of protocol
     */
    ServerCapabilityConfigPtr setProtocolType(daq::ProtocolType type) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setProtocolType(type);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the prefix of the connection string (eg. "daq.nd" or "daq.opcua")

     * @param prefix The connection string prefix
     */
    ServerCapabilityConfigPtr setPrefix(const daq::StringPtr& prefix) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setPrefix(prefix);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the type of connection

     * @param type The type of connection
     */
    ServerCapabilityConfigPtr setConnectionType(const daq::StringPtr& type) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setConnectionType(type);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }


    /*!
     * @brief Sets the boolean flag indicating whether the server capability supports core event propagation to clients

     * @param enabled True if core events are enabled; false otherwise
     */
    ServerCapabilityConfigPtr setCoreEventsEnabled(daq::Bool enabled) const
     {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->setCoreEventsEnabled(enabled);
        daq::checkErrorInfo(errCode);
        return this->addRefAndReturn();
    }

#if __has_include(<cqdaq/server_capability_config_ptr.custom.h>)
    #include <cqdaq/server_capability_config_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ