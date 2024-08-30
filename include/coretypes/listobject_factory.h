#pragma once
#include <coretypes/list_ptr.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <class TValueInterface, class TValuePtr = typename InterfaceOrTypeToSmartPtr<TValueInterface>::SmartPtr>
ListObjectPtr<IList, TValueInterface, TValuePtr> List()
{
    ListObjectPtr<IList, TValueInterface, TValuePtr> obj(ListWithElementType_Create(TValuePtr::DeclaredInterface::Id));
    return obj;
}

template <class T, class S = typename InterfaceOrTypeToSmartPtr<T>::SmartPtr>
using ListPtr = ListObjectPtr<IList, T, S>;

template <class T, class S = typename InterfaceOrTypeToSmartPtr<T>::SmartPtr, class U>
static void addToList(ListPtr<T, S>& list, U&& element)
{
    list.unsafePushBack(std::forward<U>(element));
}

template <class T, class S = typename InterfaceOrTypeToSmartPtr<T>::SmartPtr, class U, class... V>
static void addToList(ListPtr<T, S>& list, U&& first, V&&... rest)
{
    list.unsafePushBack(std::forward<U>(first));
    addToList(list, std::forward<V>(rest)...);
}

template <class T, class S = typename InterfaceOrTypeToSmartPtr<T>::SmartPtr, typename... Elements>
ListPtr<T, S> List(Elements&&... elements)
{
    auto list = List<T, S>();
    addToList(list, std::forward<Elements>(elements)...);
    return list;
}

END_NAMESPACE_CQDAQ
