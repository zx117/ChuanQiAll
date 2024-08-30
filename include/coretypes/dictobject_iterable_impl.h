#pragma once
#include <coretypes/dictobject_impl.h>
#include <coretypes/dictobject_iterator_impl.h>

BEGIN_NAMESPACE_CQDAQ

class BaseDictIterableImpl : public ImplementationOf<IIterable>
{
protected:
    using DictType = typename DictImpl::HashTableType;
    using DictPairType = typename DictType::iterator::value_type;
    friend struct BaseDictSelector;

public:
    explicit BaseDictIterableImpl(DictImpl* dict, const IntfID& id)
        : dict(dict)
        , id(id)
    {
        assert(dict != nullptr);
        dict->addRef();
    }

    ~BaseDictIterableImpl() override
    {
        dict->releaseRef();
    }

protected:
    [[nodiscard]]
    const DictType& getInternalStructure() const
    {
        return dict->hashTable;
    }

    DictImpl* dict;
    const IntfID& id;
};

template <typename TSelector>
class DictIterableImpl final : public BaseDictIterableImpl
{
public:
    using BaseDictIterableImpl::BaseDictIterableImpl;

    ErrCode INTERFACE_FUNC createStartIterator(IIterator** iterator) override
    {
        return createIterator(iterator, getInternalStructure().begin());
    }

    ErrCode INTERFACE_FUNC createEndIterator(IIterator** iterator) override
    {
        return createIterator(iterator, getInternalStructure().end());
    }
protected:

    template <typename T>
    ErrCode createIterator(IIterator** iterator, T it) 
    {
        if (iterator == nullptr)
            return CQDAQ_ERR_ARGUMENT_NULL;

        *iterator = new (std::nothrow) DictListIterator<DictType, TSelector>(
            asOrNull<IBaseObject>(dict, true),
            it,
            getInternalStructure().end(),
            id
        );

        if (*iterator == nullptr)
            return CQDAQ_ERR_NOMEMORY;

        (*iterator)->addRef();

        return CQDAQ_SUCCESS;
    }
};

struct BaseDictSelector
{
    using DictPairType = typename BaseDictIterableImpl::DictPairType;
};

struct KeySelector : BaseDictSelector
{
    IBaseObject* operator()(DictPairType pair) const
    {
        auto key = pair.first;
        if (key != nullptr)
            key->addRef();

        return pair.first;
    }
};

struct ValueSelector : BaseDictSelector
{
    IBaseObject* operator()(DictPairType pair) const
    {
        auto value = pair.second;
        if (value != nullptr)
            value->addRef();

        return pair.second;
    }
};

struct KeyValueSelector : BaseDictSelector
{
    IBaseObject* operator()(DictPairType pair) const
    {
        auto list = List<IBaseObject>();
        list->pushBack(pair.first);
        list->pushBack(pair.second);
        return list.detach();
    }
};

using DictKeyIterableImpl = DictIterableImpl<KeySelector>;
using DictValueIterableImpl = DictIterableImpl<ValueSelector>;

END_NAMESPACE_CQDAQ
