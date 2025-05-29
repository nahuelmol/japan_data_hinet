
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
    listStations(path, code);
    /*
    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if((entry->d_name != ".") && (entry->d_name != "..")){
            if (is_tar(entry->d_name) == true){
                std::cout << "this should be decompressed" << std::endl;
            }
            if (is_format(entry->d_name, "knt") == true) {
                std::cout << "entering folder" << std::endl;
                listStations(entry->d_name);
            }
        };
    }
    closedir(dir);
    */
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
