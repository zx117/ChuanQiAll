#pragma once
#include <coretypes/listobject.h>
#include <coretypes/baseobject_impl.h>
#include <coretypes/coretype.h>
#include <coretypes/freezable.h>
#include <coretypes/serializable.h>
#include <coretypes/cloneable.h>
#include <coretypes/iterable.h>
#include <coretypes/list_element_type.h>

#include <vector>

BEGIN_NAMESPACE_CQDAQ

class ListIteratorImpl;

class ListImpl : public ImplementationOf<IList, IIterable, ISerializable, IListElementType, ICoreType, ICloneable, IFreezable>
{
public:
    ListImpl();
    explicit ListImpl(IntfID id);

    ErrCode INTERFACE_FUNC getItemAt(SizeT index, IBaseObject** item) override;
    ErrCode INTERFACE_FUNC getCount(SizeT* size) override;

    ErrCode INTERFACE_FUNC setItemAt(SizeT index, IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC pushBack(IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC pushFront(IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC moveBack(IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC moveFront(IBaseObject* obj) override;

    ErrCode INTERFACE_FUNC popBack(IBaseObject** obj) override;
    ErrCode INTERFACE_FUNC popFront(IBaseObject** obj) override;

    ErrCode INTERFACE_FUNC insertAt(SizeT index, IBaseObject* obj) override;
    ErrCode INTERFACE_FUNC removeAt(SizeT index, IBaseObject** obj) override;

    ErrCode INTERFACE_FUNC deleteAt(SizeT index) override;

    ErrCode INTERFACE_FUNC clear() override;

    // IIterable, IList
    ErrCode INTERFACE_FUNC createStartIterator(IIterator** iterator) override;
    ErrCode INTERFACE_FUNC createEndIterator(IIterator** iterator) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IFreezable
    ErrCode INTERFACE_FUNC freeze() override;
    ErrCode INTERFACE_FUNC isFrozen(Bool* isFrozen) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    // IBaseObject
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // ICloneable
    ErrCode INTERFACE_FUNC clone(IBaseObject** cloned) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    // IElementType
    ErrCode INTERFACE_FUNC getElementInterfaceId(IntfID* id) override;

protected:
    IntfID iid;
    bool frozen = false;
    std::vector<IBaseObject*> list;

    void internalDispose(bool) override;
    ErrCode deleteAtInternal(SizeT index, IBaseObject** removed, bool& deleted);

private:
    friend ListIteratorImpl;

    void releaseRefOnChildren();
};

END_NAMESPACE_CQDAQ
