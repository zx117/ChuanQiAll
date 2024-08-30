
#pragma once
#include <cqdaq/allocator.h>
#include <cqdaq/data_descriptor.h>
#include <coretypes/common.h>
#include <coretypes/intfs.h>

BEGIN_NAMESPACE_CQDAQ

class MallocAllocatorImpl : public ImplementationOf<IAllocator>
{
public:
    ErrCode INTERFACE_FUNC allocate(
        const IDataDescriptor *descriptor,
        daq::SizeT bytes,
        daq::SizeT align,
        VoidPtr* address) override;

    ErrCode INTERFACE_FUNC free(VoidPtr address) override;
};

END_NAMESPACE_CQDAQ
