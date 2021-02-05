#include<iostream>
using namespace std;
// copying will not takes place and it promises not to change the value
void g(int const & a)
{
	// a++;
}
void f(int const *p)
{
	// (*p)++;			// p has access only to read			
}
int main()
{
	int const i = 10;		// read access
	int const *p = &i;		// read access

	int j = 12;				// read and write access

	f(&j);
	g(j);

	int const * p2 = &j;	// read access
	cout<<*p2<<endl;
	j++;
	cout<<*p2<<endl;

}