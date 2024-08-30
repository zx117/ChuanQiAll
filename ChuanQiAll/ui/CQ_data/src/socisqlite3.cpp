#include "socisqlite3.h"
#include <iostream>

#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

SOCI_SQLITE3 &SOCI_SQLITE3::get_instance()
{
    static SOCI_SQLITE3 instance;
    return instance;
}

void SOCI_SQLITE3::get_session(soci::session **session)
{
    // *session = db_session;
    *session = new soci::session(*m_pool);
}

SOCI_SQLITE3::SOCI_SQLITE3() : m_pool(new soci::connection_pool(SQLITE3_CONNECT_POOL_NUM))
{
    // // db_session = new soci::session();
    // try {
    //     for (int i = 0; i < SQLITE3_CONNECT_POOL_NUM; ++i) {
    //         soci::session& session = m_pool->at(i);
    //     }
    // }
    // catch (const std::exception& e) {
    //     std::cerr << "SQLITE3 Error: " << e.what() << std::endl;
    //     // mysql_error = e.what();
    // }
}

SOCI_SQLITE3::~SOCI_SQLITE3()
{
    // if (db_session){
    //     delete db_session;
    //     db_session = nullptr;
    // }
    if (m_pool) {
        delete m_pool;
        m_pool = nullptr;
    }
}

