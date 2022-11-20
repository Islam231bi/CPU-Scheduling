#include "Process.h"

Process::Process(char name, int arrival_time, int service_time, int priority){
    this->name = name;
    this->arrival_time = arrival_time;
    this->service_time = service_time;
    this->priority = priority;
}
Process::~Process(){}