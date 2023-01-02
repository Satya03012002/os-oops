using namespace std;
#include <iostream>

#include "Queue.h"
#include <bits/stdc++.h>

class Scheduler : public Queue
{
public:
   Scheduler()
   {
   }

   void FCFS()
   {
      int size;
      cout << "enter size" << endl;
      cin >> size;
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
      while (l < size)
      {

         Process p = pkb.deque(abc.arr);

         if (l == 0)
         {
            p.setCompletion_time(p.getBurst_time());
            p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
            p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
            p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }
         else
         {

            p.setCompletion_time(p.getBurst_time() + prev.getCompletion_time());
            p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
            p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
            p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }
         prev = p;
         l++;

         // size--;
         cout << p.getProcess_id() << "    " << p.getArrival_time() << "    " << p.getBurst_time() << "    " << p.getCompletion_time() << "    " << p.getTurn_around_time() << "    " << p.getWaiting_time() << "    " << p.getResponse_time() << endl;
      }

      //  cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
      // for(int i = 0; i < k; i++){
      //    // cout << "print" << endl;
      //    cout << abc.arr[i].getProcess_id()<< "    " << abc.arr[i].getArrival_time() << "    " << abc.arr[i].getBurst_time() << "    " << abc.arr[i].getCompletion_time() << "    " << abc.arr[i].getTurn_around_time() << "    " << abc.arr[i].getWaiting_time() << "    " << abc.arr[i].getResponse_time() << endl;
      // }
   }

   void RoundRobin()
   {
      int sizer;
      cout << "enter size" << endl;
      cin >> sizer;
      Process_Creator abc(sizer);
      int terminal_time;
      cout << "enter terminal_time" << endl;
      cin >> terminal_time;
      int ppp;
      Queue mno(sizer);
      MinHeap pkb(sizer);
      pkb.BuildMinHeap(abc.arr, sizer);
      int l = 0;
      Process p = pkb.deque(abc.arr);
      mno.enque(&p);
      int time = 0;
      int key = 0;
      int stp = 0;
      //  cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;

      while ( pkb.isfull() != 1 && mno.isempty() != 1)
      {
         if(pkb.isfull() !=1 && mno.isempty() != 1){
            time++;
         }
         if (l == 0)
         {
            Process w = mno.deque();//---------------------------------------------11
            cout<<"dddddddd"<<endl;
            w.setResponse_time(w.getArrival_time());
            int temp = w.getBurst_time() - terminal_time;
            if (temp > 0)
            {
               time += terminal_time;
               w.setBurst_time(temp);
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
                  while (key == 0)
                  {
                     cout << "hello" << endl;
                     Process j = pkb.deque(abc.arr);
                     int end = j.getProcess_id();
                     if (end == -1)
                     {
                        stp = -1;
                        break;
                     }
                     int aa = j.getArrival_time();
                     cout << "j-arrivaltime" << aa << endl;
                     if (aa < time)
                     {
                        int ab = j.getProcess_id();
                        cout << "j-processid" << ab << endl;
                        mno.enque(&j); //------------------------------------------------------------------2
                        // time += terminal_time;
                     }
                     else
                     {
                        pkb.reverse(abc.arr);
                        key = -1;

                        break;
                     }
                  }
               }
            }

            Process curr = mno.deque();//-------------------------------12
            cout<< "dddd"<<endl;
            int tempp = curr.getResponse_time();
            if (tempp == 0)
            {
               curr.setResponse_time(time);
            }
            time += terminal_time;
             cout << "time--> " << time << endl;
            int temp = curr.getBurst_time() - terminal_time;
            if (temp > 0)
            {

              
               curr.setBurst_time(temp);
               int kl = curr.getBurst_time();
               cout << "current.bursttime" << kl << endl;
               cout << "enqueue" << endl;

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
            }
         }
      }
   }
};