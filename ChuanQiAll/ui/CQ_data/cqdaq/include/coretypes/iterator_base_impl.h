
#pragma once

#include <coretypes/intfs.h>

#include <coretypes/iterator.h>
#include <coretypes/iterator_helper.h>

BEGIN_NAMESPACE_CQDAQ

template <typename T>
struct DefaultValueSelector
{
    IBaseObject* operator()(T t) const
    {
        if (t != nullptr)
            t->addRef();

        return t;
    }
};

template <typename T, typename ElementTypeInterface, typename ValueSelector = DefaultValueSelector<typename T::iterator::value_type>>
class IteratorBaseImpl : public ImplementationOf<IIterator, ElementTypeInterface>
{
protected:
    using IteratorType = typename T::const_iterator;

public:
    IteratorBaseImpl(IBaseObject* coreContainer, IteratorType it, IteratorType end, ValueSelector valueSelector = ValueSelector());
    ~IteratorBaseImpl() override;

    ErrCode INTERFACE_FUNC moveNext() override;
    ErrCode INTERFACE_FUNC getCurrent(IBaseObject** obj) const override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

private:
    IBaseObject* coreContainer;
    IteratorType it;
    IteratorType end;
    bool started;
    ValueSelector valueSelector;
};

template <typename T, typename E, typename VS>
IteratorBaseImpl<T, E, VS>::IteratorBaseImpl(IBaseObject* coreContainer, IteratorType it, IteratorType end, VS valueSelector)
    : coreContainer(coreContainer)
    , it(std::move(it))
    , end(std::move(end))
    , started(false)
    , valueSelector(std::move(valueSelector))
{
    assert(coreContainer != nullptr);
    coreContainer->addRef();
}

template <typename T, typename E, typename VS>
IteratorBaseImpl<T, E, VS>::~IteratorBaseImpl()
{
    coreContainer->releaseRef();
}

template <typename T, typename E, typename VS>
ErrCode IteratorBaseImpl<T, E, VS>::getCurrent(IBaseObject** obj) const
{
    if (obj == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    if (it == end)
        return CQDAQ_ERR_NOTASSIGNED;

    *obj = valueSelector(*it);
    return CQDAQ_SUCCESS;
}

template <typename T, typename E, typename VS>
ErrCode IteratorBaseImpl<T, E, VS>::equals(IBaseObject* other, Bool* equal) const
{
    if (equal == nullptr)
        return this->makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equal output parameter must not be null.");

    *equal = false;
    if (!other)
        return CQDAQ_SUCCESS;

    IIterator* itOther;
    ErrCode err = other->borrowInterface(IIterator::Id, reinterpret_cast<void**>(&itOther));
    if (!CQDAQ_SUCCEEDED(err))
        return err;

    return compareIterators(this, itOther, equal);
}

template <typename T, typename E, typename VS>
ErrCode IteratorBaseImpl<T, E, VS>::moveNext()
{
    return iteratorMoveNext<T>(started, it, end);
}

END_NAMESPACE_CQDAQ
