#pragma once
#include <coretypes/dictptr.h>
#include <coreobjects/property_object_ptr.h>

BEGIN_NAMESPACE_CQDAQ

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, OwningDict, IDict, IPropertyObject*, owner, IString*, ref)

template <typename TKey, typename TValue>
DictPtr<TKey, TValue> OwningDict(PropertyObjectPtr owner, StringPtr ref = "dict")
{
    return DictPtr<TKey, TValue>(OwningDict_Create(owner, ref));
}

END_NAMESPACE_CQDAQ
