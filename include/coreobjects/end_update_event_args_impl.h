#pragma once
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <coreobjects/end_update_event_args.h>
#include <coreobjects/property_ptr.h>
#include <coretypes/event_args_impl.h>

BEGIN_NAMESPACE_CQDAQ

class EndUpdateEventArgsImpl : public EventArgsBase<IEndUpdateEventArgs>
{
public:
    explicit EndUpdateEventArgsImpl(const ListPtr<IString>& properties, Bool isParentUpdating);

    ErrCode INTERFACE_FUNC getProperties(IList** properties) override;
    ErrCode INTERFACE_FUNC getIsParentUpdating(Bool* isParentUpdating) override;
private:
    ListPtr<IString> properties;
    Bool isParentUpdating;
};

END_NAMESPACE_CQDAQ
