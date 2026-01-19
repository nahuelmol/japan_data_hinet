#include <dirent.h>
#include <iostream>

#include "calls.h"
#include "query.h"
#include "conn.h"
#include "command.h"
#include "util.h"
#include "ascii.h"

std::string takeRecord(std::string epath) {
    const char* final_path = epath.c_str();
    DIR* dir = opendir(final_path);
    if (dir == nullptr) {
        std::cerr << "err: idk: " << std::endl;
    }
    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if(is_format(entry->d_name, "UD")){
            std::string record = entry->d_name;
            std::string recordpath = epath + "/" + record;
            std::cout << "record:" << recordpath << std::endl;
            auto result = wave_header_reader(recordpath);
            if(result.first){
                std::vector<std::string> data(result.second.begin(), result.second.end());
                std::string query = insert_record(data);
                std::cout << "query: " << query << std::endl;
                connect(query, addCall);
            } else {
                std::cout << "ERR" << std::endl;
            };
        }
    }
    std::string response = "response";
    return response;
}

void addRecords(Command* cmd) {
    DIR* dir = opendir("data/");
    if (dir == nullptr) {
        std::cerr << "err: idk: " << std::endl;
    }
    dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        std::cout << "----adding " << entry->d_name << std::endl;
        std::string earthquake = entry->d_name;
        std::string epath = "./data/" + earthquake;
        takeRecord(epath);
    }
}

void askRecords(Command* cmd) {
    std::string query = all_table("records");
    connect(query, allTableCall);
}

