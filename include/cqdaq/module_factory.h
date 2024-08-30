
#pragma once
#include <coretypes/version.h>
#include <coretypes/coretypes_config.h>

#if defined(CQDAQ_LINKS_CORE_OBJECTS)
    #include <coreobjects/version.h>
    #include <coreobjects/coreobjects_config.h>
#endif

#if defined(CQDAQ_LINKS_CQDAQ)
    #include <cqdaq/version.h>
    #include <cqdaq/cqdaq_config.h>
    #include <cqdaq/module_manager_errors.h>
    #include <cqdaq/module_check_dependencies.h>
#endif

#define DEFINE_MODULE_EXPORTS(moduleImpl)                                               \
    std::atomic<std::size_t> daq::daqSharedLibObjectCount(0);                           \
                                                                                        \
    CQDAQ_MODULE_API daq::ErrCode createModule(daq::IModule** module,                 \
                                                daq::IContext* context)                 \
    {                                                                                   \
        return daq::createObject<daq::IModule, moduleImpl>(                             \
            module,                                                                     \
            context                                                                     \
        );                                                                              \
    }                                                                                   \
                                                                                        \
    CQDAQ_MODULE_API daq::ErrCode create##moduleImpl(daq::IModule** module,           \
                                                      daq::IContext* context)           \
    {                                                                                   \
        return daq::createObject<daq::IModule, moduleImpl>(                             \
            module,                                                                     \
            context                                                                     \
        );                                                                              \
    }                                                                                   \
                                                                                        \
    CQDAQ_MODULE_API daq::ErrCode daqGetObjectCount(daq::SizeT* count)                \
    {                                                                                   \
        *count = daq::daqSharedLibObjectCount;                                          \
        return CQDAQ_SUCCESS;                                                         \
    }

// ReSharper disable once CppNonInlineFunctionDefinitionInHeaderFile
CQDAQ_MODULE_API daq::ErrCode checkDependencies(daq::IString** errMsg)
{
#if defined(CQDAQ_LINKS_CORE_OBJECTS)
    daq::LibraryVersion version{
        CQDAQ_CORETYPES_MAJOR_VERSION,
        CQDAQ_CORETYPES_MINOR_VERSION,
        CQDAQ_CORETYPES_PATCH_VERSION,
    };

    if (!isCompatibleVersion("CoreTypes", daqCoreTypesGetVersion, version, errMsg))
    {
        return CQDAQ_ERR_MODULE_INCOMPATIBLE_DEPENDENCIES;
    }

    version.major = CQDAQ_COREOBJECTS_MAJOR_VERSION;
    version.minor = CQDAQ_COREOBJECTS_MINOR_VERSION;
    version.patch = CQDAQ_COREOBJECTS_PATCH_VERSION;
    if (!isCompatibleVersion("CoreObjects", daqCoreObjectsGetVersion, version, errMsg))
    {
        return CQDAQ_ERR_MODULE_INCOMPATIBLE_DEPENDENCIES;
    }
#endif

#if defined(CQDAQ_LINKS_CQDAQ)

    version.major = CQDAQ_CQDAQ_MAJOR_VERSION;
    version.minor = CQDAQ_CQDAQ_MINOR_VERSION;
    version.patch = CQDAQ_CQDAQ_PATCH_VERSION;
    if (!isCompatibleVersion("CqDaq", daqCqDaqGetVersion, version, errMsg))
    {
        return CQDAQ_ERR_MODULE_INCOMPATIBLE_DEPENDENCIES;
    }
#endif

    return CQDAQ_SUCCESS;
}
