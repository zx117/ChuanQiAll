
#pragma once
#include <cqdaq/multi_reader_builder.h>
#include <cqdaq/input_port_factory.h>

BEGIN_NAMESPACE_CQDAQ

class MultiReaderBuilderImpl : public ImplementationOf<IMultiReaderBuilder>
{
public:
    MultiReaderBuilderImpl();

    ErrCode INTERFACE_FUNC build(IMultiReader** multiReader) override;

    ErrCode INTERFACE_FUNC addSignal(ISignal* signal) override;
    ErrCode INTERFACE_FUNC addInputPort(IInputPort* port) override;
    ErrCode INTERFACE_FUNC getSourceComponents(IList** ports) override;
   
    ErrCode INTERFACE_FUNC setValueReadType(SampleType type) override;
    ErrCode INTERFACE_FUNC getValueReadType(SampleType* type) override;

    ErrCode INTERFACE_FUNC setDomainReadType(SampleType type) override;
    ErrCode INTERFACE_FUNC getDomainReadType(SampleType* type) override;

    ErrCode INTERFACE_FUNC setReadMode(ReadMode mode) override;
    ErrCode INTERFACE_FUNC getReadMode(ReadMode* mode) override;

    ErrCode INTERFACE_FUNC setReadTimeoutType(ReadTimeoutType type) override;
    ErrCode INTERFACE_FUNC getReadTimeoutType(ReadTimeoutType* type) override;

    ErrCode INTERFACE_FUNC setRequiredCommonSampleRate(Int sampleRate) override;
    ErrCode INTERFACE_FUNC getRequiredCommonSampleRate(Int* sampleRate) override;

    ErrCode INTERFACE_FUNC setStartOnFullUnitOfDomain(Bool enabled) override;
    ErrCode INTERFACE_FUNC getStartOnFullUnitOfDomain(Bool* enabled) override;

private:
    ListPtr<IComponent> sources;
    SampleType valueReadType;
    SampleType domainReadType;
    ReadMode readMode;
    ReadTimeoutType readTimeoutType;
    Int requiredCommonSampleRate;
    Bool startOnFullUnitOfDomain;
};

END_NAMESPACE_CQDAQ
