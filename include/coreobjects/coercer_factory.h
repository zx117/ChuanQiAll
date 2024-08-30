
#pragma once
#include <coreobjects/coercer_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup objects_coercer
 * @addtogroup objects_coercer_factories Factories
 * @{
 */

/*!
 * @brief Creates a Coercer with the given evaluation expression.
 * @param eval The evaluation expression used for coercion.
 */
inline CoercerPtr Coercer(const StringPtr& eval)
{
    CoercerPtr coercer(Coercer_Create(eval));
    return coercer;
}

/*!@}*/

END_NAMESPACE_CQDAQ
