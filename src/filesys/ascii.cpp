#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

#include "waveextracts.h"

std::pair<bool, std::vector<std::string>> wave_header_reader(std::string path) {
    std::vector<std::string> fields;
    std::vector<std::string> values;
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr << "cannot open file" << std::endl;
        return {false, {}};
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
        if (value.length() == 0) {
            value = "None";
        }
        values.push_back(value);
        linecounter += 1;
        if(linecounter == 17){
            //corto al header
            linecounter = 0;
            break;
        }
    }
    
    std::string wavecontent = "";
    while(std::getline(file, line)){
        if(linecounter > 17){
            wavecontent += (line);
        } 
        linecounter++;
    }
    file.close();
    std::vector<std::string> data;
    return { true, values };
}
