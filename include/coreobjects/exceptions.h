#pragma once
#include <coretypes/exceptions.h>
#include <coreobjects/errors.h>

BEGIN_NAMESPACE_CQDAQ

DEFINE_EXCEPTION(CalcFailed, CQDAQ_ERR_CALCFAILED, "Calculation failed")
DEFINE_EXCEPTION(ManagerNotAssigned, CQDAQ_ERR_MANAGER_NOT_ASSIGNED, "Property object class manager is not assigned")

END_NAMESPACE_CQDAQ
