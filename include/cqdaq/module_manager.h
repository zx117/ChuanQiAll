
#pragma once
#include <cqdaq/module.h>
#include <coretypes/listobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_modules
 * @addtogroup cqdaq_module_manager Module manager
 * @{
 */

/*!
 * @brief Loads all available modules in a implementation-defined manner.
 * User can also side-load custom modules via `addModule` call.
 */
DECLARE_CQDAQ_INTERFACE(IModuleManager, IBaseObject)
{
    // [elementType(modules, IModule)]
    /*!
     * @brief Retrieves all modules known to the manager. Whether they were found or side-loaded.
     * @param[out] modules A list of known modules.
     */
    virtual ErrCode INTERFACE_FUNC getModules(IList** modules) = 0;

    /*!
     * @brief Side-load a custom module in run-time from memory that was not found by default.
     * @param module The module to add.
     * @retval CQDAQ_ERR_DUPLICATEITEM When an identical @p module was already added.
     */
    virtual ErrCode INTERFACE_FUNC addModule(IModule* module) = 0;

    /*!
     * @brief Loads all modules from the directory path specified during manager construction. The
     * Context is passed to all loaded modules for internal use.
     * @param context The Context containing the Logger, Scheduler, Property Object Class Manager and Module Manager
     */
    virtual ErrCode INTERFACE_FUNC loadModules(IContext* context) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, ModuleManager,
    IString*, path)

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY,
    ModuleManagerMultiplePaths, IModuleManager,
    IList*, paths)

END_NAMESPACE_CQDAQ
