// memory_manager.cpp
#include "memory_manager.h"
#include <list>
#include <unistd.h>
#include <iostream>
#include <limits>

// Define fixed partition sizes
const std::size_t partition_sizes[] = {32, 64, 128, 256, 512};

// Global linked lists to manage occupied and free chunks
std::list<Allocation> occupiedChunks;
std::list<Allocation> freeChunks;

// Function to allocate memory
void* alloc(std::size_t chunk_size, const std::string& allocationStrategy) {
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

    // Select the allocation strategy based on a global variable
    if (allocationStrategy == "firstfit") {
        return firstFitAlloc(chunk_size);
    } else if (allocationStrategy == "bestfit") {
        return bestFitAlloc(chunk_size);
    } else {
        std::cerr << "Invalid allocation strategy: " << allocationStrategy << std::endl;
        abort(); // Terminate the program
    }
}

    void dealloc(void* chunk) {
    for (auto it = occupiedChunks.begin(); it != occupiedChunks.end(); ++it) {
        if (it->space == chunk) {
            freeChunks.push_back(*it);
            occupiedChunks.erase(it);
            return; // Deallocation successful
        }
    }

    std::cerr << "Fatal error: Attempt to free unallocated memory." << std::endl;
    abort(); // Terminate the program
}

    void* firstFitAlloc(std::size_t chunk_size) {
    for (auto it = freeChunks.begin(); it != freeChunks.end(); ++it) {
        if (it->size >= chunk_size) {
            // Use the first chunk that is big enough
            void* allocated_space = it->space;
            occupiedChunks.push_back(*it);
            freeChunks.erase(it);
            return allocated_space;
        }
    }

    // If no chunk is large enough, allocate a new chunk
    void* allocated_space = sbrk(chunk_size);
    if (allocated_space == reinterpret_cast<void*>(-1)) {
        return nullptr; // Allocation failed
    }

    Allocation allocation = {chunk_size, allocated_space};
    occupiedChunks.push_back(allocation);

    return allocated_space;
}

    void* bestFitAlloc(std::size_t chunk_size) {
    // Find the best-fit chunk
    std::list<Allocation>::iterator best_fit = freeChunks.end();
    std::size_t best_fit_size = std::numeric_limits<std::size_t>::max();

    for (auto it = freeChunks.begin(); it != freeChunks.end(); ++it) {
        if (it->size >= chunk_size && it->size < best_fit_size) {
            best_fit = it;
            best_fit_size = it->size;
        }
    }

    // If a best-fit chunk is found, allocate from it
    if (best_fit != freeChunks.end()) {
        if (best_fit->size > chunk_size) {
            // If the best-fit chunk is larger than needed, split it
            void* allocated_space = best_fit->space;
            best_fit->space = static_cast<char*>(allocated_space) + chunk_size;
            best_fit->size -= chunk_size;

            Allocation allocated_chunk = {chunk_size, allocated_space};
            occupiedChunks.push_back(allocated_chunk);

            return allocated_space;
        } else {
            // Use the entire best-fit chunk
            Allocation allocated_chunk = {best_fit->size, best_fit->space};
            occupiedChunks.push_back(allocated_chunk);
            freeChunks.erase(best_fit);

            return allocated_chunk.space;
        }
    }

    // No suitable chunk found for allocation
    return nullptr;
}