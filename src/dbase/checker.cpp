
#include <iostream>

std::string allTable(std::string tablename){
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

std::string listStat(std::string stat){
    std::string query = "SELECT * FROM stations WHERE name=" + stat;
    return query;
}
