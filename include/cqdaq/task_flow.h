
#pragma once
#if defined(_MSC_VER)
    #ifdef _MSC_VER
        #pragma warning(push)
        #pragma warning(disable : 4456)  // hides previous local declaration
    #endif
#endif

#include <taskflow/taskflow.hpp>

#ifdef _MSC_VER
    #pragma warning(pop)
#endif
