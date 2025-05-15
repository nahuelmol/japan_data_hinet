#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <map>

int main() {
    std::ifstream file("IBR0191104111716.UD");
    if(!file.is_open()){
        std::cerr << "no se pudo abrir" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<double>acels;
    bool reading = false;
    while(std::getline(file, line)){
        std::stringstream ss(line);
        double val;
        if(ss << val) {
            reading =true;
            acels.push_back(val);
            while(ss >> val){
                acels.push_back(val);
            }
        } else if(reading){
            break;
        }
    }
    file.close();

    for (size_t i = 0; i < std::min<size_t>(10, acels.size()); ++i) {
        std::cout << "sample " << i << ": " << acels[i] << " m/s^2" << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////
    

    
    std::ifstream archivo("IBR0191104111716.kwin");
    if(!archivo){
        std::cerr << "i cannot open this thing" << std::endl;
        return 1;
    } else {
        std::cout << "opened" << std::endl;
    }
    std::map<std::string, std::string> parameters;
    std::string linea;
    while(std::getline(archivo, linea)){
        std::cout << "line ->" << line << std::endl;
        size_t sep = linea.find(':');
        if(sep != std::string::npos) {
            std::string clave = linea.substr(0, sep);
            std::string valor = linea.substr(sep + 1);
            parameters[clave] = valor;
        }
    }
    archivo.close();
    for( const auto& par: parameters){
        std::cout << par.first << ": " << par.second << std::endl;
    }
    return 0;
}
