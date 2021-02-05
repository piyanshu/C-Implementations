// Reference variables can be initialised at the time of declaration
// uses- 1. When we pass to func by reference the changes will reflect in the main 
// 2. do not waste any memory
#include<iostream>
using namespace std;
void increment(int& n)
{
	n++;
}
/* agar hum log kisi bhi func ke local variable ka reference 
	return kara rhe hain to vo galat hai kyunki vo memory deallocate ho chuki hogi*/
int& f(int n)
{
	int a = n;
	return a;
}
/* agar hum log kisi bhi func ke local variable ka adress  
	return kara rhe hain to vo galat hai kyunki vo memory deallocate ho chuki hogi */
int* p()
{
	int i = 10;
	return &i;
}
int main()
{
	int i = 10;
/* j is a reference variable i.e j and i points to the same memory location, 
	no extra memory will create for j*/
	int&j = i;	
	i++;
	cout<<j<<endl;
	j++;
	cout<<i<<endl;

	int k = 100;
	j = k;
	cout<<i<<endl;

	increment(i);
	cout<<i<<endl;

	int& k1 = f(i);

	int* k2 = p();
}