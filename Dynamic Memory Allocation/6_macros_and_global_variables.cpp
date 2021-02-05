/*
advantages of macros
1. agar hume pi ki value chaange karni ho to hume sab jagah jane ki zaroorat nahi hai
2. agar bad mein galti se value change kardi
*/
#include<iostream>
using namespace std;
#define PI 3.14
int main()
{
	int r;
	cout<<"Enter the value of r: ";
	cin>>r;
	cout<<PI*r*r;
}

// using global variables in program is a bad practice
/*
#include<iostream>
using namespace std;
int a;
void g()
{
	a++;
	cout<<a<<endl;
}
void f()
{
	cout<<a<<endl;
	a++;
	g();
}
int main()
{
	a = 10;
	f();
	cout<<a<<endl;
}
*/