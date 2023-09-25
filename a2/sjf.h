#pragma once
#include "simulator.h" // Include the simulator class header file
#include <deque>

// Class definition for SJF scheduler
class SJF {
public:
    // Constructor
    SJF(Simulator& sim);

    // Function to run the SJF scheduling algorithm
    void runSJF();

private:
    Simulator& simulator; // Reference to the simulator instance
};
