#include "Process.h"

Process::Process(char name, int arrival_time, int service_time, int priority){
    this->name = name;
    this->arrival_time = arrival_time;
    this->service_time = service_time;
    this->priority = priority;
    this->finish_time = 0;
    this->start_time = 0;
    this->turnaround_time = 0;
    this->norm_turn = 0;
    this->completed = false;
    this->entered = false; 
    this->HRRN_ratio = 0;
    this->SRT_time = 0;
    this->FB_priority = 0;
    this->service_remain = service_time;
    this->last_instance = 0;
}

void Process::Reset(){
    this->finish_time = 0;
    this->turnaround_time = 0;
    this->norm_turn = 0;
    this->completed = false;
    this->entered = false;
    this->HRRN_ratio = 0;
    this->SRT_time = 0;
    this->service_remain = this->service_time;
    this->start_time = 0;
    this->FB_priority = 0;
    this->last_instance = 0;
}


Process::~Process(){}