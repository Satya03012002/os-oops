
using namespace std;
#include<iostream>
#include "Process_Creator.h"
class Queue: public Process_Creator{

    int front,rear;// rare- piche wala
    int capacity;
    Process *arr;
    
    Queue(){

    }

    Queue( int x){
        front = -1;
        rear = -1;
        capacity= x;
        arr = (Process *)malloc(x * sizeof(Process));

    }

    public:
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

void enque(Process q,int data){
    if(isfullque()){
        printf("overflow");
    }
    
    else{
        rear= rear+1 %capacity;
        arr[rear]= q;
        if(front==-1){
            front=rear;
        }
    }
}

// del element in queue // default hai ki first come first go

Process deque(){
     Process p;
    int data =-1;
    if(isempty())
    {
        printf("queue is empty");
        Process null;
        return null;
    }
    else
    {
        p = arr[front];
        if(front==rear){
            front = rear = -1;
        }
        else{
            front = (front +1)%capacity;// taki agar mera front rear k barabar ho jaye tab front 0 ho jaaye
        }
    }
    return p;
}


// del queue mtlb pura queue ko hi delete harna hai

// void delque(struct arrque *q){
//     if(q){
//         if(q->array){// agar q->array null nahi hai to
//             free(q->array);
//         }
//         free(q);
//     }
    
// }


};