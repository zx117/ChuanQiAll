#pragma once
#include <coretypes/common.h>
#include <coreobjects/ownable_ptr.h>
#include <coretypes/listobject_impl.h>
#include <coretypes/weakrefptr.h>

BEGIN_NAMESPACE_CQDAQ

class OwningListImpl final : public ListImpl
{
public:
    OwningListImpl(IPropertyObject* owner, StringPtr ref);

    ErrCode INTERFACE_FUNC setItemAt(SizeT index, IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC insertAt(SizeT index, IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC pushBack(IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC pushFront(IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC moveBack(IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC moveFront(IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC popBack(IBaseObject** obj) override;
    ErrCode INTERFACE_FUNC popFront(IBaseObject** obj) override;

    ErrCode INTERFACE_FUNC removeAt(SizeT index, IBaseObject** obj) override;
    ErrCode INTERFACE_FUNC deleteAt(SizeT index) override;
    ErrCode INTERFACE_FUNC clear() override;
private:
    StringPtr ref;
    WeakRefPtr<IPropertyObject> owner;

    ErrCode removeOwner(IBaseObject* value) const;
    ErrCode setOwner(IBaseObject* value) const;
};

END_NAMESPACE_CQDAQ
