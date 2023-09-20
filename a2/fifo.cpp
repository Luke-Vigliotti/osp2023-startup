#include <iostream>
#include <fstream>
#include <vector>
#include "pcb.h" // Include your PCB class header file
#include "simulator.h" // Include your simulator class header file

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./fifo datafile" << std::endl;
        return 1;
    }

    // Get the datafile name from the command line arguments
    std::string datafile = argv[1];

    // Load data from the datafile and create PCB objects
    std::vector<pcb> pcbList = Loader::loadFromFile(datafile);

    // Initialize your simulator and ready queue
    Simulator simulator;
    simulator.initializeReadyQueue(pcbList);

    // Main simulation loop
    while (!simulator.isSimulationComplete()) {
        // Get the next process to run based on FIFO scheduling
        PCB nextProcess = simulator.getNextProcessFIFO();

        if (!nextProcess.isValid()) {
            // Handle the case when the ready queue is empty or all processes are completed
            break;
        }

        // Execute the process and update statistics
        simulator.executeProcess(nextProcess);
    }

    // Display statistics
    simulator.displayStatistics();

    return 0;
}
