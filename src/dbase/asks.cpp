#include <iostream>

int allTableCall(void* NotUsed, int argc, char** argv, char** colname){
    for(int i = 0; i < argc; i++){
        std::cout << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::cout << std::endl;
}

