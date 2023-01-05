using namespace std;
#include <iostream>
 #include "Scheduler.h"
 #include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>


class Simulator {
        
        
        int file1;
        int file2;
        Scheduler abc;
        


    public:
    Simulator(){

    }
    void askProcess(){
        cout<<" for FCFS press 1"<<endl;
        cout<<" for roundrobin press 2"<<endl;
        cout<<" for CFS press 3"<<endl;
        int key;
        cin>> key;

        switch (key)
        {
        case 1:
            abc.FCFS();
            saveProcesses();
            break;
        case 2:
            abc.RoundRobin();
            saveProcesses();
            break;
        case 3:
            abc.CFS();
            saveProcesses();

            break;
        
        default:
            cout<<"choose correct option"<<endl;
            break;
        }


    }
    void saveProcesses(){
            file1 = open("processes.txt",O_WRONLY | O_CREAT, 0777);
            dup2(file1, STDOUT_FILENO);
            cout<<"save process"<<endl;
           
    }
    void saveStatus(){
            file2 = open("status.txt", O_WRONLY | O_CREAT);
            dup2(file2, STDOUT_FILENO);
            cout<<"save status"<<endl;
            
    }


};