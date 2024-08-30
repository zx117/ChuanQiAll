
#pragma once
#include <coretypes/weakref.h>
#include <coretypes/weakref_impl.h>
#include <coretypes/intfs.h>
#include <coretypes/weakrefptr.h>

BEGIN_NAMESPACE_CQDAQ

template <typename MainInterface, typename ... Intfs>
class IntfObjectWithWeakRefImpl : public IntfObjectSupportsWeakRefImpl<MainInterface, ISupportsWeakRef, Intfs...>
{
public:
    ErrCode INTERFACE_FUNC getWeakRef(IWeakRef** weakRef) override;
protected:
    template <class TInterface>
    WeakRefPtr<TInterface> getWeakRefInternal();
};

template <typename MainInterface, typename... Intfs>
ErrCode IntfObjectWithWeakRefImpl<MainInterface, Intfs...>::getWeakRef(IWeakRef** weakRef)
{
    std::atomic_fetch_add_explicit(&this->refCount->weak, 1, std::memory_order_relaxed);

    IBaseObject* thisBaseObject;
    this->borrowInterface(IBaseObject::Id, reinterpret_cast<void**>(&thisBaseObject));
    *weakRef = new WeakRefImpl(thisBaseObject, this->refCount.get());
    (*weakRef)->addRef();

    return CQDAQ_SUCCESS;
}

template <typename MainInterface, typename ... Intfs>
template <class TInterface>
WeakRefPtr<TInterface> IntfObjectWithWeakRefImpl<MainInterface, Intfs...>::getWeakRefInternal()
{
    std::atomic_fetch_add_explicit(&this->refCount->weak, 1, std::memory_order_relaxed);

    IWeakRef* weakRef = new WeakRefImpl(this->template borrowInterface<MainInterface>(), this->refCount.get());
    return WeakRefPtr<TInterface>(weakRef);
}

template <typename... Interfaces>
using ImplementationOfWeak = IntfObjectWithWeakRefImpl<Interfaces..., IInspectable>;

//template <typename... Intfs>
//using ImplementationOfWeak = typename Meta::FoldType<typename ActualInterfaces<Intfs...>::Interfaces, IntfObjectWithWeakRefImpl>::Folded;

END_NAMESPACE_CQDAQ
