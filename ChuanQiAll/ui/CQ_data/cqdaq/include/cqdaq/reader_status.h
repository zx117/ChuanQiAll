
#pragma once
#include <cqdaq/event_packet.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_reader Reader status
 * @{
 */

enum class ReadStatus : uint32_t
{
    Ok = 0,
    Event,
    Fail,
    Unknown = 0xFFFF
};

/*#
  * [templated(defaultAliasName: ReaderStatusPtr)]
  * [interfaceSmartPtr(IReaderStatus, GenericReaderStatusPtr)]
  */
/*!
 * @brief Represents the status of the reading process returned by the reader::read function.
 *
 * The `IReaderStatus` class provides information about the outcome of the reading operation,
 * including the validity of the reader and the potential encounter of event packets during processing.
 * Objects of this class are typically returned as a result of the `read` function of the Readers,
 * allowing the client code to assess and respond to the status of the reading process.
 */
DECLARE_CQDAQ_INTERFACE(IReaderStatus, IBaseObject)
{
    /*!
     * @brief Retrieves the current reading status, indicating whether the reading process is in an "Ok" state,
     * has encountered an Event, has failed, or is in an Unknown state.
     * @param[out] status  a ReadStatus enum variable where the current reading status will be stored.
     */
    virtual ErrCode INTERFACE_FUNC getReadStatus(ReadStatus* status) = 0;

    /*!
     * @brief Retrieves the event packet from the reading process.
     * @param[out] packet The event packet from the reading process.
     */
    virtual ErrCode INTERFACE_FUNC getEventPacket(IEventPacket** packet) = 0;

    /*!
     * @brief Checks the validity of the reader.
     * @param[out] status Boolean value indicating the validity of the reader
     */
    virtual ErrCode INTERFACE_FUNC getValid(Bool* valid) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY (
    LIBRARY_FACTORY, ReaderStatus,
    IEventPacket*, eventPacket,
    Bool, valid
)

END_NAMESPACE_CQDAQ
