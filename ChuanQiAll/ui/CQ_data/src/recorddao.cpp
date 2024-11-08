#include "recorddao.h"
#include <soci/sqlite3/soci-sqlite3.h>
#include <iostream>
#include <QDebug>
#include "connectionpool.h"

RecordDao::RecordDao()
{
    session = new soci::session();
}

RecordDao::~RecordDao()
{
    qDebug() << "===========RecordDao xigou";
    session->close();
    if (session){
        delete session;
        session = nullptr;
    }
}

void RecordDao::openRecordDB(const std::string dbName)
{
    try {
        session->open(soci::sqlite3 , dbName);
    }
    catch (const std::exception& e) {
        std::cerr << "RecordDao Error: " << e.what() << std::endl;
    }
}

void RecordDao::createTable(const bool fromPool)
{
    std::cout << "createTable=====fromPool: " << fromPool << "\n";
    try
    {
        if(fromPool){
            soci::session* conn = ConnectionPool::get_instance().acquire();
            std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
            *conn << "CREATE TABLE IF NOT EXISTS Record (id INTEGER PRIMARY KEY AUTOINCREMENT, data TEXT);";
            ConnectionPool::get_instance().release(conn);
        }
        else{
            *session << "CREATE TABLE IF NOT EXISTS Record (id INTEGER PRIMARY KEY AUTOINCREMENT, data TEXT);";
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "CREATE TABLE error " << e.what() << std::endl;
    }
}

void RecordDao::update_conf(const std::string data, const bool fromPool, const int id)
{
    try {
        if(fromPool){
            soci::session* conn = ConnectionPool::get_instance().acquire();
            std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
            *conn << "INSERT INTO Record (id, data) VALUES (:id, :data) "
                     "ON CONFLICT(id) DO UPDATE SET id = :id, data = :data",
                soci::use(id), soci::use(data);
            ConnectionPool::get_instance().release(conn);
        }
        else{
            *session << "INSERT INTO Record (id, data) VALUES (:id, :data) "
                        "ON CONFLICT(id) DO UPDATE SET id = :id, data = :data",
                soci::use(id), soci::use(data);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "INSERT DATA Error: " << e.what() << std::endl;
    }
}

std::string RecordDao::get_data_by_id(const int id)
{
    std::string res;
    try {
        *session << "SELECT data FROM Record WHERE id = :id;",
            soci::into(res), soci::use(id);
    }
    catch (const std::exception& e) {
        std::cerr << "INSERT DATA Error: " << e.what() << std::endl;
    }
    return res;
}




