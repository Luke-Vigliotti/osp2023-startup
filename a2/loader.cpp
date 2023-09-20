#include "loader.h" // Include your loader class header file
#include <fstream>
#include <iostream>

// Function to load data from the datafile and create PCB objects
std::vector<pcb> Loader::loadFromFile(const std::string& filename) {
    std::vector<pcb> pcbList;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open datafile " << filename << std::endl;
        return pcbList;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Split the line into ProcessID and BurstTime
        size_t commaPos = line.find(",");
        if (commaPos != std::string::npos) {
            int processID = std::stoi(line.substr(0, commaPos));
            int burstTime = std::stoi(line.substr(commaPos + 1));

            // Create a pcb object and add it to the list
            pcb pcbObj(processID, burstTime);
            pcbList.push_back(pcbObj);
        }
    }

    file.close();
    return pcbList;
}
