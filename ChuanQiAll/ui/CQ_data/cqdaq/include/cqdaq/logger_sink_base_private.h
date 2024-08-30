
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <spdlog/sinks/sink.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(ILoggerSinkBasePrivate, IBaseObject)
{
    using Sink = spdlog::sinks::sink;
    using SinkPtr = std::shared_ptr<spdlog::sinks::sink>;

    /*!
     * @brief Get the sink implementation
     * @param[out] sinkImp The sink implementation
     */
    virtual ErrCode INTERFACE_FUNC getSinkImpl(SinkPtr* sinkImp) = 0;
};

END_NAMESPACE_CQDAQ
