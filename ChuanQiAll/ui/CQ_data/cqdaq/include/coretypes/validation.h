
#pragma once

/*
 * This header contains macros for parameter validation for functions which return ErrorCode. The
 * `CQDAQ_ENABLE_PARAMETER_VALIDATION` CMake option can be set to enable or disable validation.
 * Validation is normally enabled, but can be disabled for performance (in which case the caller
 * must guarantee valid parameter values to avoid undefined behavior).
 */

#ifdef CQDAQ_ENABLE_PARAMETER_VALIDATION

#define CQDAQ_PARAM_REQUIRE(cond) \
    do { if (!(cond)) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_NOT_NULL(param) \
    do { if (nullptr == (param)) return CQDAQ_ERR_ARGUMENT_NULL; } while (0)

#define CQDAQ_PARAM_TRUTHY(param) \
    do { if (!(param)) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_FALSY(param) \
    do { if (param) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_GE(param, val) \
    do { if (!((param) >= (val))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_GT(param, val) \
    do { if (!((param) > (val))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_LE(param, val) \
    do { if (!((param) <= (val))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_LT(param, val) \
    do { if (!((param) < (val))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_BETWEEN(param, a, b) \
    do { if (!((param) >= (a)) || !((param) <= (b))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#define CQDAQ_PARAM_STRICTLY_BETWEEN(param, a, b) \
    do { if (!((param) > (a)) || !((param) < (b))) return CQDAQ_ERR_INVALIDPARAMETER; } while (0)

#else

#define CQDAQ_PARAM_REQUIRE(cond)
#define CQDAQ_PARAM_NOT_NULL(param)
#define CQDAQ_PARAM_TRUTHY(param)
#define CQDAQ_PARAM_FALSY(param)
#define CQDAQ_PARAM_GE(param, val)
#define CQDAQ_PARAM_GT(param, val)
#define CQDAQ_PARAM_LE(param, val)
#define CQDAQ_PARAM_LT(param, val)
#define CQDAQ_PARAM_BETWEEN(param, a, b)
#define CQDAQ_PARAM_STRICTLY_BETWEEN(param, a, b)

#endif
