
#include <algorithm>
#include <dirent.h>

bool is_format(std::string name, std::string is){
    std::string format = "";
    for (auto c = name.rbegin(); c != name.rend(); ++c) {
        if((*c) == '.') {
            break;
        }
        format = format + std::string(1,*c);
    } 
    std::reverse(format.begin(), format.end());
    if(format == is){
        return true;
    } 
    return false;
}
