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
#include "cqdaq/packet_destruct_callback.h"
#include <coretypes/objectptr.h>




BEGIN_NAMESPACE_CQDAQ


class PacketDestructCallbackPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IPacketDestructCallback>
{
    using SmartPtr = daq::PacketDestructCallbackPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_packet Packet
 * @{

 */


/*!
 * @brief Used to subscribe to packet destruction

 */

class PacketDestructCallbackPtr : public daq::ObjectPtr<IPacketDestructCallback>
{
public:
    using daq::ObjectPtr<IPacketDestructCallback>::ObjectPtr;
    //using daq::ObjectPtr<IPacketDestructCallback>::operator=;



    PacketDestructCallbackPtr()
        : daq::ObjectPtr<IPacketDestructCallback>()

    {
    }

    PacketDestructCallbackPtr(daq::ObjectPtr<IPacketDestructCallback>&& ptr)
        : daq::ObjectPtr<IPacketDestructCallback>(std::move(ptr))

    {
    }

    PacketDestructCallbackPtr(const daq::ObjectPtr<IPacketDestructCallback>& ptr)
        : daq::ObjectPtr<IPacketDestructCallback>(ptr)

    {
    }

    PacketDestructCallbackPtr(const PacketDestructCallbackPtr& other)
        : daq::ObjectPtr<IPacketDestructCallback>(other)

    {
    }

    PacketDestructCallbackPtr(PacketDestructCallbackPtr&& other) noexcept
        : daq::ObjectPtr<IPacketDestructCallback>(std::move(other))

    {
    }
    
    PacketDestructCallbackPtr& operator=(const PacketDestructCallbackPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IPacketDestructCallback>::operator =(other);


        return *this;
    }

    PacketDestructCallbackPtr& operator=(PacketDestructCallbackPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IPacketDestructCallback>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Called when packet is destroyed.

     */
    void onPacketDestroyed() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->onPacketDestroyed();
        daq::checkErrorInfo(errCode);
    }

#if __has_include(<cqdaq/packet_destruct_callback_ptr.custom.h>)
    #include <cqdaq/packet_destruct_callback_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
