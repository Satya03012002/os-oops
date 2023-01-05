using namespace std;
#include <iostream>
// #include "Process.h"
#include <bits/stdc++.h>


class MinHeap
{

    
    int stop;
    int prev = -1;
    int size ;
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
            prev =  min;
            return;
        }
    }

    int isfull(){
        if(stop == -1){
            return 1;
        }else{
            return 0;
        }
    }
  void reverse(Process *arr){
    ++size;
    //    cout << "enter into reverse function" << endl;
    //    cout << "size- in reverse function-->" << size << endl;
       
        swap(arr, 0, prev);
        swap(arr,0,size);

    }
  

    Process deque(Process *arr )
    {
        
       
        if (size == -1)
        {
            stop = -1;

            // printf("arr is already empty\n");
            Process null;
            //  cout << "return from size" <<endl; 
             null.setProcess_id(-1);
            return null;

        }

        else
        {
   
             
          
            Process p = arr[0];
            //  cout << " in dqueue heapsize-->" << size << "PID --> " << p.getProcess_id()<<endl;
            
            swap(arr, 0, size);
            // size--;
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