
CXX = g++
CXXFLAGS = -Wall -Iinclude
CC = gcc
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = dext
all = $(TARGET)
SQLITE_OBJ = libs\sqlite3.o

$(TARGET): $(OBJ) $(SQLITE_OBJ)
	$(CXX) $(OBJ) $(SQLITE_OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

#objs:
	#$(CC) -c libs/sqlite3.c -o libs/sqlite3.o

#com:
	#$(CXX) index.cpp earth libs/sqlite3.o -o out.exe

#RR:
	#$(CXX) -o outRR Rstarter.cpp `R CMD config --cppflags --ldflags` -lR lRInside

#exe:
	#out.exe
