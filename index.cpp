#include<iostream>
#include<string>
#include<fstream>

int main() {
    std::string dir = "data.txt";
    std::ifstream input;
    input.open(dir);
    if(input.is_open()) {
        std::cout << "opened"<< std::endl;
        std::string line;
        while (std::getline(input, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "not opened"<< std::endl;
    }
    return 0;
}



