
#pragma once
#include <coretypes/errors.h>

/*!
 * @ingroup cqdaq_errors_group
 * @addtogroup cqdaq_errors_macros Error Code Macros
 * @{
 */

#define CQDAQ_ERRTYPE_SIGNAL 0x0Au

#define CQDAQ_ERR_RANGE_BOUNDARIES_INVALID             CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x001u)
#define CQDAQ_ERR_DIMENSION_IMPLICIT                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x002u)
#define CQDAQ_ERR_DIMENSION_EXPLICIT                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x003u)
#define CQDAQ_ERR_CONFIGURATION_INCOMPLETE             CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x004u)
#define CQDAQ_ERR_INVALID_DIMENSION_LABEL_TYPES        CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x005u)
#define CQDAQ_ERR_INVALID_PARAMETERS                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x006u)
#define CQDAQ_ERR_UNKNOWN_RULE_TYPE                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x007u)
#define CQDAQ_ERR_INVALID_SAMPLE_TYPE                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x008u)
#define CQDAQ_ERR_SIGNAL_NOT_ACCEPTED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x009u)
#define CQDAQ_ERR_PACKET_MEMORY_ALLOCATION             CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x00Au)
#define CQDAQ_ERR_PACKET_MEMORY_DEALLOCATION           CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_SIGNAL, 0x00Bu)

/*!
 * @}
 */