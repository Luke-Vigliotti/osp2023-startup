#include <iostream>
#include <string>
#include "loader.h" // Include your loader class header file
#include "simulator.h" // Include your simulator class header file

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./scheduler <scheduling_algorithm> <quantum (for RR)> <datafile>" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    std::string schedulingAlgorithm = argv[1];

    if (schedulingAlgorithm != "FIFO" && schedulingAlgorithm != "SJF" && schedulingAlgorithm != "RR") {
        std::cerr << "Invalid scheduling algorithm. Choose 'FIFO', 'SJF', or 'RR'." << std::endl;
        return 1;
    }

    if (schedulingAlgorithm == "RR" && argc != 4) {
        std::cerr << "Usage for RR: ./scheduler RR <quantum> <datafile>" << std::endl;
        return 1;
    }

    // Parse additional arguments based on the selected scheduling algorithm
    std::string datafile;
    int quantum = -1;

    if (schedulingAlgorithm == "RR") {
        quantum = std::stoi(argv[2]);
        datafile = argv[3];
    } else {
        datafile = argv[2];
    }

    // Load data from the datafile and create PCB objects
    std::vector<pcb> pcbList = Loader::loadFromFile(datafile);

    // Initialize your simulator and ready queue
    Simulator simulator;
    simulator.initializeReadyQueue(pcbList);

    // Run the selected scheduling algorithm
    if (schedulingAlgorithm == "FIFO") {
        // Run FIFO scheduling algorithm
    } else if (schedulingAlgorithm == "SJF") {
        // Run SJF scheduling algorithm
    } else if (schedulingAlgorithm == "RR") {
        // Run RR scheduling algorithm with the specified quantum
    }

    // Display statistics
    simulator.displayStatistics();

    return 0;
}
