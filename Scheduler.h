using namespace std;
#include <iostream>
#include <cstdio>

#include "Queue.h"

// #include "Process.h"

#include "MinHeap.h"

#include "Process_Creator.h"

#include <bits/stdc++.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>

class Scheduler
{
public:
   Scheduler()
   {
   }

   void FCFS()
   {  
      FILE* file;
      int size;
      int file1;
      int time = 0;
      cout << "enter size" << endl;
      cin >> size;
      file1 = open("processes.txt",O_WRONLY | O_CREAT, 0777);
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
              file = fopen("status.txt","a");
      while (l < size)
      {

         Process p = pkb.deque(abc.arr);
       
         

         if (l == 0)
         {    time = p.getArrival_time();
            fprintf(file, " %d %s %d %s \n",time, "PID  ",p.getProcess_id(), "  Arrived");
            for(int i = 1; i < p.getBurst_time(); i++){
               
             fprintf(file, " %d %s %d %s \n",time, "PID  ",p.getProcess_id(), "  Running");
             time++;
            }
            p.setCompletion_time(p.getBurst_time());
            p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
            p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
            p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }
         else
         {  fprintf(file, " %d %s %d %s \n",time, "PID  ",p.getProcess_id(), "  Arrived");
            for(int i = 1; i < p.getBurst_time(); i++){
               time++;
             fprintf(file, " %d %s %d %s \n",time, "PID  ",p.getProcess_id(), "  Running");
            }
            p.setCompletion_time(p.getBurst_time() + prev.getCompletion_time());
            p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
            p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
            p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }
         prev = p;
         l++;
         
         fprintf(file, " %d %s %d %s \n",time,"PID  ",p.getProcess_id(), "  exit");
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
      file1 = open("processes.txt",O_WRONLY | O_CREAT, 0777);
            dup2(file1, STDOUT_FILENO);
            cout<<"save process"<<endl;
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
       cout << "PId" << "  AT" << "  BT" << "    CT" << "    TAT" << "   WT" << "   RT"<< endl;
      //   (mno.isempty() != 1  && pkb.isfull() != 1)
      while ( !(mno.isempty() == 1  && pkb.isfull() == 1))
      {
         int c = mno.isempty();
         // cout << "not empty++++++++++"<< c <<endl;
         if(pkb.isfull() !=1 && mno.isempty() == 1){
            time++;
         }
         if (l == 0)
         {
            Process w = mno.deque();//---------------------------------------------11
            int ab = w.getProcess_id();
                        // cout << " dequeue --PID  " << ab << endl;
                        
            w.setResponse_time(w.getArrival_time());
            int temp = w.getBurst_time() - terminal_time;
            if (temp > 0)
            {
               
               time = terminal_time+ w.getArrival_time();
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
                  while (1){
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
                     
                     if (j.getArrival_time()< time)
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

            Process curr = mno.deque();//-------------------------------12
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
         cout<<aa;
         aa = curr.getArrival_time();
           cout << "    "<<aa;
         aa = curr.getBurst_time();
           cout << "    "<<aa;
         aa = curr.getCompletion_time();
           cout << "    "<<aa;
         aa = curr.getTurn_around_time();
         cout << "    "<<aa;
         aa = curr.getResponse_time();
           cout << "    "<<aa;
         aa = curr.getWaiting_time();
           cout << "    "<<aa <<endl;

            }
         }
      }
   }

   void CFS(){

   }
};