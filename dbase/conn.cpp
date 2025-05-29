//here should be a connection to a database (sql)
#include <iostream>
extern "C" {
#include "sqlite3.h"
}

void connect(std::string sql) {
    sqlite3* db;
    char* errMsg = 0;
    int rc = sqlite3_open("dbase.db", &db);
    if(rc != SQLITE_OK) {
        std::cerr << "err: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "db connected" << std::endl;
    }

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error al insertar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Registro insertado correctamente." << std::endl;
    }
    sqlite3_close(db);
}

