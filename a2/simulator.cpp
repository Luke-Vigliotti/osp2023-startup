#include "simulator.h"
#include "pcb.h"
#include <iostream>
#include <algorithm> // For std::accumulate

// Constructor, if needed
Simulator::Simulator() {
    // Initialize member variables as needed
}

// Function to initialize the ready queue with PCB objects
void Simulator::initializeReadyQueue(const std::vector<pcb>& pcbList) {
    // Copy PCBs from pcbList to the readyQueue
    for (const pcb& pcb : pcbList) {
        readyQueue.push_back(pcb);
    }
}

// Function to check if the simulation is complete
bool Simulator::isSimulationComplete() {
    return readyQueue.empty();
}

// Function to select the next process to run based on FIFO scheduling
PCB Simulator::getNextProcessFIFO() {
    if (!readyQueue.empty()) {
        PCB nextProcess = readyQueue.front();
        readyQueue.pop_front();
        return nextProcess;
    } else {
        // Return an empty PCB or handle the case when the ready queue is empty
        return PCB(); // Assuming PCB() creates an invalid PCB object
    }
}

// Function to execute a process and update statistics
void Simulator::executeProcess(const PCB& process) {
    // Simulate process execution
    // Update process-specific statistics (e.g., turnaround time, waiting time)

    // For example, you might increment a timer for execution time
    // and update the process's start time, end time, etc.
}

// Function to calculate and display statistics
void Simulator::displayStatistics() {
    // Calculate and display statistics like average turnaround time, waiting time, response time, etc.
    // You can use the member variables and data you've collected during execution.

    // For example, you can calculate average turnaround time as follows:
    // double averageTurnaroundTime = ... // Calculate the average

    // Display the statistics
    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << std::endl;
    // Display other statistics as needed
}
