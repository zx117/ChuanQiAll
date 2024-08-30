#pragma once
#include <coretypes/common.h>
#include <coretypes/dictobject_impl.h>
#include <coreobjects/property_object_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class OwningDictImpl : public DictImpl
{
public:
    OwningDictImpl(PropertyObjectPtr owner, StringPtr ref);

    ErrCode INTERFACE_FUNC set(IBaseObject* key, IBaseObject* value) override;

    ErrCode INTERFACE_FUNC remove(IBaseObject* key, IBaseObject** value) override;
    ErrCode INTERFACE_FUNC deleteItem(IBaseObject* key) override;

    ErrCode INTERFACE_FUNC clear() override;

private:
    StringPtr ref;
    PropertyObjectPtr owner;

    ErrCode removeOwner(IBaseObject* value) const;
};

END_NAMESPACE_CQDAQ
