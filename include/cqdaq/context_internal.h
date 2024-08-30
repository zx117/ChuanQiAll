
#pragma once
#include <cqdaq/module_manager.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_utility
 * @addtogroup cqdaq_context Context
 * @{
 */

/*!
 * @brief Internal Context interface used for transferring the Module Manager reference to a new owner.
 */

DECLARE_CQDAQ_INTERFACE(IContextInternal, IBaseObject)
{
    /*!
     * @brief Gets the Module Manager. Moves the strong reference to the manager to the first
     * caller and retains a weak reference internally.
     * @param[out] manager The module manager.
     *
     * Returns a nullptr on subsequent invocations, and if the manager is not assigned.
     */
    virtual ErrCode INTERFACE_FUNC moveModuleManager(IModuleManager** manager) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
