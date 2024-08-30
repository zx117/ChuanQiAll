
#pragma once
#include <coreobjects/validator_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_validator
 * @addtogroup objects_validator_factories Factories
 * @{
 */

/*!
 * @brief Creates a Validator with the given evaluation expression.
 * @param eval The evaluation expression used for validation.
 */
inline ValidatorPtr Validator(const StringPtr& eval)
{
    ValidatorPtr validator(Validator_Create(eval));
    return validator;
}

/*!@}*/

END_NAMESPACE_CQDAQ
