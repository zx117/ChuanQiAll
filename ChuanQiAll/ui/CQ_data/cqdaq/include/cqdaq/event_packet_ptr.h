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
#include "cqdaq/event_packet.h"
#include "packet_ptr.h"
#include <cqdaq/packet_ptr.h>
#include <coretypes/string_ptr.h>
#include <coretypes/dict_ptr.h>
#include <coretypes/objectptr.h>




BEGIN_NAMESPACE_CQDAQ


class EventPacketPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IEventPacket>
{
    using SmartPtr = daq::EventPacketPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_event_packet Event packet
 * @{

 */


/*!
 * @brief As with Data packets, Event packets travel along the signal paths. They are used to
 * notify recipients of any relevant changes to the signal sending the packet.

 */

class EventPacketPtr : public GenericPacketPtr<IEventPacket>
{
public:
    using GenericPacketPtr<IEventPacket>::GenericPacketPtr;
    //using GenericPacketPtr<IEventPacket>::operator=;



    EventPacketPtr()
        : GenericPacketPtr<IEventPacket>()

    {
    }

    EventPacketPtr(daq::ObjectPtr<IEventPacket>&& ptr)
        : GenericPacketPtr<IEventPacket>(std::move(ptr))

    {
    }

    EventPacketPtr(const daq::ObjectPtr<IEventPacket>& ptr)
        : GenericPacketPtr<IEventPacket>(ptr)

    {
    }

    EventPacketPtr(const EventPacketPtr& other)
        : GenericPacketPtr<IEventPacket>(other)

    {
    }

    EventPacketPtr(EventPacketPtr&& other) noexcept
        : GenericPacketPtr<IEventPacket>(std::move(other))

    {
    }
    
    EventPacketPtr& operator=(const EventPacketPtr& other)
    {
        if (this == &other)
            return *this;

        GenericPacketPtr<IEventPacket>::operator =(other);


        return *this;
    }

    EventPacketPtr& operator=(EventPacketPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericPacketPtr<IEventPacket>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Gets the ID of the event as a string. In example "DATA_DESCRIPTOR_CHANGED".

     * @returns The ID of the event.
     */
    daq::StringPtr getEventId() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr id;
        auto errCode = this->object->getEventId(&id);
        daq::checkErrorInfo(errCode);

        return id;
    }


    /*!
     * @brief Dictionary containing parameters as <String, BaseObject> pairs relevant to the event
     * signalized by the Event packet.

     * @returns The event parameters dictionary.
     */
    daq::DictPtr<daq::IString, daq::IBaseObject> getParameters() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::DictPtr<daq::IString, daq::IBaseObject> parameters;
        auto errCode = this->object->getParameters(&parameters);
        daq::checkErrorInfo(errCode);

        return parameters;
    }

#if __has_include(<cqdaq/event_packet_ptr.custom.h>)
    #include <cqdaq/event_packet_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ