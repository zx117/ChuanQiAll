#include "customformat.h"
#include "spdlog/fmt/bundled/chrono.h"
CustomFormat::CustomFormat(const std::string &moduleName)
    : moduleName(moduleName)
{

}
/**
 * @brief CustomFormat::format  自定义格式化器
 * @param msg                   msg 是一个引用，指向 spdlog::details::log_msg 类型的对象，包含了日志消息的所有信息
 * @param dest                  dest 是一个引用，指向 spdlog::memory_buf_t 类型的对象，用于存储格式化后的日志字符串。
 */
void CustomFormat::format(const spdlog::details::log_msg &msg, spdlog::memory_buf_t &dest)
{
    auto time = fmt::localtime(msg.time);
    fmt::format_to(std::back_inserter(dest), "{:%Y-%m-%dT%H:%M:%S} ", time);
    // 线程ID转换为十六进制形式，并添加到 dest
    fmt::format_to(std::back_inserter(dest), "t0x{:x} ", msg.thread_id);
    //添加模块名
    if (moduleName.size()) {
        fmt::format_to(std::back_inserter(dest), "{} ", moduleName);
    }
    // 日志级别转换为大写
    std::string level_str = spdlog::level::to_string_view(msg.level).data();
    std::transform(level_str.begin(), level_str.end(), level_str.begin(), ::toupper);
    fmt::format_to(std::back_inserter(dest), "[{}] ", level_str);
    // 添加日志消息
    fmt::format_to(std::back_inserter(dest), "{}", fmt::to_string(msg.payload));
    dest.push_back('\n');
}
/**
 * @brief CustomFormat::clone   复制格式化器实例
 * @return
 */
std::unique_ptr<spdlog::formatter> CustomFormat::clone() const
{
    return std::make_unique<CustomFormat>(*this);
}


