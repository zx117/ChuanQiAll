
#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/event_handler_ptr.h>
#include <vector>

namespace std
{
    template <>
    struct hash<daq::EventHandler>
    {
        using argument_type = daq::EventHandler;
        using result_type = std::size_t;

        result_type operator()(argument_type const& s) const noexcept
        {
            if (!s.assigned())
            {
                return 0;
            }

            return s.getHashCode();
        }
    };

    template <>
    struct equal_to<daq::EventHandler>
    {
        using first_argument_type = daq::EventHandler;
        using second_argument_type = daq::EventHandler;
        using result_type = bool;

        result_type operator()(first_argument_type const& lhs, second_argument_type const& rhs) const noexcept
        {
            return lhs.getHashCode() == rhs.getHashCode();
        }
    };
}

BEGIN_NAMESPACE_CQDAQ

class EventImpl : public ImplementationOf<IEvent, IFreezable>
{
    struct Handler
    {
        EventHandler eventHandler;
        bool muted;
    };
public:
    EventImpl();

    ErrCode INTERFACE_FUNC addHandler(IEventHandler* eventHandler) override;
    ErrCode INTERFACE_FUNC removeHandler(IEventHandler* eventHandler) override;

    ErrCode INTERFACE_FUNC clear() override;
    ErrCode INTERFACE_FUNC getSubscriberCount(SizeT* count) override;

    ErrCode INTERFACE_FUNC trigger(IBaseObject* sender, IEventArgs* args) override;

    ErrCode INTERFACE_FUNC mute() override;
    ErrCode INTERFACE_FUNC unmute() override;

    ErrCode INTERFACE_FUNC muteListener(IEventHandler* eventHandler) override;
    ErrCode INTERFACE_FUNC unmuteListener(IEventHandler* eventHandler) override;

    // IFreezable
    ErrCode INTERFACE_FUNC freeze() override;
    ErrCode INTERFACE_FUNC isFrozen(Bool* isFrozen) const override;

    // IBaseObject
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;
private:
    using ConstIterator = std::vector<Handler>::const_iterator;
    using Iterator = std::vector<Handler>::iterator;

    ErrCode setMuted(IEventHandler* eventHandler, bool muted);

    std::atomic<bool> muted{};
    std::atomic<bool> frozen{};
    std::vector<Handler> handlers;
};

END_NAMESPACE_CQDAQ
