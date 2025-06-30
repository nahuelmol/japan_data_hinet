#include <iostream>

class Table {
public:
    std::vector<std::string> fields;
    std::string query;
    std::string tablename;

    Table (std::string tablename) {
        this->tablename = tablename;
    }

    
    void add (std::string namefield, std::string typefield) {
        std::string field = namefield +" "+ typefield;
        this->fields.push_back(field);
    }
    void create() {
        std::string query = "CREATE TABLE " + (this->tablename) + " (\n";
        for(auto field : (this->fields)) {
            query = query + field + ",\n";
        }
        query = (query.substr(0, query.size() - 2)) + ");";
        this->query = query;
        connect(query, NULL);
    }
};

