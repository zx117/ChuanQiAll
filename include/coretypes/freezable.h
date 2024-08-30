
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_utility
 * @{
 */

/*!
 * @brief Transforms a mutable object to an immutable object.
 *
 * If an object supports IFreezable interface, it is possible to transform it to immutable object.
 * Once the object is frozen, it should not allow to change any of its properties or internal state.
 */

DECLARE_CQDAQ_INTERFACE(IFreezable, IBaseObject)
{
    /*!
     * @brief Makes the object frozen/immutable.
     * It should return CQDAQ_IGNORED value if the object is already frozen.
     */
    virtual ErrCode INTERFACE_FUNC freeze() = 0;

    /*!
     * @brief Checks if the objects is frozen/immutable.
     * @param[out] isFrozen The object's frozen/immutable state.
     */
    virtual ErrCode INTERFACE_FUNC isFrozen(Bool* isFrozen) const = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
