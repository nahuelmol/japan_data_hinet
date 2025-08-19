#ifndef CONN_H
#define CONN_H

int call(void* NotUsed, int argc, char** argv, char** colname);
void connect(std::string sql, int (*callback)(void*, int, char**, char**));

#endif

