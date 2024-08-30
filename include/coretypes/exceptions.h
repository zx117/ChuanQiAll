
#pragma once
#include <coretypes/bb_exception.h>
#include <coretypes/common.h>
#include <coretypes/error_code_to_exception.h>
#include <coretypes/errors.h>
#include <cstdio>
#include <stdexcept>
#include <string>

BEGIN_NAMESPACE_CQDAQ

#define DEFINE_EXCEPTION_BASE(excBase, excName, errCode, excMsg)                                 \
    class excName##Exception : public excBase                                                    \
    {                                                                                            \
    public:                                                                                      \
        explicit excName##Exception()                                                            \
            : excBase(true, errCode, excMsg)                                                     \
        {                                                                                        \
        }                                                                                        \
        template <typename... Params>                                                            \
        explicit excName##Exception(const std::string& msg, Params&&... params)                  \
            : excBase(errCode, msg, std::forward<Params>(params)...)                             \
        {                                                                                        \
        }                                                                                        \
        template <typename... Params>                                                            \
        explicit excName##Exception(daq::ErrCode err, const std::string& msg, Params&&... params) \
            : excBase(errCode, msg, std::forward<Params>(params)...)                             \
        {                                                                                        \
        }                                                                                        \
    };                                                                                           \
    CQDAQ_REGISTER_ERRCODE_EXCEPTION(errCode, excName##Exception)

#define CQDAQ_REGISTER_ERRCODE_EXCEPTION(errCode, type)                                                \
    class Exception##type##Factory                                                                  \
    {                                                                                               \
    public:                                                                                         \
        Exception##type##Factory()                                                                  \
        {                                                                                           \
            daq::ErrorCodeToException::GetInstance()->registerException<type>(errCode);              \
        }                                                                                           \
    };                                                                                              \
                                                                                                    \
    namespace Detail::Initialization                                                                \
    {                                                                                               \
        inline Exception##type##Factory exception##type##Factory;                                   \
    }

#define DEFINE_EXCEPTION(excName, errCode, excMsg) DEFINE_EXCEPTION_BASE(daq::DaqException, excName, errCode, excMsg)

#define CQDAQ_TRY(expression)            \
    try                                    \
    {                                      \
        expression                         \
    }                                      \
    catch (const DaqException& e)          \
    {                                      \
        return errorFromException(e);      \
    }                                      \
    catch (const std::exception& e)        \
    {                                      \
        return errorFromException(e);      \
    }                                      \
    catch (...)                            \
    {                                      \
        return CQDAQ_ERR_GENERALERROR;   \
    }

/*
 * Should be in the order of the error's numerical value
 */

DEFINE_EXCEPTION(NoMemory, CQDAQ_ERR_NOMEMORY, "No memory")
DEFINE_EXCEPTION(InvalidParameter, CQDAQ_ERR_INVALIDPARAMETER, "Invalid parameter")
DEFINE_EXCEPTION(NoInterface, CQDAQ_ERR_NOINTERFACE, "Invalid cast. The object does not implement this interface.")
DEFINE_EXCEPTION(SizeTooSmall, CQDAQ_ERR_SIZETOOSMALL, "Size too small")
DEFINE_EXCEPTION(ConversionFailed, CQDAQ_ERR_CONVERSIONFAILED, "Conversion failed")
DEFINE_EXCEPTION(OutOfRange, CQDAQ_ERR_OUTOFRANGE, "Out of range")
DEFINE_EXCEPTION(NotFound, CQDAQ_ERR_NOTFOUND, "Not found")
DEFINE_EXCEPTION(AlreadyExists, CQDAQ_ERR_ALREADYEXISTS, "Already exists")
DEFINE_EXCEPTION(NotAssigned, CQDAQ_ERR_NOTASSIGNED, "Not assigned")
DEFINE_EXCEPTION(CallFailed, CQDAQ_ERR_CALLFAILED, "Call failed")
DEFINE_EXCEPTION(ParseFailed, CQDAQ_ERR_PARSEFAILED, "Parse failed")
DEFINE_EXCEPTION(InvalidValue, CQDAQ_ERR_INVALIDVALUE, "Invalid value")
DEFINE_EXCEPTION(ResolveFailed, CQDAQ_ERR_RESOLVEFAILED, "Resolve failed")
DEFINE_EXCEPTION(InvalidType, CQDAQ_ERR_INVALIDTYPE, "Invalid type")
DEFINE_EXCEPTION(AccessDenied, CQDAQ_ERR_ACCESSDENIED, "Access denied")
DEFINE_EXCEPTION(NotEnabled, CQDAQ_ERR_NOTENABLED, "Not enabled")
// DEFINE_EXCEPTION(CalcFailed, CQDAQ_ERR_CALCFAILED, "Calculation failed")
DEFINE_EXCEPTION(NotImplemented, CQDAQ_ERR_NOTIMPLEMENTED, "Not Implemented")
DEFINE_EXCEPTION(Frozen, CQDAQ_ERR_FROZEN, "Object frozen")
DEFINE_EXCEPTION(NotFrozen, CQDAQ_ERR_NOT_FROZEN, "Object is not frozen")
DEFINE_EXCEPTION(NotSerializable, CQDAQ_ERR_NOT_SERIALIZABLE, "Not serializable")
DEFINE_EXCEPTION(Deserialize, CQDAQ_ERR_DESERIALIZE_PARSE_ERROR, "Error when parsing or deserializing")
DEFINE_EXCEPTION(DeserealizeUnknownType, CQDAQ_ERR_DESERIALIZE_UNKNOWN_TYPE, "Unknown format of Serialize type id")
DEFINE_EXCEPTION(DeserealizeNoType, CQDAQ_ERR_DESERIALIZE_NO_TYPE, "Serialize type id not found")
DEFINE_EXCEPTION(InvalidProperty, CQDAQ_ERR_INVALIDPROPERTY, "Invalid property")
DEFINE_EXCEPTION(DuplicateItem, CQDAQ_ERR_DUPLICATEITEM, "Duplicate item")
DEFINE_EXCEPTION(ArgumentNull, CQDAQ_ERR_ARGUMENT_NULL, "Argument must not be NULL.")
DEFINE_EXCEPTION(InvalidOperation, CQDAQ_ERR_INVALID_OPERATION, "Operation in not valid for the current type or state.")
DEFINE_EXCEPTION(Uninitialized, CQDAQ_ERR_UNINITIALIZED, "The operation requires initialization")
DEFINE_EXCEPTION(InvalidState, CQDAQ_ERR_INVALIDSTATE, "Invalid state")
DEFINE_EXCEPTION(ValidateFailed, CQDAQ_ERR_VALIDATE_FAILED, "Validate failed")
DEFINE_EXCEPTION(NotUpdatable, CQDAQ_ERR_NOT_UPDATABLE, "Not updatable")
DEFINE_EXCEPTION(NotCompatibleVersion, CQDAQ_ERR_NO_COMPATIBLE_VERSION, "Not compatible version")
DEFINE_EXCEPTION(Locked, CQDAQ_ERR_LOCKED, "Locked")
DEFINE_EXCEPTION(SizeTooLarge, CQDAQ_ERR_SIZETOOLARGE, "Size too large")
DEFINE_EXCEPTION(BufferFull, CQDAQ_ERR_BUFFERFULL, "Buffer full")
DEFINE_EXCEPTION(EmptyScalingTable, CQDAQ_ERR_EMPTY_SCALING_TABLE, "Scaling table must not be empty")
DEFINE_EXCEPTION(EmptyRange, CQDAQ_ERR_EMPTY_RANGE, "Scaling range must not be empty")
DEFINE_EXCEPTION(CreateFailed, CQDAQ_ERR_CREATE_FAILED, "Failed to create object")
DEFINE_EXCEPTION(GeneralError, CQDAQ_ERR_GENERALERROR, "General error")
DEFINE_EXCEPTION(DiscoveryFailed, CQDAQ_ERR_DISCOVERY_FAILED, "Device discovery failed")
DEFINE_EXCEPTION(CoerceFailed, CQDAQ_ERR_COERCE_FAILED, "Coercing failed")
DEFINE_EXCEPTION(NotSupported, CQDAQ_ERR_NOT_SUPPORTED, "The operation or type is not supported")
DEFINE_EXCEPTION(ListNotHomogeneous, CQDAQ_ERR_LIST_NOT_HOMOGENEOUS, "List is not homogeneous")
DEFINE_EXCEPTION(FactoryNotRegistered, CQDAQ_ERR_FACTORY_NOT_REGISTERED, "Factory not registered")
DEFINE_EXCEPTION(NoData, CQDAQ_ERR_NO_DATA, "No data")

extern void checkErrorInfo(ErrCode errCode);

[[noreturn]] inline void throwExceptionFromErrorCode(ErrCode errCode, const std::string& msg = "")
{
    IExceptionFactory* fact = ErrorCodeToException::GetInstance()->getExceptionFactory(errCode);
    fact->throwException(errCode, msg);

    // Unreachable code but prevents GCC from emitting a warning that a [[noreturn]] function actually returns
    throw std::runtime_error(msg + " (" + std::to_string(errCode) + ")");
}

END_NAMESPACE_CQDAQ
