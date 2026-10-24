#include <iostream>
#include <vector>
#include "command.h"
#include <tuple>
#include <sstream>

std::string insert_station(std::vector<std::string> data) {
    std::string query = std::string("INSERT INTO STATIONS VALUES (") +
        "'" + data[0] + "', " +
        "'" + data[1] + "', " +
        "'" + data[2] + "', " +
        "'" + data[3] + "', " +
        "'" + data[9] + "'" + 
        ");";
    return query;
}

std::string insert_earthquake(std::vector<std::string> data) {
    std::string query = std::string("INSERT INTO EARTHQUAKES VALUES (") +
        "'" + data[0] + "', " +
        data[1] + ", " +
        data[2] + ", " +
        data[3] + ", " +
        data[4] + 
        ");";
    return query;
}

std::string delete_earthquake() {
    std::string key;
    std::string val;

    std::cout << "Please state a condition\nFirst the column: " << std::endl;
    std::cin >> key;
    std::cout << "Now, the value: " << std::endl;
    std::cin >> val;
    std::string query = std::string("DELETE FROM EARTHQUAKES WHERE ") + key + "=" + val + ";";
    return query;
}

std::string delete_station() {
    std::string key;
    std::string val;

    std::cout << "Please state a condition\nFirst the column: " << std::endl;
    std::cin >> key;
    std::cout << "Now, the value: " << std::endl;
    std::cin >> val;
    std::string query = std::string("DELETE FROM STATION WHERE ") + key + "=" + val + ";";
    return query;
}

std::string insert_record(std::vector<std::string> data) {
    std::string query = std::string("INSERT INTO RECORDS VALUES (") +
        "'" + data[0] + "', " +
        "'" + data[1] + "', " +
        "'" + data[2] + "', " +
        "'" + data[3] + "', " +
        "'" + data[4] + "', " +
        "'" + data[5] + "', " +
        "'" + data[6] + "', " +
        "'" + data[7] + "', " +
        "'" + data[8] + "', " +
        "'" + data[9] + "', " +
        "'" + data[10] + "', " +
        "'" + data[12] + "', " +
        "'" + data[15] + "'" +
        ");";
    return query;
}

std::tuple<std::string, bool> select(std::string table, std::unordered_map<std::string, std::string> kv_flags){

    std::string cond = kv_flags["c"];
    if (cond == "all") {
        std::string query = "SELECT * FROM " +table+ ";";
        return {query, true};
    } else if (cond.find(':') != std::string::npos){
        std::stringstream ss(cond);
        std::string field;
        std::string confi;
        std::string e;
        int i = 1;

        while (std::getline(ss, e, ':')) {
            if (i == 1) {
                field = e;
            } else if (i == 2) {
                confi = e;
            }
            i++;
        }
        std::string query = "SELECT * FROM " +table+ " WHERE " +field+ "=" +confi+ ";";
        return {query, true};
    } else {
        return {"not query available", false};
    }
}

std::string delete_record(std::string tablename, int id){
    std::string query = "DELETE * FROM " + tablename + "WHERE id=" + std::to_string(id) + ");";
    return query;
}

std::string create_idx(std::string idx,std::string table, std::string field) {
    std::string query = "CREATE INDEX "+idx+" ON "+table+" ("+field+");";
    return query;
}

std::string drop_idx(std::string idx) {
    std::string query = "DROP INDEX "+idx+";";
    return query;
}


