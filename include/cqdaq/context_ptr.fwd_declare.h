
#pragma once
#include <cqdaq/component.h>

BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType>
class GenericComponentPtr;

using ComponentPtr = daq::GenericComponentPtr<IComponent>;

END_NAMESPACE_CQDAQ
