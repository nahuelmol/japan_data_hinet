#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <unordered_map>

class Command {
public:
    std::string root;
    std::string target;
    std::vector<std::string> availableRoots = {"add", "print", "decom" , "del", "help", "?"};
    std::vector<std::string> ava_k_n_v = {"-ts"};
    std::vector<std::string> ava_keys  = {"-f"};
    
    char** options = {};
    char** args;
    int many_args;
    std::unordered_map<std::string, std::string> kv_flags;
    std::unordered_map<std::string, bool> k_flags;
    std::string filename;

    bool forced = false;

    Command(int argc, char* argv[]);
    void set_options();
    void see_cmd();
};

#endif

