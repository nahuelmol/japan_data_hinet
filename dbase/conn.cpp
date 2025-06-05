//here should be a connection to a database (sql)
#include <iostream>
extern "C" {
#include "sqlite3.h"
}

int call(void* NotUsed, int argc, char** argv, char** colname) {
    for(int i = 0; i < argc; i++){
        std::cout << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    std::cout << std::endl;
    return 0;
}

void connect(std::string sql) {
    sqlite3* db;
    char* errMsg = 0;
    int rc = sqlite3_open("dbase.db", &db);
    if(rc != SQLITE_OK) {
        std::cerr << "DB CONNECTION ERR: " << sqlite3_errmsg(db) << std::endl;
    }

    rc = sqlite3_exec(db, sql.c_str(), call, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SENTENCE ERR: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    sqlite3_close(db);
}

