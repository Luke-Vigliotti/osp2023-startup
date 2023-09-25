#include "rr.h" // Include the RR scheduler header file

// Constructor for the RR scheduler
RR::RR(Simulator& sim, osp2023::time_type quantum) : simulator(sim), quantum(quantum) {
    // Initialize any member variables if needed
}

// Function to run the RR scheduling algorithm
void RR::runRR() {
    // Access the ready queue from the simulator
    std::deque<pcb>& readyQueue = simulator.getReadyQueue();

    // Main RR scheduling logic
    while (!readyQueue.empty()) {
        // Get the process at the front of the ready queue
        pcb nextProcess = readyQueue.front();
        readyQueue.pop_front();

        // Execute the process for the quantum or until it finishes
        osp2023::time_type remainingTime = nextProcess.getTotalTime() - nextProcess.getTimeUsed();
        osp2023::time_type executionTime = std::min(remainingTime, quantum);

        // Update the time used for the process
        nextProcess.setTimeUsed(nextProcess.getTimeUsed() + executionTime);

        // Add the process back to the ready queue if it's not completed
        if (nextProcess.getTimeUsed() < nextProcess.getTotalTime()) {
            readyQueue.push_back(nextProcess);
        }

        // Update statistics using simulator methods
        simulator.executeProcess(nextProcess);
    }

    // Calculate and display statistics using simulator methods
    simulator.displayStatistics();
}
