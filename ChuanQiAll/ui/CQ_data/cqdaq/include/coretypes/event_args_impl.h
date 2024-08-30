#pragma once
#include <utility>
#include <coretypes/coretypes.h>

BEGIN_NAMESPACE_CQDAQ

template <typename... TInterfaces>
class EventArgsImplTemplate;

using EventArgsImpl = EventArgsImplTemplate<IEventArgs>;

template <typename... TInterfaces>
using EventArgsBase = EventArgsImplTemplate<TInterfaces...>;

template <typename... TInterfaces>
class EventArgsImplTemplate : public ImplementationOf<TInterfaces...>
{
public:
    EventArgsImplTemplate(Int id, const StringPtr& name)
        : eventId(id)
        , eventName(name)
    {
    }

    virtual ErrCode INTERFACE_FUNC getEventId(Int* id) override;
    virtual ErrCode INTERFACE_FUNC getEventName(IString** name) override;

protected:
    Int eventId;
    StringPtr eventName;
};

template <typename... TInterfaces>
ErrCode EventArgsImplTemplate<TInterfaces...>::getEventId(Int* id)
{
    *id = eventId;

    return CQDAQ_SUCCESS;
}

template <typename... TInterfaces>
ErrCode EventArgsImplTemplate<TInterfaces...>::getEventName(IString** name)
{
    *name = eventName.addRefAndReturn();

    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
