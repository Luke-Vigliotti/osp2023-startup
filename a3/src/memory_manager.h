// memory_manager.h
#pragma once

#include <cstddef>
#include <list>

// Define an allocation struct to keep track of each allocated chunk
struct Allocation {
    std::size_t size;
    void* space;
};

extern std::list<Allocation> occupiedChunks;
extern std::list<Allocation> freeChunks;

// Function to allocate memory
void* alloc(std::size_t chunk_size);

// Function to deallocate memory
void dealloc(void* chunk);

// Function to allocate memory using First Fit strategy
void* firstFitAlloc(std::size_t chunk_size);

// Function to allocate memory using Best Fit strategy
void* bestFitAlloc(std::size_t chunk_size);