
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_packets
 * @addtogroup cqdaq_packet Packet
 * @{
 */

/*!
 * @brief Used to subscribe to packet destruction
 */
DECLARE_CQDAQ_INTERFACE(IPacketDestructCallback, IBaseObject)
{
    /*!
     * @brief Called when packet is destroyed.
     */
    virtual ErrCode INTERFACE_FUNC onPacketDestroyed() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
