#include<iostream>
#include<string>
#include<fstream>

#include "command.cpp"
#include "earthquake.cpp"
#include "station.cpp"

void switcher(Command* cmd) {
    if (cmd.root == "add") {
        if (cmd.target == "eq") {
            addEarthquake(cmd);
        } else if(cmd.target == "stat")
            addStation(cmd);
        } else {
            std::cout << "not recognized target" << std::endl;
        }
    } else if (cmd.root == "ask") {
        if(cmt.target == "eq"){
            std::string query = allTable("earthquakes");
            connect(query, allTableCall);
        }
    } else if (cmd.root == "ch") {
        if (cmd.target == "eq") {
            std::cout << "check eq" << std::endl;
        } else if (cmd.target == "stat") {
            std::cout << "check stat" << std::endl;
        } else {
            std::cout << "unrecognized target" << std::endl;
        }
    } else if (cmd.root == "del") {
        if (cmd.target == "eq") {
            std::cout << "del eq" << std::endl;
        } else if (cmd.target == "stat") {
            std::cout << "del stat" << std::endl;
        } else {
            std::cout << "unrecognized target" << std::endl;
        }
    } else if (cmd.root == "migrate") {
        std::cout << "this process takes data from filesystem and migrate it to the database" << std::endl;
        if (cmd.target == "eq"){
        } else if (cmd.target == "stat") {
        } else if (cmd.target == "all") {
        } else {
            std::cout << "not recognized target" << std::endl;
        }
    } else {
        std::cout << "not recognized root command" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    Command* cmd = new Command(argc, argv);
    switcher(cmd);
    return 0;
}

