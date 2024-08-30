#pragma once
#include <coretypes/common.h>
#include <coreobjects/property_value_event_args_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline PropertyValueEventArgsPtr PropertyValueEventArgs(const PropertyPtr& propChanged,
                                                        const BaseObjectPtr& newValue,
                                                        PropertyEventType changeType,
                                                        Bool isUpdating)
{
    return PropertyValueEventArgsPtr(PropertyValueEventArgs_Create(propChanged, newValue, changeType, isUpdating));
}

END_NAMESPACE_CQDAQ
