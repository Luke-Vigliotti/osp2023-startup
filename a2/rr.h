#pragma once
#include "simulator.h" // Include the simulator class header file

// Class definition for RR scheduler
class RR {
public:
    // Constructor
    RR(Simulator& sim, osp2023::time_type quantum);

    // Function to run the RR scheduling algorithm
    void runRR();

private:
    Simulator& simulator; // Reference to the simulator instance
    osp2023::time_type quantum; // Time quantum for RR scheduling
};
