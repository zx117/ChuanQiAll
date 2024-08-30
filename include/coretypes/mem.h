
#pragma once

#include <coretypes/common.h>

extern "C"
PUBLIC_EXPORT void* daqAllocateMemory(size_t len);

extern "C"
PUBLIC_EXPORT void daqFreeMemory(void* ptr);
