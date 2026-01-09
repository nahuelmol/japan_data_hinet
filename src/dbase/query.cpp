#include <iostream>
#include <vector>

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

std::string select_all(std::string tablename){
    std::string query = "SELECT * FROM " + tablename + ";";
    return query;
}

std::string select_earthquake(std::string earthquakename){
    std::string query = "SELECT * FROM earthquakes WHERE earthquakename="+ earthquakename + ";";
    return query;
}

std::string select_station(std::string statname){
    std::string query = "SELECT * FROM stations WHERE name=" + statname + ";";
    return query;
}

std::string delete_record(std::string tablename, int id){
    std::string query = "DELETE * FROM " + tablename + "WHERE id=" + std::to_string(id) + ");";
    return query;
}

std::string select(std::string codename, std::string target) {
    codename = "'" + codename + "'";
    std::string query = "SELECT * FROM " + target + " WHERE Code=" + codename + ";";
    std::cout << query << std::endl;
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

std::string all_table(std::string tablename){
    std::string ecolumns = "ORIGIN TIME | LAT | LON | DEPTH | MAGNITUDE |";
    std::string scolumns = "STATIONNAME | LAT | LON | PREFECTURE CODE |";
    std::string pcolumns = "PREFECTURENAME | PREFECTURE CODE | REGISTERED STATIONS |";

    if(tablename == "earthquakes"){
        std::cout << ecolumns << std::endl;
    } else if (tablename == "stations"){
        std::cout << scolumns << std::endl;
    } else if (tablename == "prefectures"){
        std::cout << pcolumns << std::endl;
    }

    std::string query = "SELECT * FROM " + tablename + ";";
    return query;
}

