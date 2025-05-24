#include<iostream>
#include<string>
#include<fstream>

#include "adder.cpp"
#include "tabber.cpp"

int main(int argc, char* argv[]) {
    command(argc, argv);
    //this will take tabbed files
    std::string dir = "data.txt";
    tab(dir);
    return 0;
}



