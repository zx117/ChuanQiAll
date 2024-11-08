#ifndef CONFIGRATIONDAO_H
#define CONFIGRATIONDAO_H

#include <string>
#include <ctime>
#include <soci/soci.h>
#include <mutex>

class Configration
{
public:
    int conf_id;
    std::tm timestamp;
    std::string conf_type;
    std::string conf_data;
};


class ConfigrationDao
{
public:
    ConfigrationDao();
    ~ConfigrationDao();

    auto createTable(const std::string) -> void;

    auto create_conf(const Configration& conf) -> void;

    auto update_conf(const std::string conf, const std::string type) -> void;
    auto update_conf(const std::string conf, const int id) -> void;

    auto get_Conf_by_id(int Conf_id) -> Configration;
    auto get_Conf_by_type(const std::string Conf_Type) -> Configration;
    auto get_allConf_by_type(const std::string Conf_Type) -> std::vector<Configration>;


private:
    std::mutex mtx;

};

#endif // CONFIGRATIONDAO_H
