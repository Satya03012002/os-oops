using namespace std;
#include<iostream>
// #include "Process.h"
#include <cstdlib>
#include <bits/stdc++.h>
class Process_Creator 
{
    int size;
    int N = 10;
   
     
    protected:
       Process *arr;
    public:
//     Process *arr;
    Process_Creator(){
        
    }
    Process_Creator(int x){
        size = x;
        int i = 0;
        arr = (Process *)malloc(size * sizeof(Process));
         
         cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
          while(i < size){
            arr[i].setArrival_time(rand() % N);
            arr[i].setBurst_time(rand() % N);
             int k = i+1;
            arr[i].setProcess_id(k);
           

            cout << arr[i].getProcess_id()<< "    " << arr[i].getArrival_time() << "    " << arr[i].getBurst_time() << "    " << arr[i].getCompletion_time() << "    " << arr[i].getTurn_around_time() << "    " << arr[i].getWaiting_time() << "    " << arr[i].getResponse_time() << endl;
              i++;
        }
    }
};
