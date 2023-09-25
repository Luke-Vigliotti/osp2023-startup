// simulator.cpp

#include "simulator.h"
#include <iostream>
#include <algorithm> // For std::accumulate

// Constructor, if needed
Simulator::Simulator() {
    // Initialize member variables as needed
}

std::deque<pcb>& Simulator::getReadyQueue() {
    return readyQueue;
}

// Function to initialize the ready queue with pcb objects
void Simulator::initializeReadyQueue(const std::vector<pcb>& pcbList) {
    // Copy pcbs from pcbList to the readyQueue
    for (const pcb& p : pcbList) {
        readyQueue.push_back(p);
    }
}

// Function to check if the simulation is complete
bool Simulator::isSimulationComplete() {
    return readyQueue.empty();
}

// Function to select the next process to run based on FIFO scheduling
pcb Simulator::getNextProcessFIFO() {
    if (!readyQueue.empty()) {
        pcb nextProcess = readyQueue.front();
        readyQueue.pop_front();
        return nextProcess;
    } else {
        // Return an empty pcb or handle the case when the ready queue is empty
        return pcb(-1, -1); // Assuming pcb() creates an invalid pcb object
    }
}

// Scheduling algorithm: Shortest Job First (SJF)
pcb Simulator::getNextProcessSJF() {
    if (!readyQueue.empty()) {
        // Sort the ready queue by burst time (SJF)
        std::sort(readyQueue.begin(), readyQueue.end(), [](const pcb& a, const pcb& b) {
            return a.getTotalTime() < b.getTotalTime();
        });

        pcb nextProcess = readyQueue.front();
        readyQueue.pop_front();
        return nextProcess;
    }
    // Return an empty/invalid PCB if the ready queue is empty
    return pcb(-1, -1);
}

// Scheduling algorithm: Round Robin (RR)
pcb Simulator::getNextProcessRR() {
    if (!readyQueue.empty()) {
        pcb nextProcess = readyQueue.front();
        readyQueue.pop_front();
        return nextProcess;
    }
    // Return an empty/invalid PCB if the ready queue is empty
    return pcb(-1, -1);
}

// Function to execute a process and update statistics
void Simulator::executeProcess(const pcb& process) {
    // Simulate process execution

    // Calculate turnaround time
    osp2023::time_type turnaroundTime = getCurrentTime() - process.getArrivalTime();
    process.setTurnaroundTime(turnaroundTime);

    // Calculate waiting time
    osp2023::time_type waitingTime = turnaroundTime - process.getTotalTime();
    process.setWaitingTime(waitingTime);

    // Calculate response time
    osp2023::time_type responseTime = process.getStartTime() - process.getArrivalTime();
    process.setResponseTime(responseTime);

}

// Function to calculate and display statistics
void Simulator::displayStatistics() {
    // Calculate and display statistics like average turnaround time, waiting time and response time

    // Calculate average turnaround time
    double totalTurnaroundTime = 0.0;
    for (const pcb& process : completedProcesses) {
        totalTurnaroundTime += process.getTurnaroundTime();
    }
    double averageTurnaroundTime = totalTurnaroundTime / completedProcesses.size();

    // Calculate average waiting time
    double totalWaitingTime = 0.0;
    for (const pcb& process : completedProcesses) {
        totalWaitingTime += process.getWaitingTime();
    }
    double averageWaitingTime = totalWaitingTime / completedProcesses.size();

    // Calculate average response time
    double totalResponseTime = 0.0;
    for (const pcb& process : completedProcesses) {
        totalResponseTime += process.getResponseTime();
    }
    double averageResponseTime = totalResponseTime / completedProcesses.size();

    // Display the statistics
    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << " ms" << std::endl;
    std::cout << "Average Waiting Time: " << averageWaitingTime << " ms" << std::endl;
    std::cout << "Average Response Time: " << averageResponseTime << " ms" << std::endl;

}
