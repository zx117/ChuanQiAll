
#pragma once
#include <cqdaq/awaitable.h>
#include <coretypes/intfs.h>
#include <cqdaq/task_flow.h>
#include <coretypes/baseobject_factory.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TReturn = void>
class AwaitableImpl : public ImplementationOf<IAwaitable>
{
public:
    using Future = tf::Future<TReturn>;

    explicit AwaitableImpl(Future future);

    ErrCode INTERFACE_FUNC cancel(Bool* canceled) override;
    ErrCode INTERFACE_FUNC wait() override;
    ErrCode INTERFACE_FUNC getResult(IBaseObject** result) override;
    ErrCode INTERFACE_FUNC hasCompleted(Bool* finished) override;
private:
    Future future;
    std::atomic<bool> completed;
};

using Awaitable = AwaitableImpl<>;
using AwaitableFunc = AwaitableImpl<std::optional<BaseObjectPtr>>;

END_NAMESPACE_CQDAQ
