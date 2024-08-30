
#pragma once
#include <cqdaq/logger_thread_pool.h>
#include <cqdaq/logger_thread_pool_private.h>
#include <coretypes/intfs.h>

#include <memory>

BEGIN_NAMESPACE_CQDAQ

class LoggerThreadPoolImpl final : public ImplementationOf<ILoggerThreadPool, ILoggerThreadPoolPrivate>
{
public:
    LoggerThreadPoolImpl();

    // ILoggerThreadPoolPrivate
    ErrCode INTERFACE_FUNC getThreadPoolImpl(ThreadPoolPtr *impl) override;

private:
    ThreadPoolPtr spdlogThreadPool;
};

END_NAMESPACE_CQDAQ
