#include <cstdlib>
#include <iostream>
using namespace std;
// //  # include "Scheduler.h"
// //  #include "MinHeap.h"
// // # include "Process.h"
// # include "Process_Creator.h"

// int main()
// {
// Process abc;
// Process_Creator def;

// return 0;
// }

// C++ program to implement
// Multilevel Inheritance
#include <bits/stdc++.h>
using namespace std;

// single base class
class A {
public:
	int a;
	void get_A_data()
	{
		cout << "Enter value of a: ";
		cin >> a;
	}
};

// derived class from base class
class B : public A {
public:
	int b;
	void get_B_data()
	{
		cout << "Enter value of b: ";
		cin >> b;
        cout << "sum: " << a+b;
	}
};

// derived from class derive1
class C : public B {
private:
	int c;

public:
	void get_C_data()
	{
		cout << "Enter value of z: ";
		cin >> c;
        
	}
	
	// function to print sum
	void sum()
	{
		int ans = a + b + c;
		cout << "sum: " << ans;
	}
};
int main()
{
	// object of sub class
	C obj;

	obj.get_A_data();
	obj.get_B_data();
	obj.get_C_data();
	obj.sum();
	return 0;
}
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