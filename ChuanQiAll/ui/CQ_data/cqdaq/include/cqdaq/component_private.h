
#pragma once

#include <coretypes/listobject.h>

BEGIN_NAMESPACE_CQDAQ

/*#
 * [interfaceLibrary(ICoreEventArgs, "coreobjects")]
 */

/*!
 * @brief Provides access to private methods of the component.
 *
 * Said methods allow for triggering a Core event of the component, and locking/unlocking attributes of
 * the component.
 */
DECLARE_CQDAQ_INTERFACE(IComponentPrivate, IBaseObject)
{
    // [templateType(attributes, IString)]
    /*!
     * @brief Locks the attributes contained in the provided list.
     * @param attributes The list of attributes that should be locked. Is not case sensitive.
     */
    virtual ErrCode INTERFACE_FUNC lockAttributes(IList* attributes) = 0;

    /*!
     * @brief Locks all attributes of the component.
     */
    virtual ErrCode INTERFACE_FUNC lockAllAttributes() = 0;

    // [templateType(attributes, IString)]
    /*!
     * @brief Unlocks the attributes contained in the provided list.
     * @param attributes The list of attributes that should be unlocked. Is not case sensitive.
     */
    virtual ErrCode INTERFACE_FUNC unlockAttributes(IList* attributes) = 0;

    /*!
     * @brief Unlocks all attributes of the component.
     */
    virtual ErrCode INTERFACE_FUNC unlockAllAttributes() = 0;

    /*!
     * @brief Triggers the component-specific core event with the provided arguments.
     * @param args The arguments of the core event.
     */
    virtual ErrCode INTERFACE_FUNC triggerComponentCoreEvent(ICoreEventArgs* args) = 0;
};

END_NAMESPACE_CQDAQ
