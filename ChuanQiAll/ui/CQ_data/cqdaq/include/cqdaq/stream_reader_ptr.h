//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:56:06.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/stream_reader.h"
#include <coretypes/span.h>
#include "sample_reader_ptr.h"
#include <cqdaq/sample_reader_ptr.h>
#include <cqdaq/reader_status_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class StreamReaderPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IStreamReader>
{
    using SmartPtr = daq::StreamReaderPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_stream_reader Stream reader
 * @{

 */


/*!
 * @brief A signal data reader that abstracts away reading of signal packets by keeping an
 * internal read-position and automatically advances it on subsequent reads.

 * @remark Currently only supports scalar sample-types and RangeInt64
 */

class StreamReaderPtr : public GenericSampleReaderPtr<IStreamReader>
{
public:
    using GenericSampleReaderPtr<IStreamReader>::GenericSampleReaderPtr;
    //using GenericSampleReaderPtr<IStreamReader>::operator=;



    StreamReaderPtr()
        : GenericSampleReaderPtr<IStreamReader>()

    {
    }

    StreamReaderPtr(daq::ObjectPtr<IStreamReader>&& ptr)
        : GenericSampleReaderPtr<IStreamReader>(std::move(ptr))

    {
    }

    StreamReaderPtr(const daq::ObjectPtr<IStreamReader>& ptr)
        : GenericSampleReaderPtr<IStreamReader>(ptr)

    {
    }

    StreamReaderPtr(const StreamReaderPtr& other)
        : GenericSampleReaderPtr<IStreamReader>(other)

    {
    }

    StreamReaderPtr(StreamReaderPtr&& other) noexcept
        : GenericSampleReaderPtr<IStreamReader>(std::move(other))

    {
    }
    
    StreamReaderPtr& operator=(const StreamReaderPtr& other)
    {
        if (this == &other)
            return *this;

        GenericSampleReaderPtr<IStreamReader>::operator =(other);


        return *this;
    }

    StreamReaderPtr& operator=(StreamReaderPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericSampleReaderPtr<IStreamReader>::operator =(std::move(other));

        return *this;
    }


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
    daq::ReaderStatusPtr read(void* samples, daq::SizeT* count, daq::SizeT timeoutMs = 0) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ReaderStatusPtr status;
        auto errCode = this->object->read(samples, count, timeoutMs, &status);
        daq::checkErrorInfo(errCode);

        return status;
    }


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
    daq::ReaderStatusPtr readWithDomain(void* samples, void* domain, daq::SizeT* count, daq::SizeT timeoutMs = 0) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::ReaderStatusPtr status;
        auto errCode = this->object->readWithDomain(samples, domain, count, timeoutMs, &status);
        daq::checkErrorInfo(errCode);

        return status;
    }

#if __has_include(<cqdaq/stream_reader_ptr.custom.h>)
    #include <cqdaq/stream_reader_ptr.custom.h>
#endif
};

END_NAMESPACE_CQDAQ