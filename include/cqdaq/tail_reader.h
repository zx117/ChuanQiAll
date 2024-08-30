
#pragma once
#include <cqdaq/sample_reader.h>
#include <cqdaq/signal.h>
#include <cqdaq/input_port_config.h>
#include <cqdaq/reader_status.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_tail_reader Tail reader
 * @{
 */

/*#
 * [include(ISampleType)]
 * [interfaceSmartPtr(ISampleReader, GenericSampleReaderPtr)]
 */

/*!
 * @brief A reader that only ever reads the last N samples, subsequent calls may result in overlapping data.
 */
DECLARE_CQDAQ_INTERFACE(ITailReader, ISampleReader)
{
    // [arrayArg(values, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` unread samples to the values buffer.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] values The buffer that the samples will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of samples.
     * @param[in,out] count The maximum amount of samples to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * samples are returned. The rest of the buffer is not modified or cleared.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::getReadStatus returns ReadStatus::Event
     * - If the reading process is successful, IReaderStatus::getReadStatu returns ReadStatus::Ok, indicating that IReaderStatus::getValid is true and there is no encountered events
     */
    virtual ErrCode INTERFACE_FUNC read(void* values, SizeT* count, IReaderStatus** status = nullptr) = 0;

    // [arrayArg(values, count), arrayArg(domain, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` unread samples and clock-stamps to the `values` and `stamps` buffers.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] values The buffer that the data values will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of samples.
     * @param[in] domain The buffer that the domain values will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` amount of clock-stamps.
     * @param[in,out] count The maximum amount of samples to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * samples are returned. The rest of the buffer is not modified or cleared.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::getReadStatus returns ReadStatus::Event
     * - If the reading process is successful, IReaderStatus::getReadStatu returns ReadStatus::Ok, indicating that IReaderStatus::getValid is true and there is no encountered events
     */
    virtual ErrCode INTERFACE_FUNC readWithDomain(void* values, void* domain, SizeT* count, IReaderStatus** status = nullptr) = 0;

    /*!
     * @brief The maximum amount of samples in history to keep.
     * @param[out] size The history size.
     */
    virtual ErrCode INTERFACE_FUNC getHistorySize(SizeT* size) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, TailReader,
    ISignal*, signal,
    SizeT, historySize,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, mode
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, TailReaderFromPort, ITailReader,
    IInputPortConfig*, port,
    SizeT, historySize,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, mode
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, TailReaderFromExisting, ITailReader,
    ITailReader*, invalidatedReader,
    SizeT, historySize,
    SampleType, valueReadType,
    SampleType, domainReadType
)

END_NAMESPACE_CQDAQ
