#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <map>

int main() {
    std::vector<std::string> fields;
    std::ifstream file("IBR0191104111716.UD");
    if(!file.is_open()){
        std::cerr << "this file cannot be opened" << std::endl;
        return 1;
    }
    std::string line;
    int linecounter = 0;
    while(std::getline(file, line)){
        std::string field;
        bool infield = true;
        bool space = false;
        for (auto c = line.begin(); c != line.end(); ++c) {
            if(!(*c == ' ') & (infield == true)) {
                field += *c;
                infield = true;
            } else {
                if(space == false) {
                    space = true;
                } else {
                    fields.push_back(field);
                    field = "";
                    infield = true;
                    break;
                }
            }
        } 
        linecounter += 1;
        if(linecounter == 17){
            break;
        }
    }
    for(auto c : fields) {
        std::cout << "field: " << c << std::endl;
    }
    file.close();
    return 0;
}
