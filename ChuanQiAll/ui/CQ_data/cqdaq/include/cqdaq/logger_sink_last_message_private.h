
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

DECLARE_CQDAQ_INTERFACE(ILastMessageLoggerSinkPrivate, IBaseObject)
{
    /*!
     * @brief Get the last log message
     * @param[out] lastMessage The last log message
     */
    virtual ErrCode INTERFACE_FUNC getLastMessage(IString** lastMessage) = 0;

    /*!
     * @brief Wait for receiving a new log message
     * @param timeoutMs The timeout in milliseconds until which wait for a new log message. If timeout set as 0 ms waiting will be skipped.
     * @param[out] success The success will return true if there was a new unread log message before waiting
     * or sink got a new logger message before timeout. False if timeout was reached.
     */
    virtual ErrCode INTERFACE_FUNC waitForMessage(SizeT timeoutMs, Bool* success) = 0;
};

END_NAMESPACE_CQDAQ
