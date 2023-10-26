// memory_manager.cpp
#include "memory_manager.h"
#include <list>
#include <unistd.h> // Include the necessary headers

// Define fixed partition sizes
const std::size_t partition_sizes[] = {32, 64, 128, 256, 512};

// Global linked lists to manage occupied and free chunks
std::list<Allocation> occupiedChunks;
std::list<Allocation> freeChunks;

// Function to allocate memory
void* alloc(std::size_t chunk_size) {
    // Check if the requested size is valid and within the fixed partition sizes
    bool valid_size = false;
    for (std::size_t size : partition_sizes) {
        if (chunk_size == size) {
            valid_size = true;
            break;
        }
    }

    if (!valid_size) {
        return nullptr; // Invalid allocation size
    }

    // Check if there's a free chunk with the exact requested size in the free list
    for (auto it = freeChunks.begin(); it != freeChunks.end(); ++it) {
        if (it->size == chunk_size) {
            // Use this free chunk and move it to occupiedChunks
            void* allocated_space = it->space;
            occupiedChunks.push_back(*it);
            freeChunks.erase(it);
            return allocated_space;
        }
    }

    // If no exact-size free chunk is found, search for a larger chunk and split it if necessary
    for (auto it = freeChunks.begin(); it != freeChunks.end(); ++it) {
        if (it->size > chunk_size) {
            // Split the larger chunk into two parts: allocated and free
            void* allocated_space = it->space;
            Allocation allocated_chunk = {chunk_size, allocated_space};
            occupiedChunks.push_back(allocated_chunk);

            // Update the size and space of the remaining free chunk
            it->size -= chunk_size;
            it->space = static_cast<char*>(it->space) + chunk_size;

            return allocated_space;
        }
    }

    // If no suitable free chunk is found, allocate a new chunk using sbrk
    void* allocated_space = sbrk(chunk_size);
    if (allocated_space == reinterpret_cast<void*>(-1)) {
        return nullptr; // Allocation failed
    }

    // Record the allocation and add it to occupiedChunks
    Allocation allocation = {chunk_size, allocated_space};
    occupiedChunks.push_back(allocation);

    return allocated_space;
}
