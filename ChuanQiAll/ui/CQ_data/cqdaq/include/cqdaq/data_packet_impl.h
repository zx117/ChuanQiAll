
#pragma once
#include <coretypes/intfs.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/data_rule_calc_private.h>
#include <cqdaq/generic_data_packet_impl.h>
#include <cqdaq/range_factory.h>
#include <cqdaq/sample_type_traits.h>
#include <cqdaq/scaling_calc_private.h>
#include <cqdaq/signal_exceptions.h>
#include <cqdaq/deleter_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TInterface = IDataPacket>
class DataPacketImpl : public GenericDataPacketImpl<TInterface>
{
public:
    using Super = PacketImpl<TInterface>;

    explicit DataPacketImpl(const DataPacketPtr& domainPacket,
                            const DataDescriptorPtr& descriptor,
                            SizeT sampleCount,
                            const NumberPtr& offset);

    explicit DataPacketImpl(const DataDescriptorPtr& descriptor,
                            SizeT sampleCount,
                            const NumberPtr& offset);

    explicit DataPacketImpl(const DataPacketPtr& domainPacket,
                            const DataDescriptorPtr& descriptor,
                            SizeT sampleCount,
                            const NumberPtr& offset,
                            void* externalMemory,
                            const DeleterPtr& deleter,
                            SizeT bufferSize = std::numeric_limits<SizeT>::max());

    explicit DataPacketImpl(const DataPacketPtr& domainPacket,
                            const DataDescriptorPtr& descriptor,
                            SizeT sampleCount,
                            void* initialValue,
                            void* otherValues,
                            SizeT otherValueCount);

    ~DataPacketImpl() override;

    ErrCode INTERFACE_FUNC getDataDescriptor(IDataDescriptor** descriptor) override;
    ErrCode INTERFACE_FUNC getSampleCount(SizeT* sampleCount) override;
    ErrCode INTERFACE_FUNC getOffset(INumber** offset) override;
    ErrCode INTERFACE_FUNC getRawData(void** address) override;
    ErrCode INTERFACE_FUNC getData(void** address) override;
    ErrCode INTERFACE_FUNC getDataSize(SizeT* dataSize) override;
    ErrCode INTERFACE_FUNC getRawDataSize(SizeT* rawDataSize) override;
    ErrCode INTERFACE_FUNC getLastValue(IBaseObject** value, ITypeManager* typeManager = nullptr) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

private:
    bool isDataEqual(const DataPacketPtr& dataPacket) const;
    BaseObjectPtr dataToObj(void* addr, const SampleType& type) const;
    BaseObjectPtr dataToObjAndIncreaseAddr(void*& addr, const SampleType& sampleType) const;
    StructPtr buildStructFromFields(const DataDescriptorPtr& descriptor, const TypeManagerPtr& typeManager, void*& addr) const;
    BaseObjectPtr buildFromDescriptor(void*& addr, const DataDescriptorPtr& descriptor, const TypeManagerPtr& typeManager) const;

    DeleterPtr deleter;
    DataDescriptorPtr descriptor;
    SizeT sampleCount;
    NumberPtr offset = nullptr;
    SizeT sampleSize, dataSize;
    SizeT rawSampleSize, rawDataSize;

    void* data;
    void* scaledData;

    std::mutex readLock;

    bool hasScalingCalc;
    bool hasDataRuleCalc;
    bool hasRawDataOnly;
    bool externalMemory;
};

template <typename TInterface>
DataPacketImpl<TInterface>::DataPacketImpl(const DataPacketPtr& domainPacket,
                                           const DataDescriptorPtr& descriptor,
                                           SizeT sampleCount,
                                           const NumberPtr& offset)
    : GenericDataPacketImpl<TInterface>(domainPacket)
    , descriptor(descriptor)
    , sampleCount(sampleCount)
    , offset(offset)
    , hasScalingCalc(false)
    , hasDataRuleCalc(false)
    , hasRawDataOnly(true)
    , externalMemory(false)
{
    scaledData = nullptr;
    data = nullptr;

    if (!descriptor.assigned())
        throw ArgumentNullException("Data descriptor in packet is null.");

    sampleSize = descriptor.getSampleSize();
    rawSampleSize = descriptor.getRawSampleSize();
    dataSize = sampleCount * sampleSize;
    rawDataSize = sampleCount * rawSampleSize;

    if (rawDataSize > 0)
    {
        data = std::malloc(rawDataSize);

        if (data == nullptr)
            throw NoMemoryException();
    }

    if (descriptor.getSampleType() == SampleType::Struct && rawSampleSize != sampleSize)
        throw InvalidParameterException("Packets with struct implicit descriptor not supported");

    const auto ruleType = descriptor.getRule().getType();

    if (ruleType == DataRuleType::Constant || (ruleType == DataRuleType::Linear && this->offset.assigned()))
        hasDataRuleCalc = descriptor.asPtr<IDataRuleCalcPrivate>(false)->hasDataRuleCalc();

    hasScalingCalc = descriptor.asPtr<IScalingCalcPrivate>(false)->hasScalingCalc();

    hasRawDataOnly = !hasScalingCalc && !hasDataRuleCalc;
}

template <typename TInterface>
DataPacketImpl<TInterface>::DataPacketImpl(const DataPacketPtr& domainPacket,
                                           const DataDescriptorPtr& descriptor,
                                           SizeT sampleCount,
                                           const NumberPtr& offset,
                                           void* externalMemory,
                                           const DeleterPtr& deleter,
                                           SizeT bufferSize)
    : GenericDataPacketImpl<TInterface>(domainPacket)
    , deleter(deleter)
    , descriptor(descriptor)
    , sampleCount(sampleCount)
    , offset(offset)
    , hasScalingCalc(false)
    , hasDataRuleCalc(false)
    , hasRawDataOnly(true)
    , externalMemory(true)
{
    scaledData = nullptr;
    data = nullptr;

    if (!descriptor.assigned())
        throw ArgumentNullException("Data descriptor in packet is null.");

    if (!deleter.assigned())
        throw ArgumentNullException("Deleter must be assigned.");

    sampleSize = descriptor.getSampleSize();
    rawSampleSize = descriptor.getRawSampleSize();
    dataSize = sampleCount * sampleSize;

    if (bufferSize == std::numeric_limits<SizeT>::max())
        rawDataSize = sampleCount * rawSampleSize;
    else
        rawDataSize = bufferSize;

    data = externalMemory;

    if (descriptor.getSampleType() == SampleType::Struct && rawSampleSize != sampleSize)
        throw InvalidParameterException("Packets with struct implicit descriptor not supported");

    const auto ruleType = descriptor.getRule().getType();

    if (ruleType == DataRuleType::Constant || (ruleType == DataRuleType::Linear && this->offset.assigned()))
        hasDataRuleCalc = descriptor.asPtr<IDataRuleCalcPrivate>(false)->hasDataRuleCalc();

    hasScalingCalc = descriptor.asPtr<IScalingCalcPrivate>(false)->hasScalingCalc();

    hasRawDataOnly = !hasScalingCalc && !hasDataRuleCalc;
}

template <typename TInterface>
DataPacketImpl<TInterface>::DataPacketImpl(const DataDescriptorPtr& descriptor,
                                           SizeT sampleCount,
                                           const NumberPtr& offset)
    : DataPacketImpl<TInterface>(nullptr, descriptor, sampleCount, offset)
{
}

template <typename TInterface>
DataPacketImpl<TInterface>::DataPacketImpl(const DataPacketPtr& domainPacket,
                                           const DataDescriptorPtr& descriptor,
                                           SizeT sampleCount,
                                           void* initialValue,
                                           void* otherValues,
                                           SizeT otherValueCount)
    : GenericDataPacketImpl<TInterface>(domainPacket)
    , descriptor(descriptor)
    , sampleCount(sampleCount)
    , hasRawDataOnly(true)
    , externalMemory(false)
{
    scaledData = nullptr;
    data = nullptr;

    if (!descriptor.assigned())
        throw ArgumentNullException("Data descriptor in packet is null.");
    const auto ruleType = descriptor.getRule().getType();
    if (ruleType != DataRuleType::Constant)
        throw InvalidParameterException("Data rule must be constant.");

    sampleSize = descriptor.getSampleSize();
    dataSize = sampleCount * sampleSize;
    const auto structSize = sampleSize + sizeof(uint32_t);

    rawDataSize = sampleSize + structSize * otherValueCount;
    data = std::malloc(rawDataSize);
    std::memcpy(data, initialValue, sampleSize);
    if (otherValueCount > 0)
        std::memcpy(reinterpret_cast<uint8_t*>(data) + sampleSize, otherValues, otherValueCount * structSize);

    hasDataRuleCalc = true;
    hasScalingCalc = descriptor.asPtr<IScalingCalcPrivate>(false)->hasScalingCalc();
    if (hasScalingCalc)
        throw InvalidParameterException("Constant data rule with post scaling not supported.");
    hasRawDataOnly = false;
}

template <typename TInterface>
DataPacketImpl<TInterface>::~DataPacketImpl()
{
    if (externalMemory)
    {
        deleter.deleteMemory(data);
    }
    else
    {
        std::free(data);
    }
    std::free(scaledData);
}

template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getDataDescriptor(IDataDescriptor** descriptor)
{
    CQDAQ_PARAM_NOT_NULL(descriptor);

    *descriptor = this->descriptor.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getSampleCount(SizeT* sampleCount)
{
    CQDAQ_PARAM_NOT_NULL(sampleCount);

    *sampleCount = this->sampleCount;
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getOffset(INumber** offset)
{
    CQDAQ_PARAM_NOT_NULL(offset);

    *offset = this->offset.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getRawData(void** address)
{
    CQDAQ_PARAM_NOT_NULL(address);

    *address = data;
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getData(void** address)
{
    CQDAQ_PARAM_NOT_NULL(address);

    if (hasRawDataOnly)
    {
        *address = data;
        return CQDAQ_SUCCESS;
    }

    readLock.lock();

    if (scaledData)
    {
        *address = scaledData;
    }
    else
    {
        if (sampleCount == 0)
            *address = nullptr;
        else
            daqTry(
                [&]()
                {
                    if (hasScalingCalc)
                    {
                        scaledData = descriptor.asPtr<IScalingCalcPrivate>(false)->scaleData(data, sampleCount);
                    }
                    else if (hasDataRuleCalc)
                    {
                        scaledData = descriptor.asPtr<IDataRuleCalcPrivate>(false)->calculateRule(offset, sampleCount, data, rawDataSize);
                    }

                    *address = scaledData;
                    return CQDAQ_SUCCESS;
                });
    }

    readLock.unlock();
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode INTERFACE_FUNC DataPacketImpl<TInterface>::getDataSize(SizeT* dataSize)
{
    CQDAQ_PARAM_NOT_NULL(dataSize);

    *dataSize = this->dataSize;
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode INTERFACE_FUNC DataPacketImpl<TInterface>::getRawDataSize(SizeT* rawDataSize)
{
    CQDAQ_PARAM_NOT_NULL(rawDataSize);

    *rawDataSize = this->rawDataSize;
    return CQDAQ_SUCCESS;
}

template <typename TInterface>
ErrCode INTERFACE_FUNC DataPacketImpl<TInterface>::equals(IBaseObject* other, Bool* equals) const
{
    if (equals == nullptr)
        return this->makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equals out-parameter must not be null");

    *equals = false;
    if (other == nullptr)
        return CQDAQ_SUCCESS;

    return daqTry(
        [this, &other, &equals]()
        {
            ErrCode errCode = Super::equals(other, equals);
            checkErrorInfo(errCode);

            if (!(*equals))
                return errCode;

            *equals = false;
            const DataPacketPtr packetOther = BaseObjectPtr::Borrow(other).asPtrOrNull<IDataPacket>();
            if (packetOther == nullptr)
                return errCode;

            if (!BaseObjectPtr::Equals(this->domainPacket, packetOther.getDomainPacket()))
                return errCode;
            if (!BaseObjectPtr::Equals(this->descriptor, packetOther.getDataDescriptor()))
                return errCode;
            if (this->sampleCount != packetOther.getSampleCount())
                return errCode;
            if (this->offset != packetOther.getOffset())
                return errCode;
            if (!this->isDataEqual(packetOther))
                return errCode;

            *equals = true;
            return errCode;
        });
}

template <typename TInterface>
bool DataPacketImpl<TInterface>::isDataEqual(const DataPacketPtr& dataPacket) const
{
    if (rawDataSize != dataPacket.getRawDataSize())
    {
        if (descriptor.getRule().getType() == DataRuleType::Constant)
            return false;
        else
            throw InvalidSampleTypeException();
    }

    return data == dataPacket.getRawData() || std::memcmp(data, dataPacket.getRawData(), rawDataSize) == 0;
}

template <typename TInterface>
inline BaseObjectPtr DataPacketImpl<TInterface>::dataToObj(void* addr, const SampleType& type) const
{
    switch (type)
    {
        case SampleType::Float32:
        {
            const auto data = static_cast<float*>(addr);
            return Floating(*data);
        }
        case SampleType::Float64:
        {
            const auto data = static_cast<double*>(addr);
            return Floating(*data);
        }
        case SampleType::Int8:
        {
            const auto data = static_cast<int8_t*>(addr);
            return Integer(*data);
        }
        case SampleType::UInt8:
        {
            const auto data = static_cast<uint8_t*>(addr);
            return Integer(*data);
        }
        case SampleType::Int16:
        {
            const auto data = static_cast<int16_t*>(addr);
            return Integer(*data);
        }
        case SampleType::UInt16:
        {
            const auto data = static_cast<uint16_t*>(addr);
            return Integer(*data);
        }
        case SampleType::Int32:
        {
            const auto data = static_cast<int32_t*>(addr);
            return Integer(*data);
        }
        case SampleType::UInt32:
        {
            const auto data = static_cast<uint32_t*>(addr);
            return Integer(*data);
        }
        case SampleType::Int64:
        {
            const auto data = static_cast<int64_t*>(addr);
            return Integer(*data);
        }
        case SampleType::UInt64:
        {
            const auto data = static_cast<uint64_t*>(addr);
            return Integer(*data);
        }
        case SampleType::RangeInt64:
        {
            const auto data = static_cast<int64_t*>(addr);
            return Range(data[0], data[1]);
        }
        case SampleType::ComplexFloat32:
        {
            const auto data = static_cast<float*>(addr);
            return ComplexNumber(data[0], data[1]);
        }
        case SampleType::ComplexFloat64:
        {
            const auto data = static_cast<double*>(addr);
            return ComplexNumber(data[0], data[1]);
        }
        default:
        {
            return BaseObject();
        }
    }
}

template <typename TInterface>
inline BaseObjectPtr DataPacketImpl<TInterface>::dataToObjAndIncreaseAddr(void*& addr, const SampleType& sampleType) const
{
    const auto ptr = dataToObj(addr, sampleType);
    addr = static_cast<char*>(addr) + getSampleSize(sampleType);
    return ptr;
}

template <typename TInterface>
inline StructPtr DataPacketImpl<TInterface>::buildStructFromFields(const DataDescriptorPtr& descriptor,
                                                                   const TypeManagerPtr& typeManager,
                                                                   void*& addr) const
{
    const auto builder = StructBuilder(descriptor.getName(), typeManager);
    const auto fields = descriptor.getStructFields();
    for (const auto& field : fields)
    {
        const auto ptr = buildFromDescriptor(addr, field, typeManager);
        builder.set(field.getName(), ptr);
    }
    return builder.build();
}

template <typename TInterface>
inline BaseObjectPtr DataPacketImpl<TInterface>::buildFromDescriptor(void*& addr,
                                                                     const DataDescriptorPtr& descriptor,
                                                                     const TypeManagerPtr& typeManager) const
{
    const auto dimensions = descriptor.getDimensions();

    if (!dimensions.assigned())
        throw NotAssignedException{"Dimensions of data descriptor not assigned."};

    const auto dimensionCount = dimensions.getCount();

    if (dimensionCount > 1)
        throw NotSupportedException{"getLastValue on packets with dimensions supports only up to one dimension."};

    const auto sampleType = descriptor.getSampleType();

    if (dimensionCount == 1)
    {
        // List
        auto listPtr = List<IBaseObject>();
        const auto size = dimensions.getItemAt(0).getSize();

        for (size_t i = 0; i < size; i++)
        {
            if (sampleType == SampleType::Struct)
            {
                // Struct
                listPtr.pushBack(buildStructFromFields(descriptor, typeManager, addr));
            }
            else
            {
                // Not struct
                listPtr.pushBack(dataToObjAndIncreaseAddr(addr, sampleType));
            }
        }
        return listPtr;
    }
    else
    {
        // Not list
        if (sampleType == SampleType::Struct)
        {
            // Struct
            return buildStructFromFields(descriptor, typeManager, addr);
        }
        // Not struct
        return dataToObjAndIncreaseAddr(addr, sampleType);
    }
}
template <typename TInterface>
ErrCode DataPacketImpl<TInterface>::getLastValue(IBaseObject** value, ITypeManager* typeManager)
{
    CQDAQ_PARAM_NOT_NULL(value);

    const auto dimensionCount = descriptor.getDimensions().getCount();

    if (dimensionCount > 1)
        return CQDAQ_IGNORED;

    void* addr;
    ErrCode err = this->getData(&addr);
    if (CQDAQ_FAILED(err))
        return err;

    addr = static_cast<char*>(addr) + (sampleCount - 1) * descriptor.getSampleSize();

    return daqTry(
        [&]()
        {
            auto ptr = buildFromDescriptor(addr, descriptor, typeManager);
            *value = ptr.detach();
            return CQDAQ_SUCCESS;
        });
}

END_NAMESPACE_CQDAQ