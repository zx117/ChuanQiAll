
#pragma once
#include <coretypes/common.h>
#include <cqdaq/sample_type.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline daq::ErrCode getSignalSampleType(const daq::SignalPtr& signal, daq::SampleType* sampleType)
{
    if (!signal.assigned())
        return CQDAQ_ERR_ARGUMENT_NULL;

    DataDescriptorPtr descriptor;
    ErrCode errCode = signal->getDescriptor(&descriptor);
    if (CQDAQ_FAILED(errCode))
        return errCode;

    if (descriptor.isStructDescriptor())
    {
        return makeErrorInfo(CQDAQ_ERR_INVALIDTYPE, "Struct values are not supported", nullptr);
    }

    return descriptor->getSampleType(sampleType);
}

END_NAMESPACE_CQDAQ
