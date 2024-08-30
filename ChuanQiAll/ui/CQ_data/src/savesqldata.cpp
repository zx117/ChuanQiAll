#include <soci/soci.h>
#include "savesqldata.h"
#include "socisqlite3.h"
#include <soci/sqlite3/soci-sqlite3.h>
#include <iostream>


SaveSqlData::SaveSqlData() : m_session(nullptr)
{
    SOCI_SQLITE3::get_instance().get_session(&m_session);
}

SaveSqlData::~SaveSqlData()
{
    if (m_session != nullptr) {
        m_session->close();
        delete m_session;
        m_session = nullptr;
    }
}

void SaveSqlData::openDB(std::string dbFile)
{
    try {
        m_session->close();
        m_session->open(soci::sqlite3, dbFile);
    }
    catch (const std::exception& e){
        std::cerr << "SOCI-SQLITE3 OPENDB ERROR: " << e.what() << std::endl;
    }
    return;
}

int SaveSqlData::createTable(std::string tableName)
{
    try {
        *m_session << "CREATE TABLE IF NOT EXISTS " + tableName + " (id INTEGER PRIMARY KEY, data BLOB, count INTEGER, testId INTEGER, type TEXT);";
        std::cout << "Table created successfully. " << tableName << std::endl;
    }
    catch(const soci::soci_error &e) {
        std::cerr << "SOCI-SQLITE3 CREATE TABLE ERROR: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

int SaveSqlData::insertData(const std::string tableName, const std::vector<char> &data, size_t count, size_t index, std::string typeStr)
{
    try {
        soci::blob blob(*m_session);
        blob.write_from_start(data.data(), data.size());
        *m_session << "INSERT INTO " + tableName + " (data, count, testId, type) VALUES (:data, :count, :testId, :type);",
            soci::use(blob), soci::use(count), soci::use(index), soci::use(typeStr);

        // std::cout << "SOCI-SQLITE3 data inserted successfully. " << tableName << std::endl;
    }
    catch(const soci::soci_error &e) {
        std::cerr << "SOCI-SQLITE3 INSERT ERROR: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void SaveSqlData::getDataByID(const std::string tableName, int dataID)
{
    TableData data;
    data.id = dataID;
    try
    {
        soci::blob blob(*m_session);
        soci::indicator ind;
        *m_session << "SELECT data, count, testId, type FROM " + tableName + " WHERE id = :id;",
            soci::into(blob, ind), soci::into(data.count), soci::into(data.testId),
            soci::into(data.type), soci::use(dataID);

        std::cout << "SQLITE3 get data by id: " << dataID << " count: " << data.count << " testIndex: " << data.testId << " type: " << data.type << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQLITE3 get data by id Error: " << tableName << dataID << e.what() << '\n';
    }

    // // test
    // soci::rowset<soci::row> rs = (m_session->prepare << "select * from Person");
    // for (soci::rowset<soci::row>::iterator it = rs.begin(); it != rs.end(); ++it)
    // {
    //     TableData data;
    //     const soci::row& row = *it;
    //     // 提取 BLOB 数据
    //     std::vector<char> dataBlob;
    //     // soci::blob blob = row["data"].get<soci::blob>();
    //     soci::blob blob = row.get<soci::blob>("data");
    //     dataBlob.resize(blob.get_len());
    //     blob.read_from_start(dataBlob.data(), blob.get_len());
    // }

    return;
}
