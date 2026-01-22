#ifndef QUERY_H
#define QUERY_H

#include <vector>
#include "command.h"

std::string insert_station(std::vector<std::string> data);
std::string insert_earthquake(std::vector<std::string> data);
std::string insert_record(std::vector<std::string> data);

std::string select_all(std::string tablename);
std::string select_earthquake(std::string earthquakename);
std::string select_station(Command* cmd);
std::string select_record(Command* cmd);
std::string select(std::string codename, std::string target);

std::string delete_record(std::string tablename, int id);
std::string create_idx(std::string idx,std::string table, std::string field);
std::string drop_idx(std::string idx);
std::string all_table(std::string tablename);

#endif

