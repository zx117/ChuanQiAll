#ifndef RECORDDAO_H
#define RECORDDAO_H

#include <soci/soci.h>

class Record
{
public:

};

class RecordDao
{
public:
    RecordDao();
    ~RecordDao();

    auto openRecordDB(const std::string dbName) -> void;
    auto createTable(const bool fromPool) -> void;
    auto update_conf(const std::string data, const bool fromPool, const int id = 1) -> void;
    auto get_data_by_id(const int id = 1) -> std::string;

private:
    soci::session* session;
};

#endif // RECORDDAO_H
