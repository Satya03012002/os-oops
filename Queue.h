
using namespace std;
#include<iostream>
#include "Process.h"
#include <bits/stdc++.h>
class Queue{

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
        arrq = (Process *)malloc(x * sizeof(Process));
        // cout << "queue ban gya" << endl;
    }
      
    //  Process *arr = (Process *)malloc(size * sizeof(Process));
    int isempty(){
        if (front == -1)
        {
            return 1;
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
// //enqueue ye bhi default hai ki data rear element me hi jaayga
 
//  void hii(Process* p){
    
//     int mm = p->getProcess_id();
//       cout << "pid  =  " <<  mm <<endl;
//     cout << "helloooo" << endl;
//  }
void enque(Process* q){

    // cout << "enqueue ander aa ya"<<endl;
    if(isfullque()){
        printf("overflow\n");
    }
    
    else{
        rear= (rear+1)%capacity;
        // cout << "rear----------------"<<rear<<endl;
        int mm = q->getProcess_id();
        arrq[rear].setProcess_id(q->getProcess_id());
        arrq[rear].setArrival_time(q->getArrival_time());
        arrq[rear].setBurst_time(q->getBurst_time());
        arrq[rear].setCompletion_time(q->getCompletion_time());
        arrq[rear].setTurn_around_time(q->getTurn_around_time());
        arrq[rear].setWaiting_time(q->getWaiting_time());
        arrq[rear].setResponse_time(q->getResponse_time());
        // cout<< " enque in queue  PID- " << arrq[rear].getProcess_id()<<endl;
        

        
        if(front==-1){
            front=rear;
        }
    }
    
}

// del element in queue // default hai ki first come first go

Process deque(){

    // cout << "dequeue ander aa ya"<<endl;
     Process q;
    
    if(front == -1)
    {
        printf("queue is empty\n");
        Process null;
        return null;
    }
    else
    {
        // Process q = arr[front];
        q.setProcess_id(arrq[front].getProcess_id());
         q.setArrival_time(arrq[front].getArrival_time());
         q.setBurst_time(arrq[front].getBurst_time());
        q.setCompletion_time(arrq[front].getCompletion_time());
        q.setTurn_around_time(arrq[front].getTurn_around_time());
        q.setWaiting_time(arrq[front].getWaiting_time());
        q.setResponse_time(arrq[front].getResponse_time());
        // cout<< "q - burst" << q.getBurst_time()<<endl;
        // cout<< "q - burst" << q.getProcess_id()<<endl;
        // cout<< "q - burst" << q.getArrival_time()<<endl;
        // cout<< "q - burst" << q.getWaiting_time()<<endl;
        // cout<< "q - burst" << q.getResponse_time()<<endl;
        // cout<< "q - burst" << q.getTurn_around_time()<<endl;
        // cout<< "q - burst" << q.getCompletion_time()<<endl;
        // cout<< " deque in deeue  PID- " << q.getProcess_id()<<endl;
        
        
     
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front +1)%capacity;// taki agar mera front rear k barabar ho jaye tab front 0 ho jaaye
        }

        return q;
    }
    
    
}





};