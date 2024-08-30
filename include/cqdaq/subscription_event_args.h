
#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/event_args.h>

BEGIN_NAMESPACE_CQDAQ

enum class SubscriptionEventType : EnumType
{
    Subscribed,
    Unsubscribed
};

/*#
 * [interfaceSmartPtr(IEventArgs, EventArgsPtr, "<coretypes/event_args_ptr.h>")]
 */
DECLARE_CQDAQ_INTERFACE(ISubscriptionEventArgs, IEventArgs)
{
    virtual ErrCode INTERFACE_FUNC getStreamingConnectionString(IString** streamingConnectionString) = 0;
    virtual ErrCode INTERFACE_FUNC getSubscriptionEventType(SubscriptionEventType* type) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, SubscriptionEventArgs,
    IString*, streamingConnectionString,
    SubscriptionEventType, type
)

END_NAMESPACE_CQDAQ
