
#pragma once
#include <cqdaq/context_ptr.h>
#include <cqdaq/logger_factory.h>
#include <cqdaq/module_manager_ptr.h>
#include <coretypes/type_manager_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_context
 * @addtogroup cqdaq_context_factories Factories
 * @{
 */

/*!
 * @brief Creates a Context with the given Scheduler, Logger, Property Object Class Manager, and Module Manager.
 * @param scheduler The scheduler the context has access to.
 * @param logger The logger the context has access to.
 * @param moduleManager The module manager.
 * @param typeManager The type manager.
 */
inline ContextPtr Context(const SchedulerPtr& scheduler,
                          const LoggerPtr& logger,
                          const TypeManagerPtr& typeManager,
                          const ModuleManagerPtr& moduleManager,
                          const DictPtr<IString, IBaseObject> options = Dict<IString, IBaseObject>())
{
    ContextPtr obj(Context_Create(scheduler, logger, typeManager, moduleManager, options));
    return obj;
}

/*!
 * @brief Creates a Context with the given logger, type manager and options and all other parameters set to nullptr.
 * @param logger The logger the context has access to.
 * @param typeManager The type manager.
 */
inline ContextPtr NullContext(const LoggerPtr& logger = Logger(), 
                              const TypeManagerPtr& typeManager = TypeManager(),
                              const DictPtr<IString, IBaseObject> options = Dict<IString, IBaseObject>())
{
    ContextPtr obj(Context_Create(nullptr, logger, typeManager, nullptr, options));
    return obj;
}


/*!@}*/
END_NAMESPACE_CQDAQ
