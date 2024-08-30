
#pragma once

#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_components_removable Removable
 * @{
 */

/*!
 * @brief Allows the component to be notified when it is removed.
 */
DECLARE_CQDAQ_INTERFACE(IRemovable, IBaseObject)
{
    /*!
     * @brief Notifies the component that it is being removed.
     *
     * Call `remove` on the component to mark it as removed. It's up to the implementation
     * to define what is does on the act of removal. Basic implementation of `Component`
     * will switch it to inactive state and it cannot be activated again.
     */
    virtual ErrCode INTERFACE_FUNC remove() = 0;

    /*!
     * @brief Returns True if component was removed.
     * @param[out] removed True if component was removed; otherwise False.
     */
    virtual ErrCode INTERFACE_FUNC isRemoved(Bool* removed) = 0;

};
/*!@}*/

END_NAMESPACE_CQDAQ
