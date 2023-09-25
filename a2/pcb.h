#include <iostream>
#include "types.h"

#pragma once  // tells the compiler to only include this file once
              /**
 * the process control block - represents a process that needs to be executed in
 * our simulator. Please note the I used some custom types of osp2023::time_type
 * and osp2023::id_type. these are just aliases to long integers but they are
 * more meaningful type names, hinting at how they will be used. Please see
 * their definitions in types.h.
 **/
class pcb {
    // the unique process id
    osp2023::id_type id;
    // the total time that a process / job should run for
    osp2023::time_type total_time;
    // the time that has been used so far for this process
    osp2023::time_type time_used;
    // the priority level for this process
    // how much time has this process spent waiting for the cpu?
    osp2023::time_type total_wait_time;
    // what time was this process last on the cpu?
    osp2023::time_type last_cpu_time;

    osp2023::time_type arrival_time;

    osp2023::time_type turnaround_time;

    osp2023::time_type waiting_time;

    osp2023::time_type start_time;
    
    osp2023::time_type response_time;

   public:
    // max and min duration for a process in our system.
    static constexpr osp2023::time_type MAX_DURATION = 100;
    static constexpr osp2023::time_type MIN_DURATION = 10;

    // Constructor
    pcb(osp2023::id_type id, osp2023::time_type total_time);

    pcb(osp2023::id_type processID, osp2023::time_type burstTime);
  
    // Getter for process ID
    osp2023::id_type getID() const;

    // Getter for total time needed to run the process
    osp2023::time_type getTotalTime() const;

    // Getter for time used by the process so far
    osp2023::time_type getTimeUsed() const;

    // Setter for time used by the process
    void setTimeUsed(osp2023::time_type time);

    // Getter for total wait time of the process
    osp2023::time_type getTotalWaitTime() const;

    // Update total wait time of the process
    void updateTotalWaitTime(osp2023::time_type wait_time);

    // Getter for the last CPU time of the process
    osp2023::time_type getLastCPUTime() const;

    // Update the last CPU time of the process
    void updateLastCPUTime(osp2023::time_type cpu_time);

    // Getter for arrival time
    osp2023::time_type getArrivalTime() const;

    // Setter for turnaround time
    void setTurnaroundTime(osp2023::time_type turnaroundTime);

    // Setter for waiting time
    void setWaitingTime(osp2023::time_type waitingTime);

    // Getter for start time
    osp2023::time_type getStartTime() const;

    // Setter for response time
    void setResponseTime(osp2023::time_type responseTime);
};
