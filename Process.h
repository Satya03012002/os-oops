using namespace std;
#include<iostream>

class Process{

int process_id,arrival_time,burst_time,completion_time,turn_around_time,waiting_time,response_time;

public:
Process(){
process_id = 0;
arrival_time = 0;
burst_time = 0;
completion_time = 0;
turn_around_time = 0;
waiting_time = 0;
response_time = 0;
}
// Process(int id){
// process_id = id;
// arrival_time = 0;
// burst_time = 0;
// completion_time = 0;
// turn_around_time = 0;
// waiting_time = 0;
// response_time = 0;
// }


void setProcess_id(int x){
    process_id = x;
}
void setArrival_time(int x){
    arrival_time = x;
}
void setBurst_time(int x){
    burst_time = x;
}
void setCompletion_time(int x){
    completion_time = x;
}
void setTurn_around_time(int x){
    turn_around_time = x;
}
void setWaiting_time(int x){
    waiting_time = x;
}
void setResponse_time(int x){
    response_time = x;
}
int getProcess_id(){
    return process_id; 
}
int getArrival_time(){
    return arrival_time;
}
int getBurst_time(){
    return burst_time;
}
int getCompletion_time(){
     return completion_time;
}
int getTurn_around_time(){
    return turn_around_time;
}
int getWaiting_time(){
    return waiting_time;
}
int getResponse_time(){
    return response_time;
}
void print(){
    cout << process_id << arrival_time << burst_time << completion_time << turn_around_time << waiting_time << response_time << endl;
}

};