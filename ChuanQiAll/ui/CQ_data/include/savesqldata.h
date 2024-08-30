#pragma once
#include <QString>
#include <vector>

namespace soci {
class session;
}

class SOCI_SQLITE3;

struct TableData
{
    qint64 id;
    const std::vector<char> data;
    qint64 count;
    qint64 testId;
    std::string type;

    TableData() {
        id = 0;
        count = 0;
        testId = 0;
        type = "double";
    }
};

class SaveSqlData
{
public:
    SaveSqlData();
    ~SaveSqlData();

    void openDB(std::string dbFile);
    int createTable(std::string tableName);

    int insertData(const std::string tableName,  const std::vector<char>& data, size_t count, size_t index, std::string typeStr);

    void getDataByID(const std::string tableName, int dataID);

private:
    soci::session* m_session;
};

