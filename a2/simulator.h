#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <vector>
#include <deque> // Include the necessary header for your chosen data structure (e.g., deque)
#include "pcb.h" // Include your PCB class header file

class Simulator {
public:
    Simulator(); // Constructor, if needed

    // Function to initialize the ready queue with PCB objects
    void initializeReadyQueue(const std::vector<pcb>& pcbList);

    // Function to check if the simulation is complete
    bool isSimulationComplete();

    // Function to select the next process to run based on FIFO scheduling
    pcb getNextProcessFIFO();

    // Function to execute a process and update statistics
    void executeProcess(const pcb& process);

    // Function to calculate and display statistics
    void displayStatistics();

private:
    std::deque<pcb> readyQueue; // Use the appropriate data structure for your ready queue
    // Other member variables for tracking statistics, etc.

    // Add any other private member functions or variables as needed
};

#endif // SIMULATOR_H
