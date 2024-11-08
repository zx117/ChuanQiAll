#include "connectionpool.h"
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>


ConnectionPool& ConnectionPool::get_instance()
{
    static ConnectionPool connPool;
    return connPool;
}

ConnectionPool::ConnectionPool(): stop_(false)
{
    sqlite_api::sqlite3_config(SQLITE_CONFIG_MULTITHREAD);
}

ConnectionPool::~ConnectionPool()
{
    stopPool();
}

void ConnectionPool::initConnection(const std::string &connectionString, size_t size)
{
    pool_size_ = size;
    for (size_t i = 0; i < size; ++i)
    {
        pool_.emplace(new soci::session(soci::sqlite3, connectionString));
    }
}

soci::session* ConnectionPool::acquire() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this] { return !pool_.empty() || stop_; });

    if (stop_ && pool_.empty()) {
        throw std::runtime_error("ConnectionPool has been stopped.");
    }

    soci::session* conn = pool_.front();
    pool_.pop();
    return conn;
}

void ConnectionPool::release(soci::session* conn) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (stop_) {
        delete conn;
    } else {
        pool_.push(conn);
        cv_.notify_one();
    }
}

void ConnectionPool::resetPool(const std::string& new_connection_string) {
    std::lock_guard<std::mutex> lock(mutex_);
    stop_ = true;
    cv_.notify_all();

    while (!pool_.empty()) {
        delete pool_.front();
        pool_.pop();
    }

    stop_ = false;
    initializePool(new_connection_string);
}

void ConnectionPool::initializePool(const std::string &connectionString) {
    for (size_t i = 0; i < pool_size_; ++i) {
        pool_.emplace(new soci::session(soci::sqlite3, connectionString));
    }
}

void ConnectionPool::stopPool() {
    std::lock_guard<std::mutex> lock(mutex_);
    stop_ = true;
    cv_.notify_all();

    while (!pool_.empty()) {
        delete pool_.front();
        pool_.pop();
    }
}

std::mutex& ConnectionPool::getMutex()
{
    static std::mutex shared_mutex;  // 静态局部变量，线程安全
    return shared_mutex;
}
