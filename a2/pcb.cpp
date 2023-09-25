#include "pcb.h"

// Constructor for the pcb class
pcb::pcb(osp2023::id_type id, osp2023::time_type total_time)
    : id(id), total_time(total_time), time_used(0), total_wait_time(0), last_cpu_time(0) {
    // Initialize other member variables as needed
}

// Member function to get the process ID
osp2023::id_type pcb::getID() const {
    return id;
}

// Member function to get the total time needed to run the process
osp2023::time_type pcb::getTotalTime() const {
    return total_time;
}

// Member function to get the time used by the process so far
osp2023::time_type pcb::getTimeUsed() const {
    return time_used;
}

// Member function to set the time used by the process
void pcb::setTimeUsed(osp2023::time_type time) {
    time_used = time;
}

// Member function to get the total wait time of the process
osp2023::time_type pcb::getTotalWaitTime() const {
    return total_wait_time;
}

// Member function to update the total wait time of the process
void pcb::updateTotalWaitTime(osp2023::time_type wait_time) {
    total_wait_time += wait_time;
}

// Member function to get the last CPU time of the process
osp2023::time_type pcb::getLastCPUTime() const {
    return last_cpu_time;
}

// Member function to update the last CPU time of the process
void pcb::updateLastCPUTime(osp2023::time_type cpu_time) {
    last_cpu_time = cpu_time;
}

