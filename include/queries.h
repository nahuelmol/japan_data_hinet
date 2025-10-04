#ifndef QUERIES_H
#define QUERIES_H

#include <vector>

std::string insert_station(std::vector<std::string> data);
std::string insert_earthquake(std::vector<std::string> data);
std::string select_all(std::string tablename);
std::string select_earthquake(std::string earthquakename);
std::string delete_record(std::string tablename, int id);
std::string select(std::string codename, std::string target);
std::string create_idx(std::string idx,std::string table, std::string field);
std::string drop_idx(std::string idx);

#endif

