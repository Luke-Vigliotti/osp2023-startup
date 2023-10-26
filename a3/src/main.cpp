// main.cpp
#include "memory_manager.h"
#include <iostream>

int main() {
    // Example usage of alloc and dealloc
    int* a = static_cast<int*>(alloc(sizeof(int)));
    int* b = static_cast<int*>(alloc(sizeof(int)));

    *a = 42;
    *b = 10;

    std::cout << "a: " << *a << ", b: " << *b << std::endl;

    dealloc(a);
    dealloc(b);

    return 0;
}
