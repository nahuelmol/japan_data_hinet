
#include "earthquake.cpp"
#include "station.cpp"


void command(int argc, char* argv[]){
    std::vector<std::string> cmds = ["add", "del", "help", "?"];
    std::vector<std::string> secs = ["eq", "stat"];
    std::string cmd;
    if(argc > 1){
        cmd = argv[1];
        sec = argv[2];
        if(cmd = "add"){
            if(sec == "eq"){
                addEarthquake();
            } else if(sec == "stat") {
                addStation();
            }
        }
    } else if (argc == 1){
        cmd = argv[1];
        if(cmd == "add") {
            std::cout << "what do you want to add?" << std::endl;
        } else if ((cmd == "help") & (cmd == "?")) {
            std::cout << "this are the available commands" << std::endl;
        }
    } else {
        std::cout << "there is no arguments" << std::endl;
    }
}

