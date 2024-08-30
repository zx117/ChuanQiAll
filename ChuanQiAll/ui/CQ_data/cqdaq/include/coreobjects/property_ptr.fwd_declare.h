#pragma once
#include <coreobjects/property_object.h>

BEGIN_NAMESPACE_CQDAQ

template <typename InterfaceType>
class GenericPropertyObjectPtr;

using PropertyObjectPtr = GenericPropertyObjectPtr<IPropertyObject>;

class PropertyValueEventArgsPtr;

END_NAMESPACE_CQDAQ
