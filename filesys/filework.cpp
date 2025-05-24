#include <algorithm>
#include <dirent.h>

bool is_tar(std::string name){
    std::string format = "";
    for (auto c = name.rbegin(); c != name.rend(); ++c) {
        if((*c) == '.') {
            break;
        }
        format = format + std::string(1,*c);
    } 
    std::reverse(format.begin(), format.end());
    if(format == "tar"){
        std::cout << "\ntar file: " << name << std::endl;
        return true;
    } 
    return false;
}

