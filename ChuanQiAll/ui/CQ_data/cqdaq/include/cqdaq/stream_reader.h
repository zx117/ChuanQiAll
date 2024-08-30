
#pragma once
#include <cqdaq/sample_reader.h>
#include <cqdaq/signal.h>
#include <cqdaq/input_port_config.h>
#include <cqdaq/reader_status.h>

BEGIN_NAMESPACE_CQDAQ

struct IInputPort;

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_stream_reader Stream reader
 * @{
 */

/*#
 * [include(IReader)]
 * [include(ISampleType)]
 * [interfaceSmartPtr(ISampleReader, GenericSampleReaderPtr)]
 */

/*!
 * @brief A signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.
 * @remark Currently only supports scalar sample-types and RangeInt64
 */
DECLARE_CQDAQ_INTERFACE(IStreamReader, ISampleReader)
{
    // [arrayArg(values, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` unread samples to the values buffer.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] samples The buffer that the samples will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of samples.
     * @param[in,out] count The maximum amount of samples to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * samples are returned. The rest of the buffer is not modified or cleared.
     * @param timeoutMs The maximum amount of time in milliseconds to wait for the requested amount of samples before returning.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::getReadStatus returns ReadStatus::Event
     * - If the reading process is successful, IReaderStatus::getReadStatu returns ReadStatus::Ok, indicating that IReaderStatus::getValid is true and there is no encountered events
     */
    virtual ErrCode INTERFACE_FUNC read(void* samples, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) = 0;

    // [arrayArg(samples, count), arrayArg(domain, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` unread samples and clock-stamps to the `samples` and `domain` buffers.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] samples The buffer that the samples will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of samples.
     * @param[in] domain The buffer that the domain values will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of clock-stamps.
     * @param[in,out] count The maximum amount of samples to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * samples are returned. The rest of the buffer is not modified or cleared.
     * @param timeoutMs The maximum amount of time in milliseconds to wait for the requested amount of samples before returning.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::getReadStatus returns ReadStatus::Event
     * - If the reading process is successful, IReaderStatus::getReadStatu returns ReadStatus::Ok, indicating that IReaderStatus::getValid is true and there is no encountered events
     */
    virtual ErrCode INTERFACE_FUNC readWithDomain(void* samples, void* domain, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) = 0;
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, StreamReader, IStreamReader,
    ISignal*, signal,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, mode,
    ReadTimeoutType, timeoutType
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, StreamReaderFromPort ,IStreamReader,
    IInputPortConfig*, port,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, readMode,
    ReadTimeoutType, timeoutType
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, StreamReaderFromExisting, IStreamReader,
    IStreamReader*, invalidatedReader,
    SampleType, valueReadType,
    SampleType, domainReadType
)

END_NAMESPACE_CQDAQ
