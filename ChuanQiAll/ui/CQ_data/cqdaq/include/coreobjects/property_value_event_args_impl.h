#pragma once
#include <coretypes/common.h>
#include <coretypes/intfs.h>
#include <coreobjects/property_value_event_args.h>
#include <coreobjects/property_ptr.h>
#include <coretypes/event_args_impl.h>

BEGIN_NAMESPACE_CQDAQ

class PropertyValueEventArgsImpl : public EventArgsBase<IPropertyValueEventArgs>
{
public:
    explicit PropertyValueEventArgsImpl(const PropertyPtr& property,
                                        const ObjectPtr<IBaseObject>& value,
                                        PropertyEventType type,
                                        Bool isUpdating)
        : EventArgsImplTemplate<IPropertyValueEventArgs>(0, "PropertyValueEvent")
        , property(property)
        , newValue(value)
        , type(type)
        , updating(isUpdating)
    {
    }

    ErrCode INTERFACE_FUNC getProperty(IProperty** prop) override;
    ErrCode INTERFACE_FUNC getValue(IBaseObject** value) override;
    ErrCode INTERFACE_FUNC setValue(IBaseObject* value) override;
    ErrCode INTERFACE_FUNC getPropertyEventType(PropertyEventType* changeType) override;
    ErrCode INTERFACE_FUNC getIsUpdating(Bool* isUpdating) override;

private:
    PropertyPtr property;
    BaseObjectPtr newValue;
    PropertyEventType type;
    Bool updating;
};

END_NAMESPACE_CQDAQ
