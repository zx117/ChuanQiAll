
#pragma once
#include <coretypes/baseobject.h>

extern "C"
int PUBLIC_EXPORT daqCycleDetectEnter(daq::IBaseObject* object);

extern "C"
void PUBLIC_EXPORT daqCycleDetectLeave(daq::IBaseObject* object);
