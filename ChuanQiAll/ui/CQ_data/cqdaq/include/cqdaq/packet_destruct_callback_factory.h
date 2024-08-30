
#pragma once
#include <cqdaq/packet_destruct_callback_ptr.h>
#include <cqdaq/packet_destruct_callback_impl.h>
#include <coretypes/objectptr.h>


BEGIN_NAMESPACE_CQDAQ
    /*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_packet Packet
 * @{
 */

/*!
 * @brief Creates packet destruct callback that is used to subscribe to packet destruction
 */
template <class Callback>
PacketDestructCallbackPtr PacketDestructCallback(Callback callback)
{
    auto obj = createWithImplementation<IPacketDestructCallback, PacketDestructCallbackImpl<Callback>>(callback);
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
