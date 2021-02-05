// int i = 10; has three steps
// 1. creating a memory location
// 2. i ke corresponding symbol table mein entry
// 3. setting the value in memory location
// storing the memory adress of any variable is known as pointer
#include<iostream>
using namespace std;
int main()
{
	int i = 10;
	// Accessing the adress through integer by using & operator
	cout<<&i<<endl;

	// Syntax for creating pointer
	int* p = &i;
	
	// Acessing an integer through adress by using *(drefernce) operator
	cout<<*p<<endl; 
}
