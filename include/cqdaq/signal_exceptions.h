
#pragma once
#include <coretypes/exceptions.h>
#include <cqdaq/signal_errors.h>

DEFINE_EXCEPTION(RangeBoundariesInvalid, CQDAQ_ERR_RANGE_BOUNDARIES_INVALID, "The low and high boundaries of the range are invalid.")
DEFINE_EXCEPTION(DimensionImplicit, CQDAQ_ERR_DIMENSION_IMPLICIT, "Operation is invalid on implicit dimensions.")
DEFINE_EXCEPTION(DimensionExplicit, CQDAQ_ERR_DIMENSION_EXPLICIT, "Operation is invalid on explicit dimensions.")
DEFINE_EXCEPTION(ConfigurationIncomplete, CQDAQ_ERR_CONFIGURATION_INCOMPLETE, "Call not allowed until configuration is complete.")
DEFINE_EXCEPTION(InvalidLabelTypes, CQDAQ_ERR_INVALID_DIMENSION_LABEL_TYPES, "Dimension explicit labels are of an invalid type.")
DEFINE_EXCEPTION(InvalidParameters, CQDAQ_ERR_INVALID_PARAMETERS, "Parameters of rule/scaling are not valid.")
DEFINE_EXCEPTION(UnknownRuleType, CQDAQ_ERR_UNKNOWN_RULE_TYPE, "Rule is custom and cannot be interpreted by cqDAQ.")
DEFINE_EXCEPTION(InvalidSampleType, CQDAQ_ERR_INVALID_SAMPLE_TYPE, "Provided sample type is not supported.")
DEFINE_EXCEPTION(SignalNotAccepted, CQDAQ_ERR_SIGNAL_NOT_ACCEPTED, "Input port does not accept the provided signal.")
DEFINE_EXCEPTION(MemoryAllocationFailed, CQDAQ_ERR_PACKET_MEMORY_ALLOCATION, "Packet data buffer memory allocation failed.")
DEFINE_EXCEPTION(MemoryDeallocationFailed, CQDAQ_ERR_PACKET_MEMORY_DEALLOCATION, "Packet data buffer memory deallocation failed.")
