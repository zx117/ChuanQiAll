#pragma once
#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

// Has to be extern "C" so that if we have DLL and Runner compiled with different compilers it still works (as name mangling is different)

extern "C"
ErrCode PUBLIC_EXPORT daqInitializeCoreObjectsTesting();

END_NAMESPACE_CQDAQ
