#include <bits/stdc++.h>
#include "Process.h"
#include "Policy.h"

int main(){

    std::string mode;
    std::string policy;
    int last_instance;
    int num_process;
    std::vector <Process> _process_list;
    std::vector <Policy> _Policy_list;

    std::cin >> mode;
    std::cin >> policy;
    std::cin >> last_instance;
    std::cin >> num_process;


    // Parsing policy information and adding to policy list
    std::vector<std::string> policies;
    std::string temp = "";
    for(int i = 0 ; i < policy.size() ; i++){
        if(policy[i] != ',')
            temp.push_back(policy[i]);
        else if(policy[i] == ','){
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
    for(int i = 0 ; i < num_process ; i++){
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

        if(policy[0] == '8'){
            priority = stoi(temp);
        }

        else {
            service_time = stoi(temp);
        }

        Process p (name, arrival_time, service_time, priority);

        _process_list.push_back(p);
    }

    for(auto p : _process_list){
        std::cout<<p.name<<" "<<p.arrival_time<<" "<<p.service_time<<" "<<p.priority<<"\n";
    }

    for(auto pp : _Policy_list){
        std::cout<<pp.name<<" "<<pp.number<<" "<<pp.quanta<<"\n";
    }
    
    std::cout<<mode<<" "<<policy<<" "<<last_instance<<" "<<num_process<<"\n";




    return 0;
}