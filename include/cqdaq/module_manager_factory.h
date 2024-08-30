
#pragma once
#include <cqdaq/module_manager_ptr.h>
#include <cqdaq/logger_ptr.h>
#include <cqdaq/context_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_module_manager
 * @addtogroup cqdaq_module_manager_factories Factories
 * @{
 */

/*!
 * @brief Creates a ModuleManager that loads modules at a given search path. If the search path is empty,
 * it searches the executable folder and its subfolders. Otherwise, it searches the for the relative directory
 * based on the current working directory.
 * @param searchPath The location of the module libraries.
 */
inline ModuleManagerPtr ModuleManager(const StringPtr& searchPath)
{
    ModuleManagerPtr obj(ModuleManager_Create(searchPath));
    return obj;
}

/*!
 * @brief Creates a ModuleManager that loads modules at given search paths. If the search path is empty,
 * it searches the executable folder and its subfolders. Otherwise, it searches the for the relative directory
 * based on the current working directory.
 * @param paths The locations of the module libraries.
 */
inline ModuleManagerPtr ModuleManagerMultiplePaths(const ListPtr<IString>& paths)
{
    ModuleManagerPtr obj(ModuleManagerMultiplePaths_Create(paths));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
