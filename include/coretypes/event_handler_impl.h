
#pragma once
#include <coretypes/delegate.hpp>
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <coretypes/objectptr.h>
#include <coretypes/event_handler.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TSenderPtr, typename TEventArgsPtr>
class EventHandlerImpl : public ImplementationOf<IEventHandler>
{
public:
    using Subscription = delegate<void(TSenderPtr&, TEventArgsPtr&)>;

    explicit EventHandlerImpl(Subscription&& sub) : subscription(std::move(sub))
    {
    }

    ErrCode INTERFACE_FUNC handleEvent(IBaseObject* sender, IEventArgs* eventArgs) override
    {
        try
        {
            auto obj = sender != nullptr ? TSenderPtr::Borrow(sender) : TSenderPtr{};
            auto args = eventArgs != nullptr ? TEventArgsPtr::Borrow(eventArgs) : TEventArgsPtr{};

            subscription(obj, args);
        }
        catch (const DaqException& e)
        {
            return errorFromException(e);
        }
        catch (const std::exception&)
        {
            return CQDAQ_ERR_GENERALERROR;
        }

        return CQDAQ_SUCCESS;
    }

    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override
    {
        if (hashCode == nullptr)
        {
            return makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Can not return by a null pointer.");
        }

        *hashCode = subscription.hashCode;
        return CQDAQ_SUCCESS;
    }

private:
    Subscription subscription;
};

END_NAMESPACE_CQDAQ
