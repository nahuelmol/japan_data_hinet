
#include <vector>

#include "filesys/filework.cpp"
#include "earthquake.cpp"
#include "station.cpp"
#include "command.cpp"

#include "dbase/checker.cpp"

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
                } else {
                    std::cout << "args" << std::endl;
                }
            } else if(sec == "stat") {
                addStation();
            }
        } else if(cmd == "check") {
            //nothing 
            //check if exists
            if(sec == "eq"){
                if(argc > 3) { 
                    third = argv[3];
                    std::cout << "I should check if " << third << " exists" << std::endl;
                } else {
                    std::cout << "args" << std::endl;
                }

            }
        } else if(cmd == "ask") {
            if(sec == "eqs"){
                std::string query = allTable("earthquakes");
                connect(query);
            } else if (sec == "prefs") {
                std::string query = allTable("prefectures");
            } else if (sec == "stats") {
                std::string query = allTable("stations");
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

