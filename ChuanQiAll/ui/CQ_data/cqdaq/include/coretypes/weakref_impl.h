
#pragma once
#include <coretypes/weakref.h>
#include <coretypes/intfs.h>
#include <atomic>

BEGIN_NAMESPACE_CQDAQ

class WeakRefImpl final : public ImplementationOf<IWeakRef>
{
public:
    WeakRefImpl(IBaseObject* object, RefCount* refCount);
    ~WeakRefImpl() override;

    ErrCode INTERFACE_FUNC getRef(IBaseObject** ref) override;
    ErrCode INTERFACE_FUNC getRefAs(IntfID intfID, void** obj) override;

private:
    RefCount* refCount;
    IBaseObject* object;
};

inline WeakRefImpl::WeakRefImpl(IBaseObject* object, RefCount* refCount)
    : refCount(refCount)
    , object(object)
{
}

inline WeakRefImpl::~WeakRefImpl()
{
    const auto newWeakRefCount = std::atomic_fetch_sub_explicit(&refCount->weak, 1, std::memory_order_acq_rel) - 1;
    assert(newWeakRefCount >= 0);
    if (newWeakRefCount == 0)
        delete refCount;
}

inline ErrCode WeakRefImpl::getRef(IBaseObject** ref)
{
    for (;;)
    {
        auto curRefCount = refCount->strong.load(std::memory_order_acquire);
        if (curRefCount == 0)
            return CQDAQ_ERR_NOTASSIGNED;

        if (refCount->strong.compare_exchange_weak(curRefCount, curRefCount + 1, std::memory_order_acq_rel))
        {
            *ref = this->object;
            return CQDAQ_SUCCESS;
        }
    }
}

inline ErrCode WeakRefImpl::getRefAs(IntfID intfID, void** obj)
{
    for (;;)
    {
        auto curRefCount = refCount->strong.load(std::memory_order_acquire);
        if (curRefCount == 0)
            return CQDAQ_ERR_NOTASSIGNED;

        if (refCount->strong.compare_exchange_weak(curRefCount, curRefCount + 1, std::memory_order_acq_rel))
        {
            auto err = this->object->borrowInterface(intfID, obj);
            if (CQDAQ_FAILED(err))
            {
                this->object->releaseRef();
                return err;
            }

            return CQDAQ_SUCCESS;
        }
    }
}

END_NAMESPACE_CQDAQ
