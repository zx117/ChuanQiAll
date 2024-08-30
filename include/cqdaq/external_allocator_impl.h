
#pragma once
#include <cqdaq/allocator.h>
#include <cqdaq/data_descriptor.h>
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <cqdaq/deleter_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ExternalAllocatorImpl : public ImplementationOf<IAllocator>
{
public:
    explicit ExternalAllocatorImpl(void* data, const DeleterPtr& deleter);

    ErrCode INTERFACE_FUNC allocate(
        const IDataDescriptor *descriptor,
        daq::SizeT bytes,
        daq::SizeT align,
        VoidPtr* address) override;

    ErrCode INTERFACE_FUNC free(VoidPtr address) override;

private:
    void* data;
    DeleterPtr deleter;

    bool allocated;
    bool deleted;
};

END_NAMESPACE_CQDAQ
