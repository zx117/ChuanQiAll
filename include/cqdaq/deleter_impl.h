
#pragma once
#include <cqdaq/deleter.h>
#include <coretypes/intfs.h>

BEGIN_NAMESPACE_CQDAQ

template <class Callback>
class DeleterImpl : public ImplementationOf<IDeleter>
{
public:
    explicit DeleterImpl(const Callback& callback);
    explicit DeleterImpl(Callback&& callback);

    ErrCode INTERFACE_FUNC deleteMemory(void* address) override;

private:
    Callback callback;
};

template <class Callback>
DeleterImpl<Callback>::DeleterImpl(const Callback& callback)
    : callback(callback)
{
}

template <class Callback>
DeleterImpl<Callback>::DeleterImpl(Callback&& callback)
    : callback(std::move(callback))
{
}

template <class Callback>
ErrCode DeleterImpl<Callback>::deleteMemory(void* address)
{
    callback(address);
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
