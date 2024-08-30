
#pragma once
#include <cqdaq/context.h>
#include <cqdaq/module_manager.h>
#include <coretypes/common.h>
#include <coretypes/stringobject.h>

#if __cplusplus
    #define EXPORT_C extern "C"
#else
    #define EXPORT_C
#endif

#if !defined(_WIN32)
    #define CQDAQ_MODULE_API EXPORT_C __attribute__ ((visibility("default")))
#elif defined(CQDAQ_MODULE_EXPORTS)
    #define CQDAQ_MODULE_API EXPORT_C __declspec(dllexport)
#else
    #define CQDAQ_MODULE_API EXPORT_C __declspec(dllimport)
#endif

#define DECLARE_MODULE_EXPORTS_WITHOUT_ID() \
    CQDAQ_MODULE_API daq::ErrCode createModule(daq::IModule** module, daq::IContext* context);     \
    CQDAQ_MODULE_API daq::ErrCode daqGetObjectCount(daq::SizeT* objCount);                         \
    CQDAQ_MODULE_API daq::ErrCode checkDependencies(daq::IString** errMsg);                        \
                                                                                                                                 
#define DECLARE_MODULE_EXPORTS(moduleId)                                                             \
    DECLARE_MODULE_EXPORTS_WITHOUT_ID()                                                              \
    CQDAQ_MODULE_API daq::ErrCode create##moduleId(daq::IModule** module, daq::IContext* context); \

