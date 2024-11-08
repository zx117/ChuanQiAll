//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:45.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/device_info_internal.h"
#include <coretypes/objectptr.h>
#include <cqdaq/server_capability_ptr.h>
#include <coretypes/string_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class DeviceInfoInternalPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IDeviceInfoInternal>
{
    using SmartPtr = daq::DeviceInfoInternalPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_devices
 * @addtogroup cqdaq_device_info Device info internal
 * @{

 */

class DeviceInfoInternalPtr : public daq::ObjectPtr<IDeviceInfoInternal>
{
public:
    using daq::ObjectPtr<IDeviceInfoInternal>::ObjectPtr;
    //using daq::ObjectPtr<IDeviceInfoInternal>::operator=;



    DeviceInfoInternalPtr()
        : daq::ObjectPtr<IDeviceInfoInternal>()

    {
    }

    DeviceInfoInternalPtr(daq::ObjectPtr<IDeviceInfoInternal>&& ptr)
        : daq::ObjectPtr<IDeviceInfoInternal>(std::move(ptr))

    {
    }

    DeviceInfoInternalPtr(const daq::ObjectPtr<IDeviceInfoInternal>& ptr)
        : daq::ObjectPtr<IDeviceInfoInternal>(ptr)

    {
    }

    DeviceInfoInternalPtr(const DeviceInfoInternalPtr& other)
        : daq::ObjectPtr<IDeviceInfoInternal>(other)

    {
    }

    DeviceInfoInternalPtr(DeviceInfoInternalPtr&& other) noexcept
        : daq::ObjectPtr<IDeviceInfoInternal>(std::move(other))

    {
    }
    
    DeviceInfoInternalPtr& operator=(const DeviceInfoInternalPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IDeviceInfoInternal>::operator =(other);


        return *this;
    }

    DeviceInfoInternalPtr& operator=(DeviceInfoInternalPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IDeviceInfoInternal>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Adds a protocol to the list of supported capabilities.

     * @param serverCapability The supported protocol to add.
     */
    void addServerCapability(const daq::ServerCapabilityPtr& serverCapability) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->addServerCapability(serverCapability);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Removes a protocol from the list of supported capabilities.

     * @param protocolId The ID of the protocol to remove.
     */
    void removeServerCapability(const daq::StringPtr& protocolId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->removeServerCapability(protocolId);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Removes all server streaming capabilities from the list of supported capabilities.

     */
    void clearServerStreamingCapabilities() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->clearServerStreamingCapabilities();
        daq::checkErrorInfo(errCode);
    }


    
    daq::Bool hasServerCapability(const daq::StringPtr& protocolId) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool hasCapability;
        auto errCode = this->object->hasServerCapability(protocolId, &hasCapability);
        daq::checkErrorInfo(errCode);

        return hasCapability;
    }

#if __has_include(<cqdaq/device_info_internal_ptr.custom.h>)
    #include <cqdaq/device_info_internal_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
