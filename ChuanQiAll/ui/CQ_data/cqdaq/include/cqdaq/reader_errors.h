
#pragma once
#include <coretypes/errors.h>

/*!
 * @ingroup cqdaq_errors_group
 * @addtogroup cqdaq_errors_macros Error Code Macros
 * @{
 */

#define CQDAQ_ERRTYPE_READER 0x0Du

#define CQDAQ_ERR_READER_UNKNOWN CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_READER, 0x0000u)
#define CQDAQ_ERR_INVALID_DATA   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_READER, 0x0001u)

/*!
 * @}
 */
