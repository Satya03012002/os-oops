using namespace std;
#include<iostream>

#include "Queue.h"
#include <bits/stdc++.h>


class Scheduler : public Queue
{
     public:
     Scheduler(){
      

     }


   void FCFS()
   {
      int size;
      cout << "enter size"<< endl;
      cin >> size;
      Process_Creator abc(size);
      MinHeap pkb(size);

      pkb.BuildMinHeap(abc.arr, size);
       int k = size;
       int l = 0;
       Process prev;
       cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
      while (l < size)
      {
         
          
         Process p = pkb.deque(abc.arr);
         
         
         if( l == 0){
            p.setCompletion_time(p.getBurst_time());
         p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
          p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
         p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }else{
              
         p.setCompletion_time(p.getBurst_time()+ prev.getCompletion_time());
         p.setTurn_around_time(p.getCompletion_time() - p.getArrival_time());
         p.setWaiting_time(p.getCompletion_time() - p.getBurst_time());
         p.setResponse_time(p.getCompletion_time() - p.getBurst_time());
         }
         prev = p;
         l++;

         // size--;
         cout << p.getProcess_id()<< "    " << p.getArrival_time() << "    " << p.getBurst_time() << "    " << p.getCompletion_time() << "    " << p.getTurn_around_time() << "    " << p.getWaiting_time() << "    " << p.getResponse_time() << endl;
      }
      
      //  cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
      // for(int i = 0; i < k; i++){
      //    // cout << "print" << endl;
      //    cout << abc.arr[i].getProcess_id()<< "    " << abc.arr[i].getArrival_time() << "    " << abc.arr[i].getBurst_time() << "    " << abc.arr[i].getCompletion_time() << "    " << abc.arr[i].getTurn_around_time() << "    " << abc.arr[i].getWaiting_time() << "    " << abc.arr[i].getResponse_time() << endl;
      // }
      
   }

   void RoundRobin(){
      int sizer;
      cout << "enter size"<< endl;
      cin >> sizer;
      Process_Creator abc(sizer);

      int terminal_time;
      cout << "enter terminal_time" << endl;
      cin >> terminal_time;
      int ppp;
      // cout<<"ppp"<<endl;
      // cin>>ppp ;


      Queue mno(sizer);
     
      MinHeap pkb(sizer);
      

      pkb.BuildMinHeap(abc.arr, sizer);
      int k = sizer;
      int l = 0;
     
      
         
      Process p = pkb.deque(abc.arr);
    
      // int mm = p.getProcess_id();
      // cout << "pid  =  " <<  mm <<endl;
      // mno.hii(&p);
      mno.enque(&p);
      
      
       int time = 0;
      //  cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
      while (mno.isempty() != 1)
      {
        
       if (l == 0)
       {
         Process w = mno.deque();

         // int aa = w.getBurst_time();
         // cout << "q - burst" << aa << endl;
         // aa = w.getProcess_id();
         // cout << "q - burst" << aa << endl;
         // aa = w.getArrival_time();
         // cout << "q - burst" << aa << endl;
         // aa = w.getCompletion_time();
         // cout << "q - burst" << aa << endl;
         // aa = w.getTurn_around_time();
         // cout << "q - burst" << aa << endl;
         // aa = w.getResponse_time();
         // cout << "q - burst" << aa << endl;
         // aa = w.getWaiting_time();
         // cout << "q - burst" << aa << endl;

         w.setResponse_time(w.getArrival_time());
         
         // time += terminal_time;
         int temp = w.getBurst_time() - terminal_time;
         // cout << "temp -- >" << temp << endl;
         if (temp > 0)
         {
            time += terminal_time;
            w.setBurst_time(temp);

            mno.enque(&w);
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
            int key = 0;
            int stop = 0;
            if (stop == 0)
            {
               while (key == 0)
               {
                  cout << "hello"<<endl;
                  Process j = pkb.deque(abc.arr);
                  int end = j.getProcess_id();
                  if (end == -1)
                  {
                     stop = -1;
                     break;
                  }
                  int aa = j.getArrival_time();
                  cout << "j-arrivaltime" << aa << endl;

                  if (aa < time)
                  {
                     int ab = j.getProcess_id();
                     cout << "j-processid" << ab << endl;
                     mno.enque(&j);
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

         // Process curr = mno.deque();


         // if(curr.getResponse_time() == 0){
         //      curr.setResponse_time(time);
         // }
       
         

         // time += terminal_time;
         // int temp = curr.getBurst_time() - terminal_time;
         // if (temp > 0)
         // {
         //     time += terminal_time;
         //    curr.setBurst_time(temp);
         //    mno.enque(&curr);
         // }
         // else
         // {
         //    time += curr.getBurst_time();
         //    curr.setCompletion_time(time);
         //    curr.setTurn_around_time(time - p.getArrival_time());
         //    curr.setWaiting_time(curr.getCompletion_time() - curr.getTurn_around_time());
         //    // cout << curr.getProcess_id()<< "    " << curr.getArrival_time() << "    " << curr.getBurst_time() << "    " << curr.getCompletion_time() << "    " << curr.getTurn_around_time() << "    " << curr.getWaiting_time() << "    " << curr.getResponse_time() << endl;
            
         // }
       }
      }
      
   }
};