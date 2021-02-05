#include<iostream>
using namespace std;
int main()
{
	int a[10];
	
	cout<<a<<endl;
	cout<<&a[0]<<endl;

	a[0] = 5;
	a[1] = 10;

	cout<<*a<<endl;
	cout<<*(a+1)<<endl;		// a[1] = *(a+1) and a[i] = *(a+i)

// differences between arrays and pointers
/* 
	all the differences can be made because jab hum pointer ko declare karte hain
	to humare pass extra 8 bytes allocate hote hain but arrays ke case me aisa nahi hota
	jab humne array ko decare kara to uska adress store karane ke liye kisi bhi pointer ks use nahi kiya
*/

// 1. &operator
	int* p = &a[0];
	cout<<&a<<endl;
	cout<<&p<<endl;

// 2. sizeof
	cout<<sizeof(p)<<endl;
	cout<<sizeof(a)<<endl;

// 3.
	p = p+1;
	// a = a+1;		Arrays cannot be reassignable
}