using namespace std;
#include <iostream>
 #include "Scheduler.h"
 #include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include"Scheduler.h"

class Simulator :  public Scheduler{

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
            break;
        case 2:
            abc.RoundRobin();
            break;
        case 3:
            abc.CFS();
            break;
        
        default:
            cout<<"choose correct option"<<endl;
            break;
        }


    }
    void saveProcesses(){
            file1 = open("processes.txt",O_WRONLY);
            dup2(file1, STDOUT_FILENO);
           
        }
    void saveStatus(){
            file2 = open("status.txt", O_WRONLY);
            dup2(file2, STDOUT_FILENO);
            
        }


};