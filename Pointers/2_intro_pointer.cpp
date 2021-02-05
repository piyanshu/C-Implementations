#include<iostream>
using namespace std;
int main()
{
	int i=10;
	int* p = &i;

	cout<<"size: "<<sizeof(p)<<endl;	// 8 bytes

	// Now there are two ways to access the memory i
	cout<<i<<endl;
	cout<<*p<<endl;

	i++;
	cout<<i<<endl;
	cout<<*p<<endl;

	i=12;
	cout<<i<<endl;
	cout<<*p<<endl;

	*p = 23;
	cout<<i<<endl;
	cout<<*p<<endl;

	(*p)++;
	cout<<i<<endl;
	cout<<*p<<endl;

	// Now there are three ways to access the memory location i
	int* q = p;

}