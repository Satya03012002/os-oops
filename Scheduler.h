using namespace std;
#include<iostream>
#include "MinHeap.h"

class Scheduler : public MinHeap
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

   void FCFS(){
      int size;
      cout << "enter size"<< endl;
      cin >> size;
      Process_Creator abc(size);

      
   }
};