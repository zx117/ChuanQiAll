
#pragma once
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/deleter_ptr.h>
#include <cqdaq/generic_data_packet_impl.h>

BEGIN_NAMESPACE_CQDAQ

template <bool ExternalMemory>
struct BinaryDataDeleter
{
};

template <>
struct BinaryDataDeleter<true>
{
    void operator()(void* data)
    {
        deleter.deleteMemory(data);
    }

    DeleterPtr deleter;
};

template <>
struct BinaryDataDeleter<false>
{
    void operator()(void* data)
    {
        std::free(data);
    }
};

template <bool ExternalMemory>
class BinaryDataPacketImpl : public GenericDataPacketImpl<IDataPacket>
{
public:
    template <bool B = ExternalMemory, std::enable_if_t<!B, int> = 0>
    explicit BinaryDataPacketImpl(const DataPacketPtr& domainPacket, const DataDescriptorPtr& dataDescriptor, SizeT sampleSize);

    template <bool B = ExternalMemory, std::enable_if_t<B, int> = 0>
    explicit BinaryDataPacketImpl(const DataPacketPtr& domainPacket,
                                  const DataDescriptorPtr& dataDescriptor,
                                  SizeT sampleSize,
                                  void* data,
                                  const DeleterPtr& deleter);

    ErrCode INTERFACE_FUNC getDataDescriptor(IDataDescriptor** dataDescriptor) override;
    ErrCode INTERFACE_FUNC getSampleCount(SizeT* sampleCount) override;
    ErrCode INTERFACE_FUNC getOffset(INumber** offset) override;
    ErrCode INTERFACE_FUNC getRawData(void** address) override;
    ErrCode INTERFACE_FUNC getData(void** address) override;
    ErrCode INTERFACE_FUNC getDataSize(SizeT* dataSize) override;
    ErrCode INTERFACE_FUNC getRawDataSize(SizeT* dataSize) override;
    ErrCode INTERFACE_FUNC getLastValue(IBaseObject** value, ITypeManager* typeManager = nullptr) override;

private:
    DataPacketPtr domainPacket;
    DataDescriptorPtr dataDescriptor;
    SizeT sampleSize;
    std::unique_ptr<void, BinaryDataDeleter<ExternalMemory>> data;

#ifdef CQDAQ_ENABLE_PARAMETER_VALIDATION
    void validateDescriptor();
#endif
};

#ifdef CQDAQ_ENABLE_PARAMETER_VALIDATION
template <bool ExternalMemory>
void BinaryDataPacketImpl<ExternalMemory>::validateDescriptor()
{
    if (!dataDescriptor.assigned())
        throw ArgumentNullException();

    if (dataDescriptor.getSampleType() != SampleType::Binary)
        throw InvalidParameterException("Sample type is not Binary.");
}
#endif

template <bool ExternalMemory>
template <bool B, std::enable_if_t<!B, int>>
BinaryDataPacketImpl<ExternalMemory>::BinaryDataPacketImpl(const DataPacketPtr& domainPacket,
                                                           const DataDescriptorPtr& dataDescriptor,
                                                           SizeT sampleSize)
    : GenericDataPacketImpl<IDataPacket>(domainPacket)
    , dataDescriptor(dataDescriptor)
    , sampleSize(sampleSize)
    , data(std::malloc(sampleSize))
{
#ifdef CQDAQ_ENABLE_PARAMETER_VALIDATION
    validateDescriptor();
#endif
}

template <bool ExternalMemory>
template <bool B, std::enable_if_t<B, int>>
BinaryDataPacketImpl<ExternalMemory>::BinaryDataPacketImpl(
    const DataPacketPtr& domainPacket, const DataDescriptorPtr& dataDescriptor, SizeT sampleSize, void* data, const DeleterPtr& deleter)
    : GenericDataPacketImpl<IDataPacket>(domainPacket)
    , dataDescriptor(dataDescriptor)
    , sampleSize(sampleSize)
    , data(data, BinaryDataDeleter<true>{deleter})
{
#ifdef CQDAQ_ENABLE_PARAMETER_VALIDATION
    validateDescriptor();
    if (!this->data)
        throw InvalidParameterException("Data parameter must not be null.");
#endif
    type = PacketType::Data;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getDataDescriptor(IDataDescriptor** dataDescriptor)
{
    CQDAQ_PARAM_NOT_NULL(dataDescriptor);

    *dataDescriptor = this->dataDescriptor.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getSampleCount(SizeT* sampleCount)
{
    CQDAQ_PARAM_NOT_NULL(sampleCount);

    *sampleCount = 1;

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getRawData(void** address)
{
    CQDAQ_PARAM_NOT_NULL(address);

    *address = data.get();

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getData(void** address)
{
    CQDAQ_PARAM_NOT_NULL(address);

    *address = data.get();

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getDataSize(SizeT* dataSize)
{
    CQDAQ_PARAM_NOT_NULL(dataSize);

    *dataSize = this->sampleSize;

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getRawDataSize(SizeT* rawDataSize)
{
    CQDAQ_PARAM_NOT_NULL(rawDataSize);

    *rawDataSize = this->sampleSize;

    return CQDAQ_SUCCESS;
}

template <bool ExternalMemory>
inline ErrCode INTERFACE_FUNC BinaryDataPacketImpl<ExternalMemory>::getLastValue(IBaseObject** value, ITypeManager* typeManager)
{
    CQDAQ_PARAM_NOT_NULL(value);

    *value = nullptr;

    return CQDAQ_IGNORED;
}

template <bool ExternalMemory>
ErrCode BinaryDataPacketImpl<ExternalMemory>::getOffset(INumber** offset)
{
    CQDAQ_PARAM_NOT_NULL(offset);

    *offset = NumberPtr(0).detach();

    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
