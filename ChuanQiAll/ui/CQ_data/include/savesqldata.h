#pragma once
#include <QString>
#include <vector>
#include <mutex>
#include "SqliteBaseDao.hpp"

namespace soci {
class session;
}

class Data
{
public:
    qint64 id;
    qint64 count;
    qint64 relative_index;
    const std::vector<char> data;
    const std::vector<char> time_data;
    std::string data_type;
    qint64 level;
    double start_time;
    double end_time;
    std::tm create_time;

    Data() : id(0), count(0), relative_index(1), data_type("double"), level(1), start_time(0.0), end_time(0.0) {}
    Data(qint64 count, qint64 r_index, const std::vector<char> data,
         const std::vector<char> time_data, std::string type, qint64 level,
         double start_time, double end_time)
        : count(count), relative_index(r_index), data(data), time_data(time_data), data_type(type),
        level(level), start_time(start_time), end_time(end_time) {}
};

class SaveSqlData : public SqliteBaseDao
{
public:
    SaveSqlData();
    ~SaveSqlData();

    auto createTable(std::string tableName) -> int;

    auto insertData(const std::string tableName, const Data& data) -> int;

    auto getDataByID(const std::string tableName, int dataID) -> Data;

private:
    std::mutex mtx;
};

