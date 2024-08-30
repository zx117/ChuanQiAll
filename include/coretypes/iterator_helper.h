
#pragma once
#include <coretypes/iterator.h>

BEGIN_NAMESPACE_CQDAQ

inline ErrCode compareIterators(const IIterator* it1, const IIterator* it2, Bool* equal)
{
    if (it1 == nullptr || it2 == nullptr || equal == nullptr)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *equal = false;

    IBaseObject* obj1;
    auto err = it1->getCurrent(&obj1);
    if (err == CQDAQ_ERR_NOTASSIGNED)
    {
        obj1 = nullptr;
    }
    else if (!CQDAQ_SUCCEEDED(err))
    {
        return err;
    }

    Finally final2([&obj1]()
    {
        if (obj1)
            obj1->releaseRef();
    });

    IBaseObject* obj2;
    err = it2->getCurrent(&obj2);
    if (err == CQDAQ_ERR_NOTASSIGNED)
    {
        obj2 = nullptr;
    }
    else if (!CQDAQ_SUCCEEDED(err))
    {
        return err;
    }

    Finally final3([&obj2]()
    {
        if (obj2)
            obj2->releaseRef();
    });

    if (obj2 == nullptr)
    {
        *equal = obj1 == nullptr;
        return CQDAQ_SUCCESS;
    }

    if (obj1 == nullptr)
        return CQDAQ_SUCCESS;

    return obj2->equals(obj1, equal);
}

template <class T>
ErrCode iteratorMoveNext(bool& started, typename T::const_iterator& it, const typename T::const_iterator& end)
{
    if (!started)
    {
        started = true;
        if (it == end)
            return CQDAQ_NO_MORE_ITEMS;

        return CQDAQ_SUCCESS;
    }

    if (it == end || ++it == end)
        return CQDAQ_NO_MORE_ITEMS;

    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
