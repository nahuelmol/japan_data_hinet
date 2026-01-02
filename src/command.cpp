#include <vector>
#include <unordered_map>
#include <algorithm>
#include <typeinfo>
#include <iostream>
#include <string>

#include "command.h"

Command::Command(int argc, char* argv[]) {
    this->many_args = argc;
    this->args = argv;
    if (argc == 1) {
        std::cout << "alone command introduced" << std::endl;
        return;
    } else {
        this->available = true;
    }
    this->root = argv[1];
    if(this->root == "add"){
        if(argc > 1){
            if(argc > 2) {
                this->target = this->args[2];
                if (argc > 3) {
                    this->filename = this->args[3];
                    this->options = argv + 4;
                    this->set_options();
                }
            }
        }
    } else if (this->root == "ask"){
        if(argc > 1){
            if(argc > 2) {
                this->target = this->args[2];
                if (argc > 3) {
                    this->options = argv + 4;
                    this->set_options();
                }
            }
        }
    } else if (this->root == "ch"){
        if(argc > 1){
            if(argc > 2) {
                this->target = this->args[2];
                if (argc > 3) {
                    this->filename = this->args[3];
                    this->options = argv + 4;
                    this->set_options();
                }
            }
        }
    } else if (this->root == "del"){
        if(argc > 1){
            if(argc > 2) {
                this->target = this->args[2];
                if (argc > 3) {
                    this->options = argv + 4;
                    this->set_options();
                }
            }
        }
    } else if (this->root == "migrate"){
        std::cout << "migrating" << std::endl;
    } else if (this->root == "db"){
        std::cout << "dbiding" << std::endl;
        if(argc > 1){
            if(argc > 2) {
                this->target = this->args[2];
                if (argc > 3) {
                    this->filename = this->args[3];
                    this->options = argv + 4;
                    this->set_options();
                }
            }
        }
    } else {
        std::cout << "not working" << std::endl;
    }
}

void Command::set_options() {
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

void Command::see_cmd() {
    std::cout << "checking" << std::endl;
}

