# Makefile

CXX = g++
CXXFLAGS = -Wall -Werror -std=c++20

all: firstfit bestfit

firstfit: memory_manager.cpp test_allocator.cpp
	$(CXX) $(CXXFLAGS) -o firstfit memory_manager.cpp test_allocator.cpp -DALLOC_STRATEGY=\"firstfit\"

bestfit: memory_manager.cpp test_allocator.cpp
	$(CXX) $(CXXFLAGS) -o bestfit memory_manager.cpp test_allocator.cpp -DALLOC_STRATEGY=\"bestfit\"

clean:
	rm -f firstfit bestfit

