# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executables
TARGETS = fifo sjf rr

all: $(TARGETS)

fifo: fifo.cpp pcb.cpp loader.cpp simulator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

sjf: sjf.cpp pcb.cpp loader.cpp simulator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

rr: rr.cpp pcb.cpp loader.cpp simulator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGETS)

.PHONY: all clean
