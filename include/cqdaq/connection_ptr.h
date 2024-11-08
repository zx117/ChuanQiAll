//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:20.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/connection.h"
#include <coretypes/objectptr.h>
#include <cqdaq/packet_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class ConnectionPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IConnection>
{
    using SmartPtr = daq::ConnectionPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_connection Connection
 * @{

 */


/*!
 * @brief Represents a connection between an Input port and Signal. Acts as a queue
 * for packets sent by the signal, which can be read by the input port and the input port's
 * owner.

 * The Connection provides standard queue methods, allowing for packets to be put at the back
 * of the queue, and popped from the front. Additionally, the front packet can be inspected via
 * `peek`, and the number of queued packets can be obtained through `getPacketCount`.
 * The Connection has a reference to the connected Signal and Input port.
 */

class ConnectionPtr : public daq::ObjectPtr<IConnection>
{
public:
    using daq::ObjectPtr<IConnection>::ObjectPtr;
    //using daq::ObjectPtr<IConnection>::operator=;



    ConnectionPtr()
        : daq::ObjectPtr<IConnection>()

    {
    }

    ConnectionPtr(daq::ObjectPtr<IConnection>&& ptr)
        : daq::ObjectPtr<IConnection>(std::move(ptr))

    {
    }

    ConnectionPtr(const daq::ObjectPtr<IConnection>& ptr)
        : daq::ObjectPtr<IConnection>(ptr)

    {
    }

    ConnectionPtr(const ConnectionPtr& other)
        : daq::ObjectPtr<IConnection>(other)

    {
    }

    ConnectionPtr(ConnectionPtr&& other) noexcept
        : daq::ObjectPtr<IConnection>(std::move(other))

    {
    }
    
    ConnectionPtr& operator=(const ConnectionPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IConnection>::operator =(other);


        return *this;
    }

    ConnectionPtr& operator=(ConnectionPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<IConnection>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Places a packet at the back of the queue.

     * @param packet The packet to be enqueued.
     */
    void enqueue(const daq::PacketPtr& packet) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->enqueue(packet);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Places a packet at the back of the queue.

     * @param packet The packet to be enqueued.
     * The connection notifies the listener on the same thread that this method was called.
     */
    void enqueueOnThisThread(const daq::PacketPtr& packet) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        auto errCode = this->object->enqueueOnThisThread(packet);
        daq::checkErrorInfo(errCode);
    }


    /*!
     * @brief Removes the packet at the front of the queue and returns it.

     * @returns The removed packet or @c nullptr if the connection has no packets.
     * @retval CQDAQ_NO_MORE_ITEMS When the connection does not hold any packets.
     */
    daq::PacketPtr dequeue() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::PacketPtr packet;
        auto errCode = this->object->dequeue(&packet);
        daq::checkErrorInfo(errCode);

        return packet;
    }


    /*!
     * @brief Returns the packet at the front of the queue without removing it.

     * @returns The packet at the front of the queue or @c nullptr if the connection has no packets.
     * @retval CQDAQ_NO_MORE_ITEMS When the connection does not hold any packets.
     */
    daq::PacketPtr peek() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::PacketPtr packet;
        auto errCode = this->object->peek(&packet);
        daq::checkErrorInfo(errCode);

        return packet;
    }


    /*!
     * @brief Gets the number of queued packets.

     * @returns The number of queued packets.
     */
    daq::SizeT getPacketCount() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT packetCount;
        auto errCode = this->object->getPacketCount(&packetCount);
        daq::checkErrorInfo(errCode);

        return packetCount;
    }


    /*!
     * @brief Gets the Signal that is sending packets through the Connection.

     * @returns The Signal.
     */
    daq::ObjectPtr<ISignal> getSignal() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ObjectPtr<ISignal> signal;
        auto errCode = this->object->getSignal(&signal);
        daq::checkErrorInfo(errCode);

        return signal;
    }


    /*!
     * @brief Gets the Input port to which packets are being sent.

     * @returns The input port.
     */
    daq::ObjectPtr<IInputPort> getInputPort() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ObjectPtr<IInputPort> inputPort;
        auto errCode = this->object->getInputPort(&inputPort);
        daq::checkErrorInfo(errCode);

        return inputPort;
    }


    /*!
     * @brief Gets the number of samples available in the queued packets.
     * The returned value ignores any Sample-Descriptor changes.

     * @returns The total amount of samples currently available in the stored packets.
     */
    daq::SizeT getAvailableSamples() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT samples;
        auto errCode = this->object->getAvailableSamples(&samples);
        daq::checkErrorInfo(errCode);

        return samples;
    }


    /*!
     * @brief Gets the number of same-type samples available in the queued packets.
     * The returned value is up-to the next Sample-Descriptor-Changed packet if any.

     * @returns The total amount of same-type samples currently available in the stored packets.
     */
    daq::SizeT getSamplesUntilNextDescriptor() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::SizeT samples;
        auto errCode = this->object->getSamplesUntilNextDescriptor(&samples);
        daq::checkErrorInfo(errCode);

        return samples;
    }


    /*!
     * @brief Returns true if the type of connection is remote.

     * @returns True if connection is remote.
     * Remote connections do not pass any packets. They represent the connection between input ports and signals
     * on remote devices.
     */
    daq::Bool isRemote() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool remote;
        auto errCode = this->object->isRemote(&remote);
        daq::checkErrorInfo(errCode);

        return remote;
    }

#if __has_include(<cqdaq/connection_ptr.custom.h>)
    #include <cqdaq/connection_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ
