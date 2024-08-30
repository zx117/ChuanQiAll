
#pragma once

#include <cqdaq/boost_dll.h>

#include <cqdaq/context.h>
#include <cqdaq/logger_component_ptr.h>
#include <cqdaq/module_manager.h>
#include <cqdaq/module_ptr.h>
#include <coretypes/common.h>

    BEGIN_NAMESPACE_CQDAQ

struct ModuleLibrary
{
    boost::dll::shared_library handle;
    ModulePtr module;
};

ModuleLibrary loadModule(const LoggerComponentPtr& loggerComponent, const fs::path& path, IContext* context);

END_NAMESPACE_CQDAQ
