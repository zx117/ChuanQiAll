#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <queue>
#include <mutex>

namespace soci {
    class session;
    class connection_pool;
}



class ConnectionPool
{
public:
    ConnectionPool(const ConnectionPool&) = delete;
    ConnectionPool& operator=(const ConnectionPool&) = delete;
    static ConnectionPool& get_instance();
    static std::mutex& getMutex();

    auto initConnection(const std::string& connectionString, size_t size) -> void;
    auto acquire() -> soci::session*;
    auto release(soci::session* conn) -> void;
    auto changeConnection(const std::string& newConnectionString) -> void;
    auto resetPool(const std::string& new_connection_string) -> void;

private:
    ConnectionPool();
    ~ConnectionPool();

    void initializePool(const std::string &connectionString);
    void stopPool();

    int pool_size_;
    bool stop_;
    std::queue<soci::session*> pool_;
    std::mutex mutex_;
    std::condition_variable cv_;
    std::condition_variable cond_;

};

#endif // CONNECTIONPOOL_H
