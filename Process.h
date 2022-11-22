#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

class Process
{

public:
    char name;
    int arrival_time;
    int service_time;
    int priority;
    int finish_time;
    int turnaround_time;
    float norm_turn;
    bool completed;
    float HRRN_ratio;
    int SRT_time;
    int service_remain;
    int start_time;
    
    Process(char name, int arrival_time, int service_time, int priority);
    Process() = default;
    void Reset();
    ~Process();
};

#endif