
#pragma once
#include <coretypes/common.h>
#include <fmt/format.h>

BEGIN_NAMESPACE_CQDAQ

class DaqException : public std::runtime_error
{
public:
    template <typename... Params>
    explicit DaqException(ErrCode errCode, const std::string& format, Params&&... params)
        : DaqException(false, errCode, fmt::format(format, std::forward<Params>(params)...))
    {
    }

    [[nodiscard]]
    ErrCode getErrCode() const
    {
        return errCode;
    }

    [[nodiscard]]
    bool getDefaultMsg() const
    {
        return defaultMsg;
    }

protected:
    template <typename... Params>
    explicit DaqException(bool defaultMsg, ErrCode errCode, const std::string& msg)
        : runtime_error(msg)
        , errCode(errCode)
        , defaultMsg(defaultMsg)
    {
    }

private:
    ErrCode errCode;
    bool defaultMsg;
};

END_NAMESPACE_CQDAQ
