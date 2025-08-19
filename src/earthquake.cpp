#include <dirent.h>
#include <iostream>

#include "filesys/ascii.cpp"

#include "dbase/conn.cpp"
#include "dbase/queries.cpp"
#include "util.h"
#include "command.h"

std::string takeFirstStation(std::string epath) {
    const char* final_path = epath.c_str();
    DIR* dir = opendir(final_path);
    if (dir == nullptr) {
        std::cerr << "err: idk: " << std::endl;
    }
    dirent* entry;
    std::string firstStation;
    while ((entry = readdir(dir)) != nullptr) {
        if(is_format(entry->d_name, "UD")){
            firstStation = entry->d_name;
            break;
        }
    }
    return firstStation;
}

int addCall(void* NotUsed, int argc, char** argv, char** colname) {
    for(int i = 0; i < argc; i++){
        std::cout << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::cout << std::endl;
}

void addEarthquake(Command* cmd) {
    std::string eq = cmd->filename;
    std::string eq_name = eq + ".knt";
    std::cout << "----adding " << eq_name << std::endl;
    std::string epath = "./data/" + eq_name;
    //read the first station header in the earthquake folder
    std::string filename;
    filename = "/" + takeFirstStation(epath);
    std::string filepath = epath + filename;
    auto result = wave_header_reader(filepath);
    if(result.first){
        std::vector<std::string> data(result.second.begin(), result.second.begin() + 5);
        //enter to the database
        std::string query = insert_earthquake(data);
        connect(query, addCall);
    } else {
        std::cout << "ERR" << std::endl;
    };
}
