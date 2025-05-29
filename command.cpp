
class Command {
public:
    std::string cmd;
    std::string file_target;
    
    Command(std::string name, std::string target) {
        this->cmd = name;
        this->file_target = target;
        if(target == "NULL") {
            std::cout << "there is no target specified" << std::endl;
        }
    }
};

