// test_allocator.cpp
#include "memory_manager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void performAllocDealloc(const std::string& datafile) {
    std::ifstream file(datafile);

    if (!file.is_open()) {
        std::cerr << "Failed to open datafile: " << datafile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "alloc") {
            std::size_t chunk_size;
            file >> chunk_size;

            void* allocated_chunk = alloc(chunk_size);
            if (allocated_chunk) {
                std::cout << "Allocated: Address=" << allocated_chunk << ", Total Size=" << chunk_size << ", Used Size=" << chunk_size << std::endl;
            } else {
                std::cerr << "Allocation failed." << std::endl;
            }
        } else if (line == "dealloc") {
            if (!occupiedChunks.empty()) {
                void* last_allocated_chunk = occupiedChunks.back().space;
                dealloc(last_allocated_chunk);
                occupiedChunks.pop_back();
                std::cout << "Deallocated: Address=" << last_allocated_chunk << std::endl;
            } else {
                std::cerr << "Deallocation failed: No memory to deallocate." << std::endl;
            }
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " datafile" << std::endl;
        return 1;
    }

    // Determine the allocation strategy based on the program name
    std::string programName = argv[1];
    std::string allocationStrategy;

    if (programName == "./firstfit") {
        allocationStrategy = "firstfit";
    } else if (programName == "./bestfit") {
        allocationStrategy = "bestfit";
    } else {
        std::cerr << "Invalid program name: " << programName << std::endl;
        return 1;
    }

    // Set the allocation strategy
    performAllocDealloc(argv[2]);

    std::cout << "Allocated List:" << std::endl;
    for (const auto& chunk : occupiedChunks) {
        std::cout << "Address=" << chunk.space << ", Total Size=" << chunk.size << ", Used Size=" << chunk.size << std::endl;
    }

    std::cout << "Free List:" << std::endl;
    for (const auto& chunk : freeChunks) {
        std::cout << "Address=" << chunk.space << ", Total Size=" << chunk.size << std::endl;
    }

    return 0;
}
