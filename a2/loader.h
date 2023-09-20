#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>
#include "pcb.h" // Include your PCB class header file

class Loader {
public:
    // Function to load data from the datafile and create PCB objects
    static std::vector<pcb> loadFromFile(const std::string& filename);

    // Other loader-related functions if needed

private:
    // Private member variables or functions as needed
};

#endif // LOADER_H
