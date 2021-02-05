#include<iostream>
using namespace std;
int main()
{
	int i = 10;
	int j = 20;

// is case mein p constant nahi hai, p jise point kar rha hai vo constant hai	
	int const * p = &i;		
	p = &j;				
	// (*p)++; 			// gives an error. p jise point kar rha hai vo constant hai

// is case mein p2 constant hai, p2 jise point kar rha hai vo constant nahi hai
	int * const p2 = &i;
	// p2 = &j;			// p is constant. so we cannot change value
	(*p2)++;

// is case mein p3 constant hai, p3 jise point kar rha hai vo bhi constant hai
	int const * const p3 = &i;
	// p3 = &j;
	// (*p3)++;
}