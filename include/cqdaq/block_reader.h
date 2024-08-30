
#pragma once
#include <cqdaq/sample_reader.h>
#include <cqdaq/signal.h>
#include <cqdaq/input_port_config.h>
#include <cqdaq/reader_status.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [include(ISampleType)]
 * [interfaceSmartPtr(ISampleReader, GenericSampleReaderPtr)]
 */

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_block_reader Block reader
 * @{
 */

/*!
 * @brief A signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads. The difference to
 * a StreamReader is that instead of reading on per sample basis it always returns only a full block of samples.
 * This means that even if more samples are available they will not be read until there is enough of them to fill
 * at least one block.
 * @remark Currently only supports single-dimensional scalar sample-types and RangeInt64
 */
DECLARE_CQDAQ_INTERFACE(IBlockReader, ISampleReader)
{
    // [arrayArg(blocks, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` blocks of unread samples to the values buffer.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] blocks The buffer that the samples will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` * `blockSize` amount of samples.
     * @param[in,out] count The maximum amount of blocks to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * blocks are returned. The rest of the buffer is not modified or cleared.
     * @param timeoutMs The maximum amount of time in milliseconds to wait for the requested amount of blocks before returning.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::isEventEncountered returns true.
     * - If the reading process is successful, ReaderStatus::isOk returns true, indicating that IReaderStatus::getValid is true and IReaderStatus::isEventEncountered is false.
     */
    virtual ErrCode INTERFACE_FUNC read(void* blocks, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) = 0;

    // [arrayArg(dataBlocks, count), arrayArg(domainBlocks, count), arrayArg(count, 1)]
    /*!
     * @brief Copies at maximum the next `count` blocks of unread samples and clock-stamps to the `dataBlocks` and `domainBlocks` buffers.
     * The amount actually read is returned through the `count` parameter.
     * @param[in] dataBlocks The buffer that the samples will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` * `blockSize` amount of samples.
     * @param[in] domainBlocks The buffer that the domain values will be copied to.
     * The buffer must be a contiguous memory big enough to receive `count` * `blockSize` amount of clock-stamps.
     * @param[in,out] count The maximum amount of blocks to be read. If the `count` is less than
     * available the parameter value is set to the actual amount and only the available
     * blocks are returned. The rest of the buffer is not modified or cleared.
     * @param timeoutMs The maximum amount of time in milliseconds to wait for the requested amount of blocks before returning.
     * @param[out] status: Represents the status of the reader.
     * - If the reader is invalid, IReaderStatus::getValid returns false.
     * - If an event packet was encountered during processing, IReaderStatus::isEventEncountered returns true.
     * - If the reading process is successful, ReaderStatus::isOk returns true, indicating that IReaderStatus::getValid is true and IReaderStatus::isEventEncountered is false.
     */
    virtual ErrCode INTERFACE_FUNC readWithDomain(void* dataBlocks, void* domainBlocks, SizeT* count, SizeT timeoutMs = 0, IReaderStatus** status = nullptr) = 0;

    /*!
     * @brief The amount of samples the reader considers as one block.
     * @param[out] size The number of samples in a block.
     */
    virtual ErrCode INTERFACE_FUNC getBlockSize(SizeT* size) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, BlockReader,
    ISignal*, signal,
    SizeT, blockSize,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, mode
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, BlockReaderFromExisting, IBlockReader,
    IBlockReader*, invalidatedReader,
    SampleType, valueReadType,
    SampleType, domainReadType,
    SizeT, blockSize
)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(
    LIBRARY_FACTORY, BlockReaderFromPort, IBlockReader,
    IInputPortConfig*, port,
    SizeT, blockSize,
    SampleType, valueReadType,
    SampleType, domainReadType,
    ReadMode, mode
)

END_NAMESPACE_CQDAQ
