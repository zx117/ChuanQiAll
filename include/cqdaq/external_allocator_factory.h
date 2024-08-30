
#pragma once
#include <cqdaq/allocator_ptr.h>
#include <cqdaq/deleter_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline AllocatorPtr ExternalAllocator(void* data, const DeleterPtr& deleter)
{
    AllocatorPtr obj(ExternalAllocator_Create(data, deleter));
    return obj;
}

END_NAMESPACE_CQDAQ
