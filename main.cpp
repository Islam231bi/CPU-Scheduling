#include <bits/stdc++.h>
#include "Process.h"
#include "Policy.h"


// Struct with operator to compare Process objects according to arrival time
struct less_than_av
{
    inline bool operator() (const Process& p1, const Process& p2)
    {
        return (p1.arrival_time < p2.arrival_time);
    }
};

// Struct with operator to compare Process objects according to service time
struct less_than_st
{
    inline bool operator() (const Process& p1, const Process& p2)
    {
        return (p1.service_time < p2.service_time);
    }
};

// Function for printing stats of policy 
void print_stats(std::string name, std::vector<Process>& _process_list, float mean1 , float mean2){
    std::cout<<name<<"\n";
    std::cout<<"Process";
    std::cout<<"    |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(3) << _process_list[i].name << std::setw(3) << "|";
    }
    std::cout<<"\n";

    std::cout<<"Arrival";
    std::cout<<"    |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(3) << _process_list[i].arrival_time << std::setw(3) << "|";
    }
    std::cout<<"\n";

    std::cout<<"Service";
    std::cout<<"    |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(3) << _process_list[i].service_time << std::setw(3) << "|";
    }
    std::cout<<" Mean|\n";

    std::cout<<"Finish";
    std::cout<<"     |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(3) << _process_list[i].finish_time << std::setw(3) << "|";
    }
    std::cout<<"-----|\n";

    std::cout<<std::fixed<<std::setprecision(2);
    std::cout<<"Turnaround";
    std::cout<<" |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(3) << _process_list[i].turnaround_time << std::setw(3) << "|";
    }
    std::cout << std::setw(5) << mean1 <<"|";
    std::cout<<"\n";

    std::cout<<"NormTurn";
    std::cout<<"   |";
    for(int i = 0 ; i < _process_list.size() ; i++){
        std::cout << std::setw(5) << _process_list[i].norm_turn << "|";
    }
    std::cout << std::setw(5) << mean2 << "|";
    std::cout<<"\n\n";
}

void FCFS (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    // Finish time calculations
    _process_list[0].finish_time = _process_list[0].arrival_time + _process_list[0].service_time;
    _process_list[0].completed = true;

    for(int i = 1 ; i < _process_list.size() ; i++){
        _process_list[i].finish_time = _process_list[i].service_time + _process_list[i-1].finish_time;
        _process_list[i].completed = true;
    }

    // Turnaround time calculations
    float turn_sum = 0;
    for(int i = 0 ; i < _process_list.size() ; i++){
        _process_list[i].turnaround_time = _process_list[i].finish_time - _process_list[i].arrival_time;
        turn_sum+=_process_list[i].turnaround_time;
    }

    // Normalized turnaround time calculations
    float norm_turn_sum = 0;
    for(int i = 0 ; i< _process_list.size() ; i++){
        _process_list[i].norm_turn = (float)_process_list[i].turnaround_time / (float)_process_list[i].service_time;
        norm_turn_sum+=_process_list[i].norm_turn;
    }

    // Mean calculations
    float turnaround_mean = turn_sum / (float) _process_list.size(); 
    float norm_mean = norm_turn_sum / (float) _process_list.size();

    if( mode == "trace") {
        std::cout<<"FCFS  ";
        for(int i = 0 ; i <=last_instance ; i++){
            std::cout<<i%10<<" ";
        }
        std::cout<<"\n";
        for(int i = 0 ; i<=47 ; i++){
            std::cout<<"-";
        }


    }
    else if (mode == "stats") {
        print_stats("FCFS", _process_list, turnaround_mean, norm_mean);
    }
}

void RR (std::vector<Process>& _process_list, std::string mode, int last_instance, int quanta){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }
    

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        // print_stats("RR", _process_list, turnaround_mean, norm_mean);

    }
}

void SPN (std::vector<Process>& _process_list, std::string mode, int last_instance){
   // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    // Finish time calculations
    _process_list[0].finish_time = _process_list[0].arrival_time + _process_list[0].service_time;
    _process_list[0].completed = true;

    int current_time = _process_list[0].finish_time;

    // sorting remaining processes by service time 
    sort(_process_list.begin()+1, _process_list.end(), less_than_st());

    int i = 1;
    for(; i < _process_list.size(); i++){
        if(_process_list[i].arrival_time <= current_time){
            if(!_process_list[i].completed){
                _process_list[i].completed = true;
                current_time = current_time + _process_list[i].service_time;
                _process_list[i].finish_time = current_time;
                i = 0;
            }
        }
    }
    sort(_process_list.begin()+1, _process_list.end(), less_than_av());

    // Turnaround time calculations
    float turn_sum = 0;
    for(int i = 0 ; i < _process_list.size() ; i++){
        _process_list[i].turnaround_time = _process_list[i].finish_time - _process_list[i].arrival_time;
        turn_sum+=_process_list[i].turnaround_time;
    }

    // Normalized turnaround time calculations
    float norm_turn_sum = 0;
    for(int i = 0 ; i< _process_list.size() ; i++){
        _process_list[i].norm_turn = (float)_process_list[i].turnaround_time / (float)_process_list[i].service_time;
        norm_turn_sum+=_process_list[i].norm_turn;
    }

    // Mean calculations
    float turnaround_mean = turn_sum / (float) _process_list.size(); 
    float norm_mean = norm_turn_sum / (float) _process_list.size();

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        print_stats("SPN", _process_list, turnaround_mean, norm_mean);
    }
}

void SRT (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        // print_stats("SRT", _process_list, turnaround_mean, norm_mean);

    }
}

void HRRN (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    // Finish time calculations
    // We choose first process to go next since response ratio is 1 for all processes 
    _process_list[0].finish_time = _process_list[0].arrival_time + _process_list[0].service_time;
    _process_list[0].completed = true;

    int current_time = _process_list[0].finish_time;

    int cnt = 0;
    Process *max_p = nullptr;
    float max_wait = 0;
    while(cnt < _process_list.size() - 1 ){
        for(int i = 1; i < _process_list.size(); i++){
            if(_process_list[i].completed == false){
                _process_list[i].HRRN_ratio = ((float) (current_time - _process_list[i].arrival_time 
                + _process_list[i].service_time))/
                (float)(_process_list[i].service_time);
                max_p = _process_list[i].HRRN_ratio >= max_wait ? &_process_list[i] : max_p;
                max_wait = _process_list[i].HRRN_ratio >= max_wait ? _process_list[i].HRRN_ratio : max_wait;
            }
        }
        max_wait = 0;
        max_p->completed = true;
        current_time = current_time + max_p->service_time;
        max_p->finish_time = current_time;
        cnt++;
    }

    // Turnaround time calculations
    float turn_sum = 0;
    for(int i = 0 ; i < _process_list.size() ; i++){
        _process_list[i].turnaround_time = _process_list[i].finish_time - _process_list[i].arrival_time;
        turn_sum+=_process_list[i].turnaround_time;
    }

    // Normalized turnaround time calculations
    float norm_turn_sum = 0;
    for(int i = 0 ; i< _process_list.size() ; i++){
        _process_list[i].norm_turn = (float)_process_list[i].turnaround_time / (float)_process_list[i].service_time;
        norm_turn_sum+=_process_list[i].norm_turn;
    }

    // Mean calculations
    float turnaround_mean = turn_sum / (float) _process_list.size(); 
    float norm_mean = norm_turn_sum / (float) _process_list.size();


    if (mode == "trace") {

    }
    else if (mode == "stats") {
        print_stats("HRRN", _process_list, turnaround_mean, norm_mean);
    }
}

void FB_1 (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        // print_stats("FB_1", _process_list, turnaround_mean, norm_mean);

    }
}

void FB_2i (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        // print_stats("FB_2i", _process_list, turnaround_mean, norm_mean);

    }
}

void Aging(std::vector<Process>& _process_list, std::string mode, int last_instance, int quanta){
    // Resetting values for each process
    for(auto process: _process_list){
        process.Reset();
    }

    if (mode == "trace") {

    }
    else if (mode == "stats") {
        // print_stats("Aging", _process_list, turnaround_mean, norm_mean);

    }
}

int main(){

    std::string _mode;
    std::string _policy;
    int _last_instance;
    int _num_process;
    std::vector <Process> _process_list;
    std::vector <Policy> _Policy_list;

    std::cin >> _mode;
    std::cin >> _policy;
    std::cin >> _last_instance;
    std::cin >> _num_process;


    // Parsing policy information and adding to policy list
    std::vector<std::string> policies;
    std::string temp = "";
    for(int i = 0 ; i < _policy.size() ; i++){
        if(_policy[i] != ',')
            temp.push_back(_policy[i]);
        else if(_policy[i] == ','){
            policies.push_back(temp);
            temp.clear();
        }
    }

    // Adding last policy
    policies.push_back(temp);


    for(auto pol : policies){
        if(pol.size() == 1){
            Policy p (stoi(pol),-1);
            _Policy_list.push_back(p);
        }
        else if (pol.size() == 3){
            Policy p (pol[0]- '0',pol[2] - '0');
            _Policy_list.push_back(p);
        }
    }

    // Parsing Process information and adding to Process list
    for(int i = 0 ; i < _num_process ; i++){
        std::string p_list;
        std::cin >> p_list;

        char name = p_list[0];
        int arrival_time = 0;
        int service_time = -1;
        int priority = -1;

        std::string temp = "";
        for (int j = 2 ; p_list[j] != ',' ; j++){
            temp.push_back(p_list[j]);
        }

        arrival_time = stoi(temp);

        temp.clear();
        
        for(int j = p_list.size() - 1 ;  p_list[j] != ',' ; j--){
            temp.push_back(p_list[j]);
        }

        std::reverse(temp.begin(),temp.end());

        service_time = stoi(temp);

        Process p (name, arrival_time, service_time, priority);

        _process_list.push_back(p);
    }

    // Sorting processes accroding to arrival_time
    sort(_process_list.begin(), _process_list.end(), less_than_av());

    // for(auto p : _process_list){
    //     std::cout<<p.name<<" "<<p.arrival_time<<" "<<p.service_time<<" "<<p.priority<<"\n";
    // }

    // looping on the list of policies and executing each one
    for(auto pp : _Policy_list){
        switch (pp.number)
        {
        case 1:
            FCFS(_process_list, _mode, _last_instance);
            break;
        case 2:
            RR(_process_list,_mode,_last_instance,pp.quanta);
            break;
        case 3:
            SPN(_process_list, _mode, _last_instance);
            break;
        case 4:
            SRT(_process_list, _mode, _last_instance);
            break;
        case 5:
            HRRN(_process_list, _mode, _last_instance);
            break;
        case 6:
            FB_1(_process_list, _mode, _last_instance);
            break;
        case 7:
            FB_2i(_process_list, _mode, _last_instance);
            break;
        case 8:
            Aging(_process_list,_mode,_last_instance,pp.quanta);
            break;
        default:
            break;
        }
    }

    return 0;
}