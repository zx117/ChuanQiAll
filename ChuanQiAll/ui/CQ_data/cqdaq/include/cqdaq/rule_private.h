
#pragma once
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_data_rule Rule private
 * @{
 */

/*!
 * @brief Private rule interface implemented by Dimension rules, Data rules and Scaling. Allows for parameter verification.
 */
DECLARE_CQDAQ_INTERFACE(IRulePrivate, IBaseObject)
{
    /*!
     * @brief Checks whether the parameters are valid and returns an appropriate error code if not.
     * @retval CQDAQ_ERR_INVALID_PARAMETERS If the parameters are invalid for the specific rule type.
     */
    virtual ErrCode INTERFACE_FUNC verifyParameters() = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
