
CXX = g++
CC = gcc

objs:
	$(CC) -c libs/sqlite3.c -o libs/sqlite3.o

com:
	$(CXX) index.cpp libs/sqlite3.o -o out.exe

exe:
	out.exe
