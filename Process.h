#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <vector>

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
    bool entered;
    float HRRN_ratio;
    int SRT_time;
    int service_remain;
    int start_time;
    int FB_priority;
    int last_instance;
    std::vector<char> process_stat;
    
    Process(char name, int arrival_time, int service_time, int priority);
    Process() = default;
    void Reset();
    ~Process();
};

#endif