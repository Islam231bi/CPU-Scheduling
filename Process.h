#ifndef PROCESS_H
#define PROCESS_H

class Process
{

public:
    char name;
    int arrival_time;
    int service_time;
    int priority;
    int finish;
    int turnaround;
    float norm_turn;
    
    Process(char name, int arrival_time, int service_time, int priority);
    ~Process();
};

#endif