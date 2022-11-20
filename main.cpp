#include <bits/stdc++.h>
#include "Process.h"
#include "Policy.h"

void FCFS (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting FCFS"<<"\n";
}

void RR (std::vector<Process>& _process_list, std::string mode, int last_instance, int quanta){
    //  std::cout<<"Ececuting RR with quanta: "<< quanta<<"\n";
}

void SPN (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting SPN"<<"\n";
}

void SRT (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting SRT"<<"\n";
}

void HRRN (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting HRRN"<<"\n";
}

void FB_1 (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting FB_1"<<"\n";
}

void FB_2i (std::vector<Process>& _process_list, std::string mode, int last_instance){
    // std::cout<<"Ececuting FB_2i"<<"\n";
}

void Aging(std::vector<Process>& _process_list, std::string mode, int last_instance, int quanta){
    // std::cout<<"Ececuting Aging with quanta: "<< quanta<<"\n";
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

    // for(auto p : _process_list){
    //     std::cout<<p.name<<" "<<p.arrival_time<<" "<<p.service_time<<" "<<p.priority<<"\n";
    // }

    // for(auto pp : _Policy_list){
    //     std::cout<<pp.name<<" "<<pp.number<<" "<<pp.quanta<<"\n";
    // }
    
    // std::cout<<_mode<<" "<<_policy<<" "<<_last_instance<<" "<<_num_process<<"\n";

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