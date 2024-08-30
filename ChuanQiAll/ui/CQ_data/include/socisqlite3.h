#pragma once

#define SQLITE3_CONNECT_POOL_NUM 20

namespace soci {
    class session;
class connection_pool;
}


class SOCI_SQLITE3
{
public:
    SOCI_SQLITE3(const SOCI_SQLITE3&) = delete;
    SOCI_SQLITE3& operator=(const SOCI_SQLITE3&) = delete;

    static SOCI_SQLITE3& get_instance();

    void get_session(soci::session** session);

private:
    SOCI_SQLITE3();
    ~ SOCI_SQLITE3();

    soci::session *db_session;
    soci::connection_pool* m_pool;

};
