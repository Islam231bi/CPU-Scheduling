#include <bits/stdc++.h>
#include "Process.h"



int main(){

    std::string mode;
    std::string policy;
    int last_instance;
    int num_process;
    std::vector <Process> process_list ;

    std::cin >> mode;
    std::cin >> policy;
    std::cin >> last_instance;
    std::cin >> num_process;

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

        process_list.push_back(p);
    }

    for(auto p : process_list){
        std::cout<<p.name<<" "<<p.arrival_time<<" "<<p.service_time<<" "<<p.priority<<"\n";
    }
    std::cout<<mode<<" "<<policy<<" "<<last_instance<<" "<<num_process<<"\n";

    return 0;
}