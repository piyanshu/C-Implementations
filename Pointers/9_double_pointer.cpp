#include<iostream>
using namespace std;
void increment(int** p)
{
	p = p+1;			// no changes reflected
}
void increment(int** p)
{
	*p = *p+1;			// changes reflected
}
void increment(int** p)
{
	**p = **p+1;		// changes reflected
}
int main()
{
	int i = 10;
	int* p = &i;

	int** p2 = &p;
	cout<<p2<<endl;
	cout<<&p<<endl;

	cout<<p<<endl;
	cout<<*p2<<endl;
	cout<<&i<<endl;

	cout<<i<<endl;
	cout<<*p<<endl;
	cout<<**p2<<endl;
}