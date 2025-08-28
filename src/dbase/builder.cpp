
#include <iostream>

#include "tables.h"
#include "queries.h"
#include "conn.h"

int callback (void* NotUsed, int argc, char** argv, char** colname) {
    for(int i = 0; i < argc; i++){
        std::cout << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::string eqname = "eq" + std::string(argv[0]);
    /*Table Earthquake(eqname);
    Earthquake.add("StationLat", "TEXT");
    Earthquake.add("StationLon", "TEXT");
    Earthquake.add("MaxAcc", "TEXT");
    std::cout << Earthquake.query << std::endl;
    Earthquake.create();*/
    //database is locked
    return 0;
}

void buildEqsTables() {
    std::string query = select_all("earthquakes");
    connect(query, callback); //connects
}

void buildTables() {
    Table Earthquakes("Earthquakes");
    Table Stations("Stations");

    Earthquakes.add("OriginTime", "TEXT UNIQUE");
    Earthquakes.add("Lat", "TEXT");
    Earthquakes.add("Lon", "TEXT");
    Earthquakes.add("Depth", "TEXT");
    Earthquakes.add("Magnitude", "TEXT");

    Stations.add("Code", "TEXT UNIQUE");
    Stations.add("Lat", "TEXT");
    Stations.add("Lon", "TEXT");
    Stations.add("Height", "TEXT");
    Stations.add("ScaleFactor", "TEXT");

    Earthquakes.create();
    Stations.create();
}
