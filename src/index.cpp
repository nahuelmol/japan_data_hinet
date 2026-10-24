#include<iostream>
#include<string>
#include<fstream>

#include "command.h"
#include "earthquake.h"
#include "station.h"
#include "record.h"
#include "query.h"
#include "builder.h"
#include "map.h"
#include "export.h"
#include "util.h"
#include "conn.h"
#include "calls.h"

void switcher(Command* cmd) {
    if (cmd->root == "add") {
        if (cmd->target == "eq") {
            addEarthquake(cmd);
        } else if(cmd->target == "st") {
            addStation(cmd);
        } else if(cmd->target == "rd") {
            addRecords(cmd);
        } else {
            std::cout << "not recognized target" << std::endl;
        }
    } else if (cmd->root == "ask") {
        std::tuple <std::string, bool> response;
        if(cmd->target == "eq"){
            askEarthquake(cmd);
        } else if(cmd->target == "st") {
            response = select("stations", cmd->kv_flags);
        } else if(cmd->target == "rd") {
            response = select("records", cmd->kv_flags);
        } else {
            std::cout << "not recognized target" << std::endl;
        }
        if (std::get<1>(response) == true) {
            connect(std::get<0>(response), addCall);
        }
    } else if (cmd->root == "del") {
        if (cmd->target == "eq") {
            delEarthquake(cmd);
        } else if (cmd->target == "st") {
            delStation();
        } else {
            std::cout << "delete: unrecognized target" << std::endl;
        }
    } else if (cmd->root == "db") {
        if(cmd->target == "build"){
            std::cout << "building tables" << std::endl;
            buildTables();
        } else if(cmd->target == "seed"){
            std::cout << "seeding" << std::endl;
            //seedStations();
        } else {
            std::cout << "not recognized target" << std::endl;
        }
    } else if (cmd->root == "outs") {
        if(cmd->target == "map:build"){
            std::cout << "making map" << std::endl;
            //makeMap();
        } else if(cmd->target == "csv:build"){
            std::cout << "making csv" << std::endl;
            //makeCSV();
        } else {
            std::cout << "not recognized target" << std::endl;
        }
    } else {
        std::cout << "not recognized root command" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    Command* cmd = new Command(argc, argv);
    if(cmd->available) {
        switcher(cmd);
    } else {
        std::cout << "----getting out" << std::endl;
    }
    return 0;
}

