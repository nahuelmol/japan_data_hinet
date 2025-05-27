//here should be a connection to a database (sql)
#include <iostream>
extern "C" {
#include "sqlite3.h"
}

void connect() {
    sqlite3* db;
    int rc = sqlite3_open("dbase.db", &db);
    if(rc != SQLITE_OK) {
        std::cerr << "err: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "db connected" << std::endl;
    }
    sqlite3_close(db);
}

