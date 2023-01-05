// #include<stdlib.h>
// #include<unistd.h>
// #include<stdio.h>
// #include<string.h>
// #include<fcntl.h>
// #include"Scheduler.h"

// class Simulator{
//     private:
//         int file_desc;
//         int file_desc2;
//         Process_Creator* p;
//         Scheduler* schedular;
//         int number_of_processes;
//         char* process_name;
//         int simulation_time;
//         int terminal_time;
//     // implementation of part (a)
//     public:
//         Simulator(int argc, char** argv){
//             p = new Process_Creator();
//             schedular = new Scheduler();
//             number_of_processes = stoi(argv[1]);
//             process_name = argv[2];
//             simulation_time = stoi(argv[3]);
//             (argc == 5) ? (terminal_time = stoi(argv[4])) : (terminal_time = 2);
//         }
//         void createProcesses(){
//             for(int i=0;i<number_of_processes;i++){
//                 (*p).addRandomProcess();
//             }
//         }
//         void showProcesses(){
//             (*p).printProcesses();
//         }
//         void saveProcesses(){
//             file_desc = open("processes.txt",O_WRONLY);
//             dup2(file_desc, STDOUT_FILENO);
            
//         }
//         void saveStatus(){
//             file_desc = open("status.txt", O_WRONLY);
//             dup2(file_desc, STDOUT_FILENO);
//             cout<<"ms"<<"    "<<"PID"<<"    "<<"Status"<<endl;
//             if(strcmp(process_name, "fcfs") == 0 || strcmp(process_name, "FCFS") == 0){
//                 (*schedular).FCFS((*p), simulation_time);
//             }
//             else if(strcmp(process_name, "rr") == 0 || strcmp(process_name, "RR") == 0){
//                 (*schedular).RoundRobin((*p), simulation_time, terminal_time);
//             }
//             else if(strcmp(process_name, "cfs") == 0 || strcmp(process_name, "CFS") == 0){
//                 // code goes here
//             }
//             else{
//                 cout<<"Please enter a valid input!!!"<<endl;
//             }
//         }
// };