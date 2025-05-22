#include <iostream>

void readfile(std::string content){
    //this function will work with the wave
    std::string number;
    std::vector<std::string> numbers;
    for(char c: content) {
        if((*c) != ' ') {
            number += (*c);
        } else {
            numbers.push_back(number);
            number = "";
        }
    }

}
