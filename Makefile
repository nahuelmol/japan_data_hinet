
CXX = g++
CC = gcc

objs:
	$(CC) -c dbase/sqlite3.c -o sqlite3.o

com:
	$(CXX) index.cpp sqlite3.o -o out.exe

exe:
	out.exe
