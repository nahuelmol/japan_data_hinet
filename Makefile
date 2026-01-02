
CXX = g++
CXXFLAGS = -Wall -Iinclude
CC = gcc
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = ss
all = $(TARGET)
SQLITE_OBJ = libs\sqlite3.o

$(TARGET): $(OBJ) $(SQLITE_OBJ)
	$(CXX) $(OBJ) $(SQLITE_OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

