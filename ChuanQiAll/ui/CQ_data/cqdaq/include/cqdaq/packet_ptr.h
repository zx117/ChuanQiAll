//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:21.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/packet.h"
#include <coretypes/objectptr.h>
#include <cqdaq/packet_destruct_callback_ptr.h>




BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType = daq::IPacket>
class GenericPacketPtr;

using PacketPtr = daq::GenericPacketPtr<>;

END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IPacket>
{
    using SmartPtr = daq::GenericPacketPtr<daq::IPacket>;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @addtogroup cqdaq_packets
 * @{

 */


/*!
 * @}
 */


/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_packet Packet
 * @{

 */


/*!
 * @brief Base packet type. Data, Value, and Event packets are all also packets. Provides
 * the packet's unique ID that is unique to a given device, as well as the packet type.

 */
template <typename InterfaceType>
class GenericPacketPtr : public daq::ObjectPtr<InterfaceType>
{
public:
    using daq::ObjectPtr<InterfaceType>::ObjectPtr;
    //using daq::ObjectPtr<InterfaceType>::operator=;



    GenericPacketPtr()
        : daq::ObjectPtr<InterfaceType>()

    {
    }

    GenericPacketPtr(daq::ObjectPtr<InterfaceType>&& ptr)
        : daq::ObjectPtr<InterfaceType>(std::move(ptr))

    {
    }

    GenericPacketPtr(const daq::ObjectPtr<InterfaceType>& ptr)
        : daq::ObjectPtr<InterfaceType>(ptr)

    {
    }

    GenericPacketPtr(const PacketPtr& other)
        : daq::ObjectPtr<InterfaceType>(other)

    {
    }

    GenericPacketPtr(PacketPtr&& other) noexcept
        : daq::ObjectPtr<InterfaceType>(std::move(other))

    {
    }
    
    GenericPacketPtr& operator=(const PacketPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<InterfaceType>::operator =(other);


        return *this;
    }

    GenericPacketPtr& operator=(PacketPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<InterfaceType>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the packet's type.

     * @returns The packet type.
     */
    daq::PacketType getType() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::PacketType type;
        auto errCode = this->object->getType(&type);
        daq::checkErrorInfo(errCode);

        return type;
    }


    /*!
     * @brief Subscribes for notification when the packet is destroyed.

     * @param packetDestructCallback The callback that is called when the packet is destroyed.
     */
    void subscribeForDestructNotification(const daq::PacketDestructCallbackPtr& packetDestructCallback) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->subscribeForDestructNotification(packetDestructCallback);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Gets the reference count of the packet.

     * @returns The reference count of the packet.
     */
    daq::SizeT getRefCount() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT refCount;
        auto errCode = this->object->getRefCount(&refCount);
        daq::checkErrorInfo(errCode);

        return refCount;
    }

#if __has_include(<cqdaq/packet_ptr.custom.h>)
    #include <cqdaq/packet_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ