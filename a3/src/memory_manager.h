// memory_manager.h
#pragma once

#include <cstddef>

// Define an allocation struct to keep track of each allocated chunk
struct Allocation {
    std::size_t size;
    void* space;
};

// Function to allocate memory
void* alloc(std::size_t chunk_size);

// Function to deallocate memory
void dealloc(void* chunk);
