using namespace std;
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>

class Process
{

    int process_id, arrival_time, burst_time, completion_time, turn_around_time, waiting_time, response_time;

public:
    Process()
    {
        process_id = 0;
        arrival_time = 0;
        burst_time = 0;
        completion_time = 0;
        turn_around_time = 0;
        waiting_time = 0;
        response_time = 0;
    }
    Process(int id)
    {
        process_id = id;
        arrival_time = 0;
        burst_time = 0;
        completion_time = 0;
        turn_around_time = 0;
        waiting_time = 0;
        response_time = 0;
    }

    void setProcess_id(int x)
    {
        process_id = x;
    }
    void setArrival_time(int x)
    {
        arrival_time = x;
    }
    void setBurst_time(int x)
    {
        burst_time = x;
    }
    void setCompletion_time(int x)
    {
        completion_time = x;
    }
    void setTurn_around_time(int x)
    {
        turn_around_time = x;
    }
    void setWaiting_time(int x)
    {
        waiting_time = x;
    }
    void setResponse_time(int x)
    {
        response_time = x;
    }
    int getProcess_id()
    {
        return process_id;
    }
    int getArrival_time()
    {
        return arrival_time;
    }
    int getBurst_time()
    {
        return burst_time;
    }
    int getCompletion_time()
    {
        return completion_time;
    }
    int getTurn_around_time()
    {
        return turn_around_time;
    }
    int getWaiting_time()
    {
        return waiting_time;
    }
    int getResponse_time()
    {
        return response_time;
    }

    void print()
    {
        cout << process_id << arrival_time << burst_time << completion_time << turn_around_time << waiting_time << response_time << endl;
    }
};

class Process_Creator
{
    int size;
    int N = 10;

public:
    Process *arr;
    Process_Creator()
    {
    }
    Process_Creator(int x)
    {
        size = x;
        int i = 0;
        arr = (Process *)malloc(size * sizeof(Process));

        cout << "PId"
             << "  AT"
             << "  BT"
             << "  CT"
             << "  TAT"
             << "  WT"
             << "  RT" << endl;
        while (i < size)
        {
            arr[i].setArrival_time(rand() % N);
            arr[i].setBurst_time(rand() % N);
            int k = i + 1;
            arr[i].setProcess_id(k);

            cout << arr[i].getProcess_id() << "    " << arr[i].getArrival_time() << "    " << arr[i].getBurst_time() << "    " << arr[i].getCompletion_time() << "    " << arr[i].getTurn_around_time() << "    " << arr[i].getWaiting_time() << "    " << arr[i].getResponse_time() << endl;
            i++;
        }
    }
};

class MinHeap
{

    int stop;
    int prev = -1;
    int size;

public:
    MinHeap()
    {
        size = -1;
        stop = 0;
    }
    MinHeap(int x)
    {
        size = x - 1;
        stop = 0;
    }

    int Left(int i)
    {
        return 2 * i + 1;
    }
    int Right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return i / 2;
    }
    void swap(Process *arr, int min, int i)
    {
        Process temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

public:
    void MinHeapify(Process *arr, int i, int len)
    {

        int min = i;
        int l = Left(i);
        int r = Right(i);

        if (l < len && arr[l].getArrival_time() < arr[min].getArrival_time())
        {
            min = l;
        }
        if (r < len && arr[r].getArrival_time() < arr[min].getArrival_time())
        {
            min = r;
        }

        if (min != i)
        {
            swap(arr, min, i);
            MinHeapify(arr, min, len);
        }
        else
        {
            prev = min;
            return;
        }
    }

    int isfull()
    {
        if (stop == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void reverse(Process *arr)
    {
        ++size;

        swap(arr, 0, prev);
        swap(arr, 0, size);
    }

    Process deque(Process *arr)
    {

        if (size == -1)
        {
            stop = -1;

           
            Process null;
          
            null.setProcess_id(-1);
            return null;
        }

        else
        {

            Process p = arr[0];
          
            swap(arr, 0, size);
        
            MinHeapify(arr, 0, size);

            size--;

            return p;
        }
    }

    void BuildMinHeap(Process *arr, int len)
    {

        for (int i = len / 2; i >= 0; i--)
        {

            MinHeapify(arr, i, len);
        }

        printf("\n\n");

        return;
    }
};

class Queue
{

    int front, rear; // rare- piche wala
    int capacity;
    Process *arrq;

public:
    Queue()
    {
    }

    Queue(int x)
    {
        front = -1;
        rear = -1;
        capacity = x;
        arrq = (Process *)malloc(x * sizeof(Process));
        // cout << "queue ban gya" << endl;
    }

    //  Process *arr = (Process *)malloc(size * sizeof(Process));
    int isempty()
    {
        if (front == -1)
        {
            return 1;
        }
        return (0);
    }

    // isfullqueue

    int isfullque()
    {
        return ((rear + 1) % capacity == front);
    }
    // queuesize
    int quesize()
    {
        return ((capacity - front + rear + 1) % capacity); // may be we can direct write q->rear - q->front +1
    }

    void enque(Process *q)
    {

        // cout << "enqueue ander aa ya"<<endl;
        if (isfullque())
        {
            printf("overflow\n");
        }

        else
        {
            rear = (rear + 1) % capacity;
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

            if (front == -1)
            {
                front = rear;
            }
        }
    }

    // del element in queue // default hai ki first come first go

    Process deque()
    {

        // cout << "dequeue ander aa ya"<<endl;
        Process q;

        if (front == -1)
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

            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % capacity; // taki agar mera front rear k barabar ho jaye tab front 0 ho jaaye
            }

            return q;
        }
    }
};

class Scheduler
{
public:
    Scheduler()
    {
    }

    void FCFS()
    {
        FILE *file;
        int size;
        int file1;
        int time = 0;
        cout << "enter size" << endl;
        cin >> size;
        file1 = open("processes.txt", O_WRONLY | O_CREAT, 0777);
        dup2(file1, STDOUT_FILENO);

        Process_Creator abc(size);
        MinHeap pkb(size);

        pkb.BuildMinHeap(abc.arr, size);
        int k = size;
        int l = 0;
        Process prev;
        cout << "PId"
             << "  AT"
             << "  BT"
             << "  CT"
             << "  TAT"
             << "  WT"
             << "  RT" << endl;
        file = fopen("status.txt", "a");
        while (l < size)
        {

            Process p = pkb.deque(abc.arr);

            if (l == 0)
            {
                time = p.getArrival_time();
                fprintf(file, " %d %s %d %s \n", time, "PID  ", p.getProcess_id(), "  Arrived");
                for (int i = 1; i < p.getBurst_time(); i++)
                {

                    fprintf(file, " %d %s %d %s \n", time, "PID  ", p.getProcess_id(), "  Running");
                    time++;
                }
                p.setCompletion_time(p.getBurst_time());
                p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
                p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
                p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
            }
            else
            {
                fprintf(file, " %d %s %d %s \n", time, "PID  ", p.getProcess_id(), "  Arrived");
                for (int i = 1; i < p.getBurst_time(); i++)
                {
                    time++;
                    fprintf(file, " %d %s %d %s \n", time, "PID  ", p.getProcess_id(), "  Running");
                }
                p.setCompletion_time(p.getBurst_time() + prev.getCompletion_time());
                p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
                p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
                p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
            }
            prev = p;
            l++;

            fprintf(file, " %d %s %d %s \n", time, "PID  ", p.getProcess_id(), "  exit");
            time++;
            cout << p.getProcess_id() << "    " << p.getArrival_time() << "    " << p.getBurst_time() << "    " << p.getCompletion_time() << "    " << p.getTurn_around_time() << "    " << p.getWaiting_time() << "    " << p.getResponse_time() << endl;
        }

        fclose(file);
    }

    void RoundRobin()
    {
        int file1;
        int sizer;
        cout << "enter size" << endl;
        cin >> sizer;
        Process_Creator abc(sizer);
        int terminal_time;
        cout << "enter terminal_time" << endl;
        cin >> terminal_time;
        file1 = open("processes.txt", O_WRONLY | O_CREAT, 0777);
        dup2(file1, STDOUT_FILENO);
        cout << "save process" << endl;
        int ppp;
        Queue mno(sizer);
        MinHeap pkb(sizer);
        pkb.BuildMinHeap(abc.arr, sizer);
        int l = 0;
        Process p = pkb.deque(abc.arr);
        mno.enque(&p);
        int ab = p.getProcess_id();
        // cout << " enqueue --PID  " << ab << endl;

        int time = 0;
        int key = 0;
        int stp = 0;
        cout << "PId"
             << "  AT"
             << "  BT"
             << "    CT"
             << "    TAT"
             << "   WT"
             << "   RT" << endl;
        //   (mno.isempty() != 1  && pkb.isfull() != 1)
        while (!(mno.isempty() == 1 && pkb.isfull() == 1))
        {
            int c = mno.isempty();
            // cout << "not empty++++++++++"<< c <<endl;
            if (pkb.isfull() != 1 && mno.isempty() == 1)
            {
                time++;
            }
            if (l == 0)
            {
                Process w = mno.deque(); //---------------------------------------------11
                int ab = w.getProcess_id();
                // cout << " dequeue --PID  " << ab << endl;

                w.setResponse_time(w.getArrival_time());
                int temp = w.getBurst_time() - terminal_time;
                if (temp > 0)
                {

                    time = terminal_time + w.getArrival_time();
                    w.setBurst_time(temp);
                    int ab = w.getProcess_id();
                    // cout << " enqueue --PID  " << ab << endl;

                    mno.enque(&w); //---------------------------------------------------------------------3
                }
                else
                {
                    time += w.getBurst_time();
                    w.setCompletion_time(time);
                    w.setTurn_around_time(time - p.getArrival_time());
                    int ll = w.getTurn_around_time();
                    w.setWaiting_time(w.getCompletion_time() - ll);

                    // cout << w.getProcess_id()<< "    " << w.getArrival_time() << "    " << w.getBurst_time() << "    " << w.getCompletion_time() << "    " << w.getTurn_around_time() << "    " << w.getWaiting_time() << "    " << w.getResponse_time() << endl;
                }
                l++;
            }
            else
            {
                if (pkb.isfull() != 1)
                {
                    if (stp == 0)
                    {
                        while (1)
                        {
                            // {   cout<<"hello"<<endl;
                            // cout << "hello" << endl;
                            Process j = pkb.deque(abc.arr);
                            int end = j.getProcess_id();
                            if (end == -1)
                            {
                                // cout<<"heap end------------------------>"<<endl;
                                stp = -1;
                                break;
                            }
                            int aa = j.getArrival_time();

                            if (j.getArrival_time() < time)
                            {
                                int ab = j.getProcess_id();
                                // cout << " enqueue --PID  " << ab << endl;
                                mno.enque(&j); //------------------------------------------------------------------2
                            }
                            else
                            {
                                pkb.reverse(abc.arr);
                                break;
                            }
                        }
                    }
                }

                Process curr = mno.deque(); //-------------------------------12
                int ab = curr.getProcess_id();
                // cout << " dequeue--PID  " << ab<< endl;

                time += terminal_time;
                int tempp = curr.getResponse_time();
                if (tempp == 0)
                {
                    curr.setResponse_time(time);
                }

                //  cout << "time--> " << time << endl;
                int temp = curr.getBurst_time() - terminal_time;
                //  curr.setBurst_time(curr.getBurst_time() - terminal_time);
                if (temp > 0)
                {
                    curr.setBurst_time(curr.getBurst_time() - terminal_time);
                    // curr.setBurst_time(temp);

                    int kl = curr.getBurst_time();
                    // cout << "current.bursttime" << kl << endl;
                    // cout << "enqueue" << endl;
                    int ab = curr.getProcess_id();
                    // cout << " ---------------------------------------------enqueue --PID  " << ab << endl;

                    mno.enque(&curr); //------------------------------------------------------------1
                }
                else
                {
                    time += curr.getBurst_time();
                    curr.setCompletion_time(time);
                    curr.setTurn_around_time(time - p.getArrival_time());
                    int ll = curr.getTurn_around_time();
                    curr.setWaiting_time(curr.getCompletion_time() - ll);
                    // cout << curr.getProcess_id()<< "    " << curr.getArrival_time() << "    " << curr.getBurst_time() << "    " << curr.getCompletion_time() << "    " << curr.getTurn_around_time() << "    " << curr.getWaiting_time() << "    " << curr.getResponse_time() << endl;

                    int aa = curr.getProcess_id();
                    cout << aa;
                    aa = curr.getArrival_time();
                    cout << "    " << aa;
                    aa = curr.getBurst_time();
                    cout << "    " << aa;
                    aa = curr.getCompletion_time();
                    cout << "    " << aa;
                    aa = curr.getTurn_around_time();
                    cout << "    " << aa;
                    aa = curr.getResponse_time();
                    cout << "    " << aa;
                    aa = curr.getWaiting_time();
                    cout << "    " << aa << endl;
                }
            }
        }
    }

    void CFS()
    {
    }
};

class Simulator
{

    int file1;
    int file2;
    Scheduler abc;

public:
    Simulator()
    {
    }
    void askProcess()
    {
        cout << " for FCFS press 1" << endl;
        cout << " for roundrobin press 2" << endl;
        cout << " for CFS press 3" << endl;
        int key;
        cin >> key;

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
            cout << "choose correct option" << endl;
            break;
        }
    }
    void saveProcesses()
    {
        file1 = open("processes.txt", O_WRONLY | O_CREAT, 0777);
        dup2(file1, STDOUT_FILENO);
        cout << "save process" << endl;
    }
    void saveStatus()
    {
        file2 = open("status.txt", O_WRONLY | O_CREAT);
        dup2(file2, STDOUT_FILENO);
        cout << "save status" << endl;
    }
};


int main(){
    
    Simulator def;
    def.askProcess();

    return 0;



}