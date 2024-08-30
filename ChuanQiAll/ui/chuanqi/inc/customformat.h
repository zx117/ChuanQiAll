#ifndef CUSTOMFORMAT_H
#define CUSTOMFORMAT_H

#include "spdlog/spdlog.h"
#include "spdlog/formatter.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <QDebug>
class CustomFormat : public spdlog::formatter
{

public:
    explicit CustomFormat(const std::string& moduleName);
    void format(const spdlog::details::log_msg& msg, spdlog::memory_buf_t& dest) override;
    std::unique_ptr<spdlog::formatter> clone() const override;
private:
    std::string moduleName;


};

#endif // CUSTOMFORMAT_H
