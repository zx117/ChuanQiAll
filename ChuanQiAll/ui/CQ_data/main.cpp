#include "sqlmanager.h"

int main(int argc, char *argv[])
{
    SOCI_SQLITE3 &soci_mysql = SOCI_SQLITE3::get_instance();
    soci_mysql.test();
}