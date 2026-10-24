
CXX = g++
CXXFLAGS = -Wall -Iinclude
CC = gcc
SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = ss
all = $(TARGET)

$(TARGET): $(OBJ) $(SQLITE_OBJ)
	$(CXX) $(OBJ) $(SQLITE_OBJ) -o $@ -lsqlite3

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

