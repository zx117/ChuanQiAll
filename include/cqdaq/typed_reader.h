
#pragma once
#include <cqdaq/sample_type_traits.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/reader_domain_info.h>
#include <cqdaq/sample_reader.h>

BEGIN_NAMESPACE_CQDAQ

class Comparable;

class Reader
{
public:
    explicit Reader(FunctionPtr transform);
    virtual ~Reader() = default;

    virtual ErrCode readData(void* inputBuffer, SizeT offset, void** outputBuffer, SizeT count) = 0;
    virtual std::unique_ptr<Comparable> readStart(void* inputBuffer, SizeT offset, const ReaderDomainInfo& domainInfo) = 0;
    
    virtual SizeT getOffsetTo(const ReaderDomainInfo& domainInfo, const Comparable& start, void* inputBuffer, SizeT size) = 0;
    virtual bool handleDescriptorChanged(DataDescriptorPtr& descriptor, ReadMode mode) = 0;

    [[nodiscard]] virtual bool isUndefined() const noexcept;
    [[nodiscard]] virtual SampleType getReadType() const noexcept = 0;

    FunctionPtr getTransformFunction() const;
    void setTransformFunction(FunctionPtr transform);

    void setTransformIgnore(bool ignore);

protected:
    bool ignoreTransform;
    FunctionPtr transformFunction;
    DataDescriptorPtr dataDescriptor;
    SampleType dataSampleType{SampleType::Undefined};
};

class UndefinedReader final : public Reader
{
public:
    using Reader::Reader;

    ErrCode readData(void* inputBuffer, SizeT offset, void** outputBuffer, SizeT count) override
    {
        return CQDAQ_ERR_INVALIDSTATE;
    }

    virtual std::unique_ptr<Comparable> readStart(void* inputBuffer, SizeT offset, const ReaderDomainInfo& domainInfo) override
    {
        throw InvalidStateException();
    }

    SizeT getOffsetTo(const ReaderDomainInfo& domainInfo, const Comparable& start, void* inputBuffer, SizeT size) override
    {
        throw InvalidStateException();
    }

    virtual bool handleDescriptorChanged(DataDescriptorPtr& descriptor, ReadMode mode) override
    {
        return false;
    }

    [[nodiscard]]
    bool isUndefined() const noexcept override
    {
        return true;
    }

    [[nodiscard]]
    SampleType getReadType() const noexcept override
    {
        return SampleType::Invalid;
    }
};

template <typename ReadType>
class TypedReader : public Reader
{
public:
    using Reader::Reader;

    virtual ErrCode readData(void* inputBuffer, SizeT offset, void** outputBuffer, SizeT count) override;
    virtual std::unique_ptr<Comparable> readStart(void* inputBuffer, SizeT offset, const ReaderDomainInfo& domainInfo) override;

    virtual SizeT getOffsetTo(const ReaderDomainInfo& domainInfo, const Comparable& start, void* inputBuffer, SizeT size) override;

    virtual bool handleDescriptorChanged(DataDescriptorPtr& descriptor, ReadMode mode) override;

    virtual SampleType getReadType() const noexcept override;
private:
    template <typename TDataType>
    ErrCode readValues(void* inputBuffer, SizeT offset, void** outputBuffer, SizeT toRead) const;

    template <typename TDataType>
    SizeT getOffsetToData(const ReaderDomainInfo& domainInfo, const Comparable& start, void* inputBuffer, SizeT size) const;

    SizeT valuesPerSample{1};

    SizeT rawSampleSize{0};
};

std::unique_ptr<Reader> createReaderForType(SampleType readType, const FunctionPtr& transformFunction);

extern template class TypedReader<SampleTypeToType<SampleType::Float32>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Float64>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::UInt8>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Int8>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::UInt16>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Int16>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::UInt32>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Int32>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Int64>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::RangeInt64>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::ComplexFloat32>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::ComplexFloat64>::Type>;
extern template class TypedReader<SampleTypeToType<SampleType::Struct>::Type>;

END_NAMESPACE_CQDAQ