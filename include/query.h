#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include "command.h"
#include <tuple>

std::string insert_station(std::vector<std::string> data);
std::string insert_earthquake(std::vector<std::string> data);
std::string insert_record(std::vector<std::string> data);

std::tuple<std::string, bool> select(std::string table, std::unordered_map<std::string, std::string> kv_flags);

std::string delete_earthquake();
std::string delete_station();
std::string delete_record(std::string tablename, int id);

std::string create_idx(std::string idx,std::string table, std::string field);
std::string drop_idx(std::string idx);

#endif

