
std::string insert_earthquake(std::vector<std::string> data) {
    std::string query = std::string("INSERT INTO EARTHQUAKES VALUES (") +
        "'" + data[0] + "', " +
        data[1] + ", " +
        data[2] + ", " +
        data[3] + ", " +
        data[4] + 
        ");";
    return query;
}

std::string select_all(std::string tablename){
    std::string query = "SELECT * FROM " + tablename + ";";
    return query;
}

std::string select_earthquake(std::string earthquakename){
    std::string query = "SELECT * FROM earthquakes WHERE earthquakename="+ earthquakename + ";";
    return query;
}

std::string delete_record(std::string tablename, int id){
    std::string query = "DELETE * FROM " + tablename + "WHERE id=" + std::to_string(id) + ");";
    return query;
}
