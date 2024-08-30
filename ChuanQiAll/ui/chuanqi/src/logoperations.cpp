#include "logoperations.h"
LogOperations::LogOperations(QObject *parent)
{

}

LogOperations::~LogOperations()
{
    // 当 LogOperations 对象被销毁时，关闭所有日志记录器
    spdlog::drop_all();
}

/**
 * @brief LogOperations::recordLog    输出日志信息
 * @param moduleName                  模块名
 * @param level                       信息等级
 * @param information                 信息内容
 */
void LogOperations::recordLog(const QString& moduleName, int level, const QString &information)
{
    if (!moduleName.isEmpty() && level != 0 && !information.isEmpty())
    {
        auto logger = getLogger();
        if(logger!=nullptr)
        {
            // 设置日志格式为自定义格式，包含模块名
            logger->set_formatter(std::make_unique<CustomFormat>(std::string(moduleName.toLocal8Bit())));
            // 记录日志信息
            logger->log(static_cast<spdlog::level::level_enum>(level), std::string(information.toLocal8Bit()));
            logger->flush();
            emit logMessage("111");
        }
    }
}

/**
 * @brief LogOperations::setFlushOn  设置刷新显示的信息等级并即时刷新
 * @param level                      信息等级
 */
void LogOperations::setFlushOn(int level)
{
    auto logger = getLogger();
    // 设置日志记录器的日志等级
    logger->set_level(static_cast<spdlog::level::level_enum>(level));
    // 设置日志记录器在每次记录日志时刷新
    logger->flush_on(static_cast<spdlog::level::level_enum>(level));
}

/**
 * @brief LogOperations::setFlushOnTime   设置刷新时间
 * @param time                            时间
 */
void LogOperations::setFlushOnTime(int time)
{
    // 设置日志记录器定时刷新的时间间隔
    spdlog::flush_every(std::chrono::seconds(time));
}

/**
 * @brief LogOperations::getLogger    从日志库中检索初始化时的日志记录器并返回
 * @return                             返回初始化时创建的日志记录器
 */
std::shared_ptr<spdlog::logger> LogOperations::getLogger()
{
    // 检索并返回初始化时创建的日志记录器
    auto logger = spdlog::get("logger");
    return logger;
}

/**
 * @brief LogOperations::createLogger  初始化时创建异步日志记录器
 * @param path                         日志文件路径
 * @param filename                     日志文件名
 * @param time                         日志文件刷新时间
 */
void LogOperations::createLogger(const QString& path, const QString& filename)
{

    spdlog::init_thread_pool(10000, 2);
    spdlog::flush_every(std::chrono::seconds(1));
    // 使用当前日期生成日志文件名
    std::string current_date = fmt::format("{:%Y-%m-%d}", fmt::localtime(std::chrono::system_clock::now()));
    std::string file_name = fmt::format("{}/{}.txt", std::string(path.toLocal8Bit()), std::string(filename.toLocal8Bit()), current_date);

    // 创建控制台 sink
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

    // 创建文件 sink
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(file_name, 0, 0);

    // 创建包含多个 sink 的异步日志记录器
    std::list<spdlog::sink_ptr> sinks = {console_sink,file_sink};
    auto logger = std::make_shared<spdlog::async_logger>("logger", sinks.begin(), sinks.end(), spdlog::thread_pool());

    // 设置日志级别
    logger->set_level(spdlog::level::debug);

    // 注册 logger
    spdlog::register_logger(logger);
}
