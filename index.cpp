#include<iostream>
#include<string>
#include<fstream>

#include"tabber.cpp"

int main() {
    std::string dir = "data.txt";
    /*std::ifstream input;
    input.open(dir);
    if(input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "not opened"<< std::endl;
    }*/
    tab(dir);
    return 0;
}



