#ifndef POLICY_H
#define POLICY_H

#include <iostream>

class Policy
{

public:
    std::string name;
    int number;
    int quanta;
    
    Policy(int number, int quanta);
    ~Policy();
};

#endif