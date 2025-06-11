
void makeMap() {
    //this will take data from an earthquake table and then create a map
    std::string query = select_all("stations");
    connect(query);
}


