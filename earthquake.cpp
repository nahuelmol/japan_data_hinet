
#include <dirent.h>
#include <iostream>

void addEarthquake(std::string eq) {
    std::string year = eq.substr(0,3);
    std::string month= eq.substr(4,6);
    std::string day  = eq.substr(7,9);
    std::string hour = eq.substr(10,15);

    std::string complete_name = eq + ".knt";
    std::cout << "adding earthquake" << std::endl;
    const char* folder = "./data/";
}

