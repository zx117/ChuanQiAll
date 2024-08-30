
#pragma once
#include <cqdaq/context.h>
#include <cqdaq/input_port.h>
#include <cqdaq/packet.h>
#include <cqdaq/signal.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceSmartPtr(IInputPort, ObjectPtr<IInputPort>, "")]
 * [interfaceSmartPtr(ISignal, ObjectPtr<ISignal>, "")]
 */

/*!
 * @ingroup cqdaq_signal_path
 * @addtogroup cqdaq_connection Connection
 * @{
 */

/*!
 * @brief Represents a connection between an Input port and Signal. Acts as a queue
 * for packets sent by the signal, which can be read by the input port and the input port's
 * owner.
 *
 * The Connection provides standard queue methods, allowing for packets to be put at the back
 * of the queue, and popped from the front. Additionally, the front packet can be inspected via
 * `peek`, and the number of queued packets can be obtained through `getPacketCount`.
 *
 * The Connection has a reference to the connected Signal and Input port.
 */
DECLARE_CQDAQ_INTERFACE(IConnection, IBaseObject)
{
    /*!
     * @brief Places a packet at the back of the queue.
     * @param packet The packet to be enqueued.
     */
    virtual ErrCode INTERFACE_FUNC enqueue(IPacket* packet) = 0;

    /*!
     * @brief Places a packet at the back of the queue.
     * @param packet The packet to be enqueued.
     *
     * The connection notifies the listener on the same thread that this method was called.
     */
    virtual ErrCode INTERFACE_FUNC enqueueOnThisThread(IPacket * packet) = 0;

    /*!
     * @brief Removes the packet at the front of the queue and returns it.
     * @param[out] packet The removed packet or @c nullptr if the connection has no packets.
     * @retval CQDAQ_NO_MORE_ITEMS When the connection does not hold any packets.
     */
    virtual ErrCode INTERFACE_FUNC dequeue(IPacket** packet) = 0;

    /*!
     * @brief Returns the packet at the front of the queue without removing it.
     * @param[out] packet The packet at the front of the queue or @c nullptr if the connection has no packets.
     * @retval CQDAQ_NO_MORE_ITEMS When the connection does not hold any packets.
     */
    virtual ErrCode INTERFACE_FUNC peek(IPacket** packet) = 0;

    /*!
     * @brief Gets the number of queued packets.
     * @param[out] packetCount The number of queued packets.
     */
    virtual ErrCode INTERFACE_FUNC getPacketCount(SizeT* packetCount) = 0;

    /*!
     * @brief Gets the Signal that is sending packets through the Connection.
     * @param[out] signal The Signal.
     */
    virtual ErrCode INTERFACE_FUNC getSignal(ISignal** signal) = 0;

    /*!
     * @brief Gets the Input port to which packets are being sent.
     * @param[out] inputPort The input port.
     */
    virtual ErrCode INTERFACE_FUNC getInputPort(IInputPort** inputPort) = 0;

    /*!
     * @brief Gets the number of samples available in the queued packets.
     * The returned value ignores any Sample-Descriptor changes.
     * @param[out] samples The total amount of samples currently available in the stored packets.
     */
    virtual ErrCode INTERFACE_FUNC getAvailableSamples(SizeT* samples) = 0;

    /*!
     * @brief Gets the number of same-type samples available in the queued packets.
     * The returned value is up-to the next Sample-Descriptor-Changed packet if any.
     * @param[out] samples The total amount of same-type samples currently available in the stored packets.
     */
    virtual ErrCode INTERFACE_FUNC getSamplesUntilNextDescriptor(SizeT* samples) = 0;

    /*!
     * @brief Returns true if the type of connection is remote.
     * @param[out] remote True if connection is remote.
     *
     * Remote connections do not pass any packets. They represent the connection between input ports and signals
     * on remote devices.
     */
    virtual ErrCode INTERFACE_FUNC isRemote(Bool* remote) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, Connection,
    IInputPort*, inputPort,
    ISignal*, signal,
    IContext*, context
)

END_NAMESPACE_CQDAQ
