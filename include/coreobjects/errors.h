#pragma once
#include <coretypes/errors.h>

/*!
 * @ingroup objects_errors_group
 * @addtogroup objects_errors_macros Error Code Macros
 * @{
 */

#define CQDAQ_ERRTYPE_COREOBJECTS   0x06u
/*!
 * @objects_error{
 * 0x80060001,
 * Failed to retrieve the object's owner as it has no owner.
 * }
 */
#define CQDAQ_ERR_NO_OWNER             CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_COREOBJECTS, 0x001u)
#define CQDAQ_ERR_OWNER_EXPIRED        CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_COREOBJECTS, 0x002u)
#define CQDAQ_ERR_MANAGER_NOT_ASSIGNED CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_COREOBJECTS, 0x002u)

/*!
 * @}
 */
