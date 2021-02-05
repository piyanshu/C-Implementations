#include<iostream>
using namespace std;
int main()
{
	int i=10;
	int* p = &i;	// p points to integer i

	cout<<p<<endl;	
	p=p+1;	// At this line the pointer p points to the next integer after i
	cout<<p;	// the memory adress will increased by 4

	double d = 10.56;
	double* dp = &d;	// dp points to double d

	cout<<dp<<endl;	
	dp = dp+2;			// At this line the pointer dp starts pointer to next to next integer after i
	cout<<dp<<endl;		// memory adress increase by 16 = 8+8

// These arithmetic operations doesn't make any sense because we dont know what is the next integer
// But this makes sense in case of arrays because of continuous memory allocations
}