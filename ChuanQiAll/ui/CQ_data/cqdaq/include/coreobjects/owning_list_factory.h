#pragma once
#include <coretypes/listptr.h>
#include <coretypes/listobject_factory.h>
#include <coreobjects/property_object_ptr.h>

BEGIN_NAMESPACE_CQDAQ

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, OwningList, IList, IPropertyObject*, owner, IString*, ref)

template <class TValueInterface, class TValuePtr = typename InterfaceToSmartPtr<TValueInterface>::SmartPtr>
ListObjectPtr<IList, TValueInterface, TValuePtr> OwningList(const PropertyObjectPtr& owner, StringPtr ref = "list")
{
    ListObjectPtr<IList, TValueInterface, TValuePtr> obj(OwningList_Create(owner, ref));
    return obj;
}

template <class T, class S = typename InterfaceToSmartPtr<T>::SmartPtr, typename... Elements>
ListPtr<T, S> OwningList(StringPtr ref, PropertyObjectPtr owner, Elements&&... elements)
{
    auto list = OwningList<T, S>(owner, std::move(ref));
    addToList(list, std::forward<Elements>(elements)...);
    return list;
}

template <typename... Elements>
auto OwningList(StringPtr ref, PropertyObjectPtr owner, Elements&&... elements)
{
    return OwningList<IBaseObject, ObjectPtr<IBaseObject>>(std::move(ref), owner, std::forward<Elements>(elements)...);
}

template <typename... Elements>
auto OwningList(PropertyObjectPtr owner, Elements&&... elements)
{
    return OwningList<IBaseObject, ObjectPtr<IBaseObject>>("list", owner, std::forward<Elements>(elements)...);
}

END_NAMESPACE_CQDAQ
