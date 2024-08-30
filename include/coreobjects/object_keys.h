#pragma once
#include <coretypes/coretypes.h>

BEGIN_NAMESPACE_CQDAQ

template <class Intf>
struct ObjectHash
{
    size_t operator()(const ObjectPtr<Intf>& obj) const
    {
        SizeT hashCode;
        obj->getHashCode(&hashCode);
        return hashCode;
    }

    size_t operator()(const typename InterfaceToSmartPtr<Intf>::SmartPtr& obj) const
    {
        SizeT hashCode;
        obj->getHashCode(&hashCode);
        return hashCode;
    }
};

template <class Intf>
struct ObjectEqualTo
{
    bool operator()(const ObjectPtr<Intf>& a, const ObjectPtr<Intf>& b) const
    {
        assert(a != nullptr && b != nullptr);
        return a.equals(b);
    }

    bool operator()(const typename InterfaceToSmartPtr<Intf>::SmartPtr& a, const typename InterfaceToSmartPtr<Intf>::SmartPtr& b) const
    {
        assert(a != nullptr && b != nullptr);
        return a.equals(b);
    }
};

struct StringHash
{
    size_t operator()(const StringPtr& str) const
    {
        SizeT hashCode;
        str->getHashCode(&hashCode);
        return hashCode;
    }
};

struct StringEqualTo
{
    bool operator()(const StringPtr& a, const StringPtr& b) const
    {
        assert(a != nullptr && b != nullptr);

        ConstCharPtr aChPtr;
        a->getCharPtr(&aChPtr);
        ConstCharPtr bChPtr;
        b->getCharPtr(&bChPtr);
        return strcmp(aChPtr, bChPtr) == 0;
    };
};

END_NAMESPACE_CQDAQ

namespace std
{
    template <>
    struct hash<daq::StringPtr> : daq::StringHash
    {
    };

    template <>
    struct equal_to<daq::StringPtr> : daq::StringEqualTo
    {
    };
}
