
#pragma once

/**
 * @ingroup types_errors_group
 * @defgroup types_errors_macros Error Code Macros
 * @{
 */

#define CQDAQ_ERROR_CODE(TYPE_ID, ERROR_CODE) (0x80000000u | ((TYPE_ID) << 16u) | (ERROR_CODE))
#define CQDAQ_GET_ERROR_CODE(ERROR) (0x0000FFFFu & ERROR)

#define CQDAQ_FAILED(x)    ((x) & 0x80000000u)
#define CQDAQ_SUCCEEDED(x) (!CQDAQ_FAILED(x))

#define CQDAQ_ERRTYPE_GENERIC        0x00u

#define CQDAQ_SUCCESS                0x00000000u

#define CQDAQ_LOWER                  0x00000002u
#define CQDAQ_EQUAL                  0x00000003u
#define CQDAQ_GREATER                0x00000004u
#define CQDAQ_NO_MORE_ITEMS          0x00000005u
#define CQDAQ_IGNORED                0x00000006u
#define CQDAQ_NOTFOUND               0x00000007u

#define CQDAQ_MAKE_ERROR(err) CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, err)

#define CQDAQ_ERR_NOMEMORY                       CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0000u)
#define CQDAQ_ERR_INVALIDPARAMETER               CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0001u)
#define CQDAQ_ERR_NOINTERFACE                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x4002u) // to make it COM-compatible
#define CQDAQ_ERR_SIZETOOSMALL                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0003u)
#define CQDAQ_ERR_CONVERSIONFAILED               CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0004u)
/*!
 * @types_error{
 * 0x80000005,
 * The requested item index exceeds the target structure size.
 * }
 */
#define CQDAQ_ERR_OUTOFRANGE                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0005u)
/*!
 * @types_error{
 * 0x80000006,
 * Requested object is not a part of the target structure.
 * }
 */
#define CQDAQ_ERR_NOTFOUND                       CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0006u)

/*!
 * @types_error{
 * 0x8000000A,
 * The object being added is already present in the target structure.
 * }
 */
#define CQDAQ_ERR_ALREADYEXISTS                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x000Au)
#define CQDAQ_ERR_NOTASSIGNED                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x000Bu)
#define CQDAQ_ERR_CALLFAILED                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x000Cu)
#define CQDAQ_ERR_PARSEFAILED                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x000Du)
#define CQDAQ_ERR_INVALIDVALUE                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x000Eu)
#define CQDAQ_ERR_RESOLVEFAILED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0010u)
#define CQDAQ_ERR_INVALIDTYPE                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0011u)
#define CQDAQ_ERR_ACCESSDENIED                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0012u)
#define CQDAQ_ERR_NOTENABLED                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0013u)
#define CQDAQ_ERR_GENERALERROR                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0014u)
#define CQDAQ_ERR_CALCFAILED                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0015u)
#define CQDAQ_ERR_NOTIMPLEMENTED                 CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0016u)
#define CQDAQ_ERR_FROZEN                         CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0017u)
#define CQDAQ_ERR_NOT_SERIALIZABLE               CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0018u)
#define CQDAQ_ERR_FACTORY_NOT_REGISTERED         CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0020u)
#define CQDAQ_ERR_DESERIALIZE_PARSE_ERROR        CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0021u)
#define CQDAQ_ERR_DESERIALIZE_UNKNOWN_TYPE       CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0022u)
#define CQDAQ_ERR_DESERIALIZE_NO_TYPE            CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0023u)
#define CQDAQ_ERR_INVALIDPROPERTY                CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0024u)
#define CQDAQ_ERR_DUPLICATEITEM                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0025u)
#define CQDAQ_ERR_ARGUMENT_NULL                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0026u)
#define CQDAQ_ERR_INVALID_OPERATION              CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0027u)
#define CQDAQ_ERR_UNINITIALIZED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0028u)
#define CQDAQ_ERR_INVALIDSTATE                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0029u)

/*!
 * @types_error{
 * 0x80000030,
 * Validation of the passed value failed. The value does not adhere to the imposed type
 * or content predicates.
 * }
 */
#define CQDAQ_ERR_VALIDATE_FAILED                CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0030u)
#define CQDAQ_ERR_NOT_UPDATABLE                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0031u)
#define CQDAQ_ERR_NO_COMPATIBLE_VERSION          CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0032u)
#define CQDAQ_ERR_LOCKED                         CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0033u)
#define CQDAQ_ERR_SIZETOOLARGE                   CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0034u)
#define CQDAQ_ERR_BUFFERFULL                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0035u)
#define CQDAQ_ERR_CREATE_FAILED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0036u)
#define CQDAQ_ERR_EMPTY_SCALING_TABLE            CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0037u)
#define CQDAQ_ERR_EMPTY_RANGE                    CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0038u)
#define CQDAQ_ERR_DISCOVERY_FAILED               CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0039u)
/*!
 * @types_error{
 * 0x80000040,
 * Coercion of the passed value failed. The value does not adhere to the imposed type
 * or content predicates. It cannot be coerced to fit to the provided value restrictions. 
 * }
 */
#define CQDAQ_ERR_COERCE_FAILED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0040u)
#define CQDAQ_ERR_NOT_SUPPORTED                  CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0041u)

#define CQDAQ_ERR_LIST_NOT_HOMOGENEOUS           CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0042u)
#define CQDAQ_ERR_NOT_FROZEN                     CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0043u)
#define CQDAQ_ERR_NO_TYPE_MANAGER                CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0044u)

#define CQDAQ_ERR_NO_DATA                        CQDAQ_ERROR_CODE(CQDAQ_ERRTYPE_GENERIC, 0x0050u)

/*!
 * @}
 */