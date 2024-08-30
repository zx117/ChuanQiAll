
#pragma once
#include <cqdaq/packet.h>
#include <cqdaq/reader.h>
#include <coretypes/listobject.h>
#include <cqdaq/signal.h>
#include <cqdaq/input_port_config.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [templated(IReader)]
 * [interfaceSmartPtr(IReader, GenericReaderPtr)]
 */

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_packet_reader Packet reader
 * @{
 */

/*!
 * @brief A signal reader reads packets from a signal data stream.
 */
DECLARE_CQDAQ_INTERFACE(IPacketReader, IReader)
{
    /*!
     * @brief Retrieves the next available packet in the data-stream.
     * @param[out] packet The next available packet or @c nullptr if not are available.
     */
    virtual ErrCode INTERFACE_FUNC read(IPacket** packet) = 0;

    // [elementType(packets, IPacket)]
    /*!
     * @brief Retrieves all the currently available packets in the data-stream.
     * @param[out] packets The currently available packets or an empty list.
     */
    virtual ErrCode INTERFACE_FUNC readAll(IList** packets) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, PacketReader,
    ISignal*, signal
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, PacketReaderFromPort, IPacketReader,
    IInputPortConfig*, port
)

END_NAMESPACE_CQDAQ
