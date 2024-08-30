#pragma once

#define CQDAQ_COREOBJECTS_MAJOR_VERSION    1u
#define CQDAQ_COREOBJECTS_MINOR_VERSION    0u
#define CQDAQ_COREOBJECTS_PATCH_VERSION    0u

#if defined(_MSC_VER) && !defined(CQDAQ_SKIP_LIB_LINK)
    #ifdef _WIN64
        #ifndef NDEBUG
            #pragma comment(lib, "daqcoreobjects-64-1-debug.lib")
        #else
            #pragma comment(lib, "daqcoreobjects-64-1.lib")
        #endif
    #else
        #ifndef NDEBUG
            #pragma comment(lib, "daqcoreobjects-32-1-debug.lib")
        #else
            #pragma comment(lib, "daqcoreobjects-32-1.lib")
        #endif
    #endif
#endif
