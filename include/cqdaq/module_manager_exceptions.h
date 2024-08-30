
#pragma once
#include <cqdaq/module_manager_errors.h>
#include <coretypes/exceptions.h>

BEGIN_NAMESPACE_CQDAQ

class ModuleManagerException : public DaqException
{
public:
    using DaqException::DaqException;
};

#define DEFINE_MODULE_MANAGER_EXCEPTION(excName, errCode, excMsg) DEFINE_EXCEPTION_BASE(daq::ModuleManagerException, excName, errCode, excMsg)

/*
 * Should be in the order of the error's numerical value
 */
DEFINE_MODULE_MANAGER_EXCEPTION(ModuleManagerUnknown, CQDAQ_ERR_MODULE_MANAGER_UNKNOWN, "Unknown module-manager exception")
DEFINE_MODULE_MANAGER_EXCEPTION(ModuleLoadFailed, CQDAQ_ERR_MODULE_LOAD_FAILED, "Module failed to load")
DEFINE_MODULE_MANAGER_EXCEPTION(ModuleNoEntryPoint, CQDAQ_ERR_MODULE_NO_ENTRY_POINT, "Module has no entry-point function to call")
DEFINE_MODULE_MANAGER_EXCEPTION(ModuleEntryPointFailed, CQDAQ_ERR_MODULE_ENTRY_POINT_FAILED, "Module entry-point function call failed")
DEFINE_MODULE_MANAGER_EXCEPTION(ModuleIncompatibleDependencies, CQDAQ_ERR_MODULE_INCOMPATIBLE_DEPENDENCIES, "Module has incompatible dependencies")

END_NAMESPACE_CQDAQ
