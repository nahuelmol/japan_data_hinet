

void addRecords() {
    std::cout eq_name = ;
    std::cout << "----adding " << eq_name << std::endl;
    std::string epath = "./data/" + eq_name;
    std::string filename;
    recordfile  = "/" + takeRecord(epath);
    std::string recordpath = epath + recordfile;
    auto result = wave_header_reader(recordpath);
    if(result.first){
        std::vector<std::string> data(result.second.begin(), result.second.begin() + 5);
        std::string query = insert_record(data);
        connect(query, addCall);
    } else {
        std::cout << "ERR" << std::endl;
    };
}
void askRecords() {
    std::string query = all_table("records");
    connect(query, allTableCall);
}

