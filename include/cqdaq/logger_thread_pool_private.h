
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

#include <spdlog/async.h>
#include <spdlog/details/thread_pool.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(ILoggerThreadPoolPrivate, IBaseObject)
{
    using ThreadPool = spdlog::details::thread_pool;
    using ThreadPoolPtr = std::shared_ptr<ThreadPool>;

    virtual ErrCode INTERFACE_FUNC getThreadPoolImpl(ThreadPoolPtr *impl) = 0;
};

END_NAMESPACE_CQDAQ
