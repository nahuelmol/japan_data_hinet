#include <iostream>
#include <vector>

void wavereader(std::string content){
    //this function will work with the wave
    std::string number;
    std::vector<std::string> numbers;
    for(auto c: content) {
        if(c != ' ') {
            number += int(c);
        } else {
            numbers.push_back(number);
            number = "";
        }
    }
    std::cout << "\nPayload";
    std::cout << "data size: " << numbers.size() << std::endl;
}
