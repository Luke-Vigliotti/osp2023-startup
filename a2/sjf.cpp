#include <algorithm>
#include "sjf.h" // Include the SJF scheduler header file

// Constructor for the SJF scheduler
SJF::SJF(Simulator& sim) : simulator(sim) {
    // Initialize any member variables if needed
}

// Function to run the SJF scheduling algorithm
void SJF::runSJF() {
    // Access the ready queue from the simulator
    std::deque<pcb>& readyQueue = simulator.getReadyQueue();

    // Main SJF scheduling logic
    while (!readyQueue.empty()) {
        // Sort the ready queue by CPU burst time (shortest job first)
        std::sort(readyQueue.begin(), readyQueue.end(), [](const pcb& a, const pcb& b) {
            return a.getTotalTime() < b.getTotalTime();
        });

        // Get the process with the shortest burst time
        pcb nextProcess = readyQueue.front();
        readyQueue.pop_front();

        int burstTime = nextProcess.getTotalTime(); 

        // Execute the process and update statistics using simulator methods
        simulator.executeProcess(nextProcess);
    }

    // Calculate and display statistics using simulator methods
    simulator.displayStatistics();
}
