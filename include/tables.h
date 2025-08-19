#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>

class Table {
public:
    std::vector<std::string> fields;
    std::string query;
    std::string tablename;

    Table(std::string tablename);
    void add(std::string namefield, std::string typefield);
    void create();
};

#endif
