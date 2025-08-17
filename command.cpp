#include<vector>
#include<unordered_map>
#include<algorithm>
#include<typeinfo>


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

    bool forced = false;

    Command(int argc, char* argv[]) {
        this->many_args = argc;
        this->args = argv;
        this->root = argv[1];

        if(this->root == "add"){
            if(argc > 1){
                if(argc > 2) {
                    this->target = this->args[2];
                    this->options = argv + 3;
                    this->set_options();
                }
            }
        } else if (this->root == "del"){
            std::cout << "del" << std::endl;
        } else {
            std::cout << "not working" << std::endl;
        }
    }

    void set_options() {
        for(char** p = this->options; *p != nullptr; ++p) {
            auto it = std::find(this->ava_k_n_v.begin(), this->ava_k_n_v.end(), *p);
            if(it != this->ava_k_n_v.end()) {
                std::cout << *(p+1) << std::endl;
                this->kv_flags[*p] = *(p+1);
            } 
            auto in = std::find(this->ava_keys.begin(), this->ava_keys.end(), *p);
            if(in != this->ava_keys.end()) {
                if(*in == "-f"){
                    this->forced = true;
                }
            }
        }
    }

    void see_cmd() {
        std::cout << "checking" << std::endl;
    }
};

