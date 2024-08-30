#pragma once
#include <coretypes/dictobject.h>
#include <coretypes/dict_ptr.h>

BEGIN_NAMESPACE_CQDAQ

template <class KeyT, class ValueT>
inline DictObjectPtr<IDict, KeyT, ValueT> Dict()
{
    using KeyPtr = typename InterfaceOrTypeToSmartPtr<KeyT>::SmartPtr;
    using ValuePtr = typename InterfaceOrTypeToSmartPtr<ValueT>::SmartPtr;
    using DictionaryPtr = DictObjectPtr<IDict, KeyT, ValueT, KeyPtr, ValuePtr>;

    DictionaryPtr obj(DictWithExpectedTypes_Create(KeyPtr::DeclaredInterface::Id, ValuePtr::DeclaredInterface::Id));
    return obj;
}

template <typename KeyT, typename ValueT>
static DictObjectPtr<IDict, KeyT, ValueT> Dict(std::initializer_list<std::pair<const typename InterfaceToSmartPtr<KeyT>::SmartPtr,
                                                                                     typename InterfaceToSmartPtr<ValueT>::SmartPtr>> init)
{
    using KeyPtr = typename InterfaceOrTypeToSmartPtr<KeyT>::SmartPtr;
    using ValuePtr = typename InterfaceOrTypeToSmartPtr<ValueT>::SmartPtr;
    using DictionaryPtr = DictObjectPtr<IDict, KeyT, ValueT, KeyPtr, ValuePtr>;

    DictionaryPtr obj(DictWithExpectedTypes_Create(KeyPtr::DeclaredInterface::Id, ValuePtr::DeclaredInterface::Id));
    for (auto& [k, v] : init)
    {
        obj.set(k, v);
    }

    return obj;
}

template <class KeyT, class ValueT>
using DictPtr = DictObjectPtr<IDict, KeyT, ValueT>;

END_NAMESPACE_CQDAQ
