
#include <vector>

#include "filesys/filework.cpp"
#include "earthquake.cpp"
#include "station.cpp"
#include "command.cpp"

void command(int argc, char* argv[]){
    std::vector<std::string> cmds = {"add", "print", "decom" , "del", "help", "?"};
    std::vector<std::string> secs = {"eq", "stat"};
    std::string cmd;
    if(argc > 1){
        cmd = argv[1];
        //if_target(argv);
        Command command(argv[1], argv[2]);
        std::string sec;
        std::string third;
        sec = argv[2];
        if(cmd == "add"){
            if(sec == "eq"){
                if(argc > 3) { 
                    third = argv[3];
                    addEarthquake(third);
                }
            } else if(sec == "stat") {
                addStation();
            }
        }
    } else if (argc == 1){
        cmd = argv[1];
        Command command(argv[1], "NULL");
        if(cmd == "add") {
            std::cout << "what do you want to add?" << std::endl;
        } else if ((cmd == "help") & (cmd == "?")) {
            std::cout << "this are the available commands" << std::endl;
        }
    } else {
        std::cout << "there is no arguments" << std::endl;
    }
}

