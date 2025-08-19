
#include <dirent.h>
#include <iostream>
#include <string>
#include "connect.h"
#include <vector>

void listStations(std::string path, std::string code) {
    const char* final_path = path.c_str();
    DIR* dir = opendir(final_path);
    if (dir == nullptr) {
        std::cerr << "folder can't be open" << std::endl;
    }
    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if(is_format(entry->d_name, "UD")){
            std::string starts = entry->d_name;
            if(starts.substr(0,3) == code){
                std::cout << entry->d_name << std::endl;
            }
            if(code == "all") {
                std::cout << entry->d_name << std::endl;
            }
        }
    }
}

void lookForStations(std::string earthQuake){
    //para un earthquake especifico
    const char* target = "./data/";
    std::string path = std::string(target) + earthQuake + ".knt";
    const char* final_path = path.c_str();
    std::cout << "Looking for... " << earthQuake << std::endl;
    std::cout << "Available stations:";

    //se lo busca como .knt
    DIR* dir = opendir(final_path);
    if (dir == nullptr) {
        std::cerr << "earthquake doesn't exists" << std::endl;
    }
    std::cout << "Prefecture code: " << std::endl;
    std::string code;
    std::cin >> code;
    //this are stations available but not in database
    listStations(path, code);
}

std::vector<std::string> takeStationData(std::string code) {
    std::string lat;
    std::string lon;
    std::string height;
    std::string scale;
    std::cout << "lat: ";
    std::cin >> lat;
    std::cout << "lon: ";
    std::cin >> lon;
    std::cout << "height: ";
    std::cin >> height;
    std::cout << "scale factor: ";
    std::cin >> scale;
    std::vector<std::string> data = {code,lat,lon,height,scale};
    return data;
}

void addStation(){
    std::cout << "Tell me the earthquake" << std::endl;
    std::string earthQuake;
    std::cin >> earthQuake;
    lookForStations(earthQuake); //this will show stations in filesystem
    std::cout << "Which station do you want to add, tell me the station code: " << std::endl;
    std::string codename;
    std::cin >> codename;
    //the following checks if station already exists in database
    std::string query = select(codename, "stations");
    connect(query, NULL);
    //if not
    std::vector<std::string> data = takeStationData(codename);
    query = insert_station(data);
    connect(query, NULL);
}

//SEEDING
std::vector<std::string> filter(std::vector<std::string> rawdata, std::string targetable) {
    int i = 0;
    std::vector<std::string> newdata;
    if(targetable == "station") {
        int places[] = {5,6,7,8,13};
        for(int place : places){
            newdata.push_back(rawdata[place]);
        }
        return newdata;
    } else if (targetable == "earthquakes") {
        //things
    } else {
        std::cout << "unrecognized target" << std::endl;
    }
}

void enterDir(std::vector<std::string> earthquakes){
    for(std::string eq : earthquakes){
        //one eq at a time
        std::string eqpath = "./data/" + eq;
        DIR* dir = opendir(eqpath.c_str());
        if (dir == nullptr) {
            std::cerr << "ERR:cannot open earthquake" << std::endl;
        }
        dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if(is_format(entry->d_name, "UD")){
                std::string station_path = eqpath + "/" + (entry->d_name);
                auto result = wave_header_reader(station_path);
                if(result.first){
                    std::vector<std::string> clean_data = filter(result.second, "station");
                    std::string query = insert_station(clean_data);
                    connect(query, NULL);
                } else {
                    std::cout << "ERR: station data cannot be extracted" << std::endl;
                };
            }
        }
    }
}

void seedStations(){
    const char* final_path = "./data";
    DIR* dir = opendir(final_path);
    if (dir == nullptr) {
        std::cerr << "earthquake doesn't exists" << std::endl;
    }
    dirent* entry;
    std::vector<std::string> earthquakes;
    while ((entry = readdir(dir)) != nullptr) {
        if(is_format(entry->d_name, "knt")){
            earthquakes.push_back(entry->d_name);
        }
    }
    enterDir(earthquakes);
}

