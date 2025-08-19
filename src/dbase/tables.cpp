#include <iostream>
#include "tables.h"
#include "conn.h"

Table::Table(std::string tablename) {
    this->tablename = tablename;
}
    
void Table::add(std::string namefield, std::string typefield) {
    std::string field = namefield +" "+ typefield;
    this->fields.push_back(field);
}

void Table::create() {
    std::string query = "CREATE TABLE " + (this->tablename) + " (\n";
    for(auto field : (this->fields)) {
        query = query + field + ",\n";
    }
    query = (query.substr(0, query.size() - 2)) + ");";
    this->query = query;
    connect(query, NULL);
}

