#include <soci/soci.h>
#include "savesqldata.h"
#include <soci/sqlite3/soci-sqlite3.h>
#include <iostream>
#include "connectionpool.h"

SaveSqlData::SaveSqlData()
{}

SaveSqlData::~SaveSqlData()
{}

int SaveSqlData::createTable(std::string tableName)
{
    try
    {
        soci::session* conn = ConnectionPool::get_instance().acquire();
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "CREATE TABLE IF NOT EXISTS " + tableName + " (id INTEGER PRIMARY KEY AUTOINCREMENT, count INTEGER, "
                                                             "relative_index INTEGER, data BLOB, time_data BLOB, data_type TEXT,"
                                                             "level INTEGER, start_time REAL, end_time REAL, create_time INTEGER);";
        std::cout << "======== CREATE TABLE OK: " << tableName << std::endl;
        ConnectionPool::get_instance().release(conn);
    }
    catch (const std::exception& e)
    {
        std::cerr << "CREATE TABLE error " << e.what() << tableName << std::endl;
    }
    return 0;
}

int SaveSqlData::insertData(const std::string tableName, const Data &data)
{
    try
    {
        soci::session* conn = ConnectionPool::get_instance().acquire();
        soci::blob blob(*conn);
        blob.write_from_start(data.data.data(), data.data.size());
        soci::blob time_blob(*conn);
        time_blob.write_from_start(data.time_data.data(), data.time_data.size());
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "INSERT INTO " + tableName + " (count, relative_index, data, time_data, data_type, level, start_time, end_time, create_time) "
                                              "VALUES (:count, :relative_index, :data, :time_data, :data_type, :level, :start_time, :end_time, DATETIME('now', 'localtime'));",
            soci::use(data.count), soci::use(data.relative_index), soci::use(blob), soci::use(time_blob), soci::use(data.data_type),
            soci::use(data.level), soci::use(data.start_time), soci::use(data.end_time);
        ConnectionPool::get_instance().release(conn);
    }
    catch (const std::exception& e)
    {
        std::cout << "INSERT DATA error " << e.what() << std::endl;
        return -1;
    }
    return 0;
}

Data SaveSqlData::getDataByID(const std::string tableName, int dataID)
{
    Data data;
    data.id = dataID;
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try
    {
        soci::blob blob(*conn);
        soci::indicator ind;
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "SELECT data, count, relative_index, type FROM " + tableName + " WHERE id = :id;",
            soci::into(blob, ind), soci::into(data.count), soci::into(data.relative_index),
            soci::into(data.data_type), soci::use(dataID);

        std::cout << "SQLITE3 get data by id: " << dataID << " count: " << data.count << " testIndex: " << data.relative_index << " type: " << data.data_type << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQLITE3 get data by id Error: " << tableName << dataID << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
    return data;
}
