
#pragma once
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <coretypes/event_args_impl.h>
#include <cqdaq/subscription_event_args.h>

BEGIN_NAMESPACE_CQDAQ

class SubscriptionEventArgsImpl : public EventArgsBase<ISubscriptionEventArgs>
{
public:
    explicit SubscriptionEventArgsImpl(const StringPtr& streamingConnectionString,
                                       SubscriptionEventType eventType);

    ErrCode INTERFACE_FUNC getStreamingConnectionString(IString** streamingConnectionString) override;
    ErrCode INTERFACE_FUNC getSubscriptionEventType(SubscriptionEventType* eventType) override;

private:
    StringPtr streamingConnectionString;
    SubscriptionEventType eventType;
};

END_NAMESPACE_CQDAQ
