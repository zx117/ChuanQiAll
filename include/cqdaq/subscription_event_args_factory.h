
#pragma once
#include <coretypes/common.h>
#include <cqdaq/subscription_event_args_ptr.h>

BEGIN_NAMESPACE_CQDAQ

inline SubscriptionEventArgsPtr SubscriptionEventArgs(const StringPtr& streamingConnectionString,
                                                      SubscriptionEventType eventType)
{
    return SubscriptionEventArgsPtr(SubscriptionEventArgs_Create(streamingConnectionString, eventType));
}

END_NAMESPACE_CQDAQ
