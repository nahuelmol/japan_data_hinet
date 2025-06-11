
#include <dirent.h>
#include <iostream>
#include <string>


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
void addStation(){
    std::cout << "Tell me the earthquake" << std::endl;
    std::string earthQuake;
    std::cin >> earthQuake;
    lookForStations(earthQuake); //this will show stations
    std::cout << "Now, tell me the station name" << std::endl;
    std::string station;
    std::cin >> station;
}

//SEEDING

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
                //std::vector<std::string> data = takeStationData(station_path);
                auto result = wave_header_reader(station_path);
                if(result.first){
                    std::vector<std::string> data(result.second.begin() + 5, result.second.end());
                    std::string query = insert_station(data);
                    connect(query);
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

