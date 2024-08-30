
#pragma once
#include <cqdaq/reader_errors.h>
#include <coretypes/exceptions.h>

BEGIN_NAMESPACE_CQDAQ

class ReaderException : public DaqException
{
public:
    using DaqException::DaqException;
};

#define DEFINE_READER_EXCEPTION(excName, errCode, excMsg) \
    DEFINE_EXCEPTION_BASE(daq::ReaderException, excName, errCode, excMsg)

/*
 * Should be in the order of the error's numerical value
 */
DEFINE_READER_EXCEPTION(ReaderUnknown, CQDAQ_ERR_READER_UNKNOWN, "Unknown reader exception")
DEFINE_READER_EXCEPTION(InvalidData, CQDAQ_ERR_INVALID_DATA, "Samples can't be read or converted to the wanted type")

END_NAMESPACE_CQDAQ
