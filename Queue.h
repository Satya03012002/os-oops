
using namespace std;
#include<iostream>
#include "MinHeap.h"
#include <bits/stdc++.h>
class Queue: public MinHeap{

    int front,rear;// rare- piche wala
    int capacity;
   Process *arrq;
    public:
    Queue(){

    }

    Queue( int x){
        front = -1;
        rear = -1;
        capacity= x;
        arr = (Process *)malloc(x * sizeof(Process));
        cout << "queue ban gya" << endl;
    }
      
    //  Process *arr = (Process *)malloc(size * sizeof(Process));
    int isempty(){
        if (front == -1)
        {
            return (1);
        }
        return (0);
    }

// isfullqueue

int isfullque(){
    return((rear+1)%capacity== front);
    
}
//queuesize
int quesize(){
    return((capacity -front + rear +1)% capacity);// may be we can direct write q->rear - q->front +1
}
//enqueue ye bhi default hai ki data rear element me hi jaayga
 
 void hii(Process* p){
    
    int mm = p->getProcess_id();
      cout << "pid  =  " <<  mm <<endl;
    cout << "helloooo" << endl;
 }
void enque(Process* q){
    if(isfullque()){
        printf("overflow");
    }
    
    else{
        rear= rear+1%capacity;
         
        // arrq[rear]= *q;
        arr[rear].setProcess_id(q->getProcess_id());
        arr[rear].setArrival_time(q->getArrival_time());
        arr[rear].setBurst_time(q->getBurst_time());
        arr[rear].setCompletion_time(q->getCompletion_time());
        arr[rear].setTurn_around_time(q->getTurn_around_time());
        arr[rear].setWaiting_time(q->getWaiting_time());
        arr[rear].setResponse_time(q->getResponse_time());

        
        if(front==-1){
            front=rear;
        }
    }
    cout << "add ho gyA" << endl;
}

// del element in queue // default hai ki first come first go

Process deque(){
     Process q;
    int data =-1;
    if(isempty())
    {
        printf("queue is empty");
        Process null;
        return null;
    }
    else
    {
        
        q.setProcess_id(arrq[front].getProcess_id());
         q.setArrival_time(arrq[front].getArrival_time());
         q.setBurst_time(arrq[front].getBurst_time());
        q.setCompletion_time(arrq[front].getCompletion_time());
        q.setTurn_around_time(arrq[front].getTurn_around_time());
        q.setWaiting_time(arrq[front].getWaiting_time());
        q.setResponse_time(arrq[front].getResponse_time());
        cout << "P.waiting" << arr[front].getWaiting_time()<< endl;
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front +1)%capacity;// taki agar mera front rear k barabar ho jaye tab front 0 ho jaaye
        }
    }
    cout << "bhej raha hu" << endl;
    return q;
}





};