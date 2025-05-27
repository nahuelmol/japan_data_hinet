
std::string insert_earthquake(std::string ename) {
    std::string query = "INSERT INTO EARTHQUAKES VALUES (earthquakename " + ename + " TEXT);"
    return query;
}

std::string select_all(std::string tablename){
    std::string query = "SELECT * FROM " + tablename + ";";
    return query;
}

std::string select_earthquake(std::string earthquakename){
    std::string query = "SELECT * FROM earthquakes WHERE earthquakename="+earthquake";";
    return query;
}

std::string delete_record(std::string tablename, int id){
    std::string query = "DELETE * FROM " + tablename + "WHERE id=" + id + ");";
    return query;
}
