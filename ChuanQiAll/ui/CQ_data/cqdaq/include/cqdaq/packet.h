
#pragma once
#include <cqdaq/allocator.h>
#include <cqdaq/packet_destruct_callback.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup cqdaq_packets
 * @{
 */
enum class PacketType
{
    None = 0, ///< Undefined packet type
    Data,     ///< Packet is a Data packet
    Event     ///< Packet is an Event packet
};
/*!@}*/

/*#
 * [templated(defaultAliasName: PacketPtr)]
 * [interfaceSmartPtr(IPacket, GenericPacketPtr)]
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
DECLARE_CQDAQ_INTERFACE(IPacket, IBaseObject)
{
    /*!
     * @brief Gets the packet's type.
     * @param[out] type The packet type.
     */
    virtual ErrCode INTERFACE_FUNC getType(PacketType* type) = 0;

    /*!
     * @brief Subscribes for notification when the packet is destroyed.
     * @param packetDestructCallback The callback that is called when the packet is destroyed.
     */
    virtual ErrCode INTERFACE_FUNC subscribeForDestructNotification(IPacketDestructCallback* packetDestructCallback) = 0;

    /*!
     * @brief Gets the reference count of the packet.
     * @param[out] refCount The reference count of the packet.
     */
    virtual ErrCode INTERFACE_FUNC getRefCount(SizeT* refCount) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
