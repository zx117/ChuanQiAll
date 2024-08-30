
#pragma once
#include <cqdaq/allocator_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline AllocatorPtr MallocAllocator()
{
    AllocatorPtr obj(MallocAllocator_Create());
    return obj;
}

END_NAMESPACE_CQDAQ
