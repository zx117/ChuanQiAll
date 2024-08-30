
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @addtogroup types_utility
 * @{
 */

/*!
 * @brief Objects that can be cloned implement this interface.
 */
DECLARE_CQDAQ_INTERFACE(ICloneable, IBaseObject)
{
    /*!
     * @brief Clones the object.
     * @param[out] cloned The cloned object.
     */
    virtual ErrCode INTERFACE_FUNC clone(IBaseObject** cloned) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
