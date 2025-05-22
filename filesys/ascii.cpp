#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <map>

int main() {
    std::vector<std::string> fields;
    std::vector<std::string> values;
    std::ifstream file("IBR0191104111716.UD");
    if(!file.is_open()){
        std::cerr << "this file cannot be opened" << std::endl;
        return 1;
    }
    std::string line;
    int linecounter = 0;
    while(std::getline(file, line)){
        std::string field;
        std::string value;
        bool infield = true;
        bool invalue = false;
        bool spaced = false;
        bool tab = false;
        for (auto c = line.begin(); c != line.end(); ++c) {
            if(!(*c == ' ')) {
                if(spaced == true) {
                    spaced = false;
                }
                if(infield == true){
                    field += *c;
                }
                if(invalue == true) {
                    value += *c;
                }
            } else {
                if(spaced == false) {
                    spaced = true;
                    //cuando encuentre el segundo espacio haré el push back
                } else {
                    //cuando encuentre el segundo espacio hago el cambio a valores
                    if(infield == true){
                        infield = false;
                        invalue = true;
                    }
                    spaced = false;
                }
            }
        } 
        fields.push_back(field);
        values.push_back(value);
        linecounter += 1;
        if(linecounter == 17){
            //corto al header
            break;
        }
    }
    file.close();
    for(int i = 0; i< 16;i++) {
        std::cout << fields[i] << " -> " << values[i] << std::endl;
    }
    //guardo en in diccionary
    return 0;
}
