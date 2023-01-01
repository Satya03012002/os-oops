using namespace std;
#include<iostream>
#include "Process.h"
#include <cstdlib>

class Process_Creator : public Process
{
    int size;
    int N = 10;
   
    

    public:
    Process *arr = (Process *)malloc(size * sizeof(Process));
    Process_Creator(){
        
    }
    Process_Creator(int x){
        size = x;
        int i = 0;
         
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