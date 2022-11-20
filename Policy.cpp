#include "Policy.h"

Policy::Policy(int number, int quanta) {
    this->number = number;
    
    switch (number)
    {
    case 1:
        this->name = "FCFS";
        break;
    case 2:
        this->name = "RR";
        break;
    case 3:
        this->name = "SPN";
        break;
    case 4:
        this->name = "SRT";
        break;
    case 5:
        this->name = "HRRN";
        break;
    case 6:
        this->name = "FB-1";
        break;
    case 7:
        this->name = "FB-2i";
        break;
    case 8:
        this->name = "Aging";
        break;
    default:
        break;
    }

    this->quanta = quanta;
}

Policy::~Policy(){}