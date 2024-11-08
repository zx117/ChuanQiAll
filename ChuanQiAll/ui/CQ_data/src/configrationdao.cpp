#include "configrationdao.h"
#include <iostream>
#include "connectionpool.h"

ConfigrationDao::ConfigrationDao() {}

ConfigrationDao::~ConfigrationDao()
{}

auto ConfigrationDao::createTable(const std::string tableName) -> void
{
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "CREATE TABLE IF NOT EXISTS " + tableName + " (id INTEGER PRIMARY KEY AUTOINCREMENT, conf_type TEXT, conf_data TEXT unique, timestamp TIMESTAMP);";
        std::cout << "======== CREATE TABLE OK: " << tableName << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "SQLITE CREATE TABLE error " << e.what() << tableName << std::endl;
    }
    ConnectionPool::get_instance().release(conn);
}

auto ConfigrationDao::create_conf(const Configration& conf) -> void
{
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "INSERT INTO Configration (conf_type, conf_data, timestamp) VALUES (:conf_type, :conf_data, now())",
            soci::use(conf.conf_type), soci::use(conf.conf_data);
    }
    catch (const std::exception& e) {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
}

auto ConfigrationDao::update_conf(const std::string conf, const std::string type) -> void
{
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "UPDATE Configration SET conf_data:= conf WHERE conf_type = :conf_type;",
            soci::use(conf), soci::use(type);
    }
    catch (const std::exception& e) {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
}

void ConfigrationDao::update_conf(const std::string conf, const int id)
{
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "UPDATE Configration SET conf_data:= conf WHERE id = :id;",
            soci::use(conf), soci::use(id);
    }
    catch (const std::exception& e) {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
}

auto ConfigrationDao::get_Conf_by_id(int Conf_id) -> Configration
{
    Configration conf;
    conf.conf_id = Conf_id;
    soci::session* conn = ConnectionPool::get_instance().acquire();

    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "SELECT conf_type, conf_data type FROM Configration WHERE id = :id;",
            soci::into(conf.conf_type), soci::into(conf.conf_data), soci::use(Conf_id);
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
    return conf;
}

auto ConfigrationDao::get_Conf_by_type(const std::string Conf_Type) -> Configration
{
    Configration conf;
    conf.conf_type = Conf_Type;
    soci::session* conn = ConnectionPool::get_instance().acquire();

    try
    {
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        *conn << "SELECT conf_data type FROM Configration WHERE conf_type = :conf_type;",
            soci::into(conf.conf_data), soci::use(Conf_Type);
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
    return conf;
}

auto ConfigrationDao::get_allConf_by_type(const std::string Conf_Type) -> std::vector<Configration>
{
    std::vector<Configration> confs;
    soci::session* conn = ConnectionPool::get_instance().acquire();
    try{
        std::unique_lock<std::mutex> lock(ConnectionPool::getMutex());
        soci::rowset<soci::row> rs = conn->prepare << "SELECT * FROM Configration";

        for (auto it = rs.begin(); it != rs.end(); ++it) {
            Configration conf;
            conf.conf_id = it->get<int>(0);
            conf.conf_type = it->get<std::string>(1);
            conf.conf_data = it->get<std::string>(2);
            conf.timestamp = it->get<std::tm>(3);
            confs.emplace_back(conf);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "SQLITE Configration Error: " << e.what() << '\n';
    }
    ConnectionPool::get_instance().release(conn);
    return confs;
}
