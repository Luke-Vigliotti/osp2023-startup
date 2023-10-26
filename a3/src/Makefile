# Makefile

CXX = g++
CXXFLAGS = -Wall -Werror -std=c++20
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
