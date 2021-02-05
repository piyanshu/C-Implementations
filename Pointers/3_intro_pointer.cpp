#include<iostream>
using namespace std;
int main()
{
	int *p = 0;			// Always assign the pointer through NULL
	cout<<p<<endl;

	cout<<*p<<endl;
	(*p)++;
	cout<<*p<<endl;
}