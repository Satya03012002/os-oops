using namespace std;
#include <iostream>
#include "Process_Creator.h"


class MinHeap :public  Process_Creator
{

    int size ;
    int stop;
    public:
    MinHeap(){
        size = -1;
        stop = 0;
    }
     MinHeap(int x){
        size = x-1;
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
            return;
        }
    }

    Process deque(Process *arr )
    {

        if (size == -1)
        {
            stop = -1;

            printf("arr is already empty\n");
            Process null;
            return null;
        }

        else
        {
    //          cout<< "size -->" << size << endl;
    //           cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
    //   for(int i = 0; i <= size; i++){
    //      // cout << "print" << endl;
    //      cout << arr[i].getProcess_id()<< "    " << arr[i].getArrival_time() << "    " << arr[i].getBurst_time() << "    " << arr[i].getCompletion_time() << "    " << arr[i].getTurn_around_time() << "    " << arr[i].getWaiting_time() << "    " << arr[i].getResponse_time() << endl;
    //   } 

             
            // printf("\n deqq\n");
            Process p = arr[0];
            
            swap(arr, 0, size);
            // cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
            // cout << p.getProcess_id()<< "    " << p.getArrival_time() << "    " << p.getBurst_time() << "    " << p.getCompletion_time() << "    " << p.getTurn_around_time() << "    " << p.getWaiting_time() << "    " << p.getResponse_time() << endl;
           
            MinHeapify(arr, 0, size);
             size--;


            return p;
        }
    }

    void BuildMinHeap(Process *arr, int len)
    {
       cout << "enter in build min heap" << endl;
        for (int i = len / 2; i >= 0; i--)
        {

            MinHeapify(arr, i, len);
        }

        
       cout << "PId" << "  AT" << "  BT" << "  CT" << "  TAT" << "  WT" << "  RT"<< endl;
      for(int i = 0; i < len; i++){
         // cout << "print" << endl;
         cout << arr[i].getProcess_id()<< "    " << arr[i].getArrival_time() << "    " << arr[i].getBurst_time() << "    " << arr[i].getCompletion_time() << "    " << arr[i].getTurn_around_time() << "    " << arr[i].getWaiting_time() << "    " << arr[i].getResponse_time() << endl;
      } 

      printf("\n\n");
       
        return;
    }
};