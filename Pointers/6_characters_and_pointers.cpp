#include<iostream>
using namespace std;
int main()
{
	int a[] = {1, 2, 3};	
	char b[] = "abcd";	// name of array holds the adress
	cout<<a<<endl;
/* cout and cin behaves differently in case of char arrays 
	it goes to that adress and prints till null
*/
	cout<<b<<endl;		 

	char* c = &b[0];
	cout<<c<<endl;

	char c1 = 'a';
	char* pc = &c1;
	cout<<c1<<endl;
	cout<<pc<<endl;	// in this case also it goes to that adress and prints till null

// In this case one char array is allocated to us and put "abcde" in that
	char str[] = "abcde";
// but in this case pointer pstr holds the adress of buffer memory which can holds "abcde"
	char* pstr = "abcde";
	cout<<pstr<<endl;
}
