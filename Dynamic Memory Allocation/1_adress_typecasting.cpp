#include<iostream>
using namespace std;
int main()
{
	int i = 65;
	char c = i;	// implicit typecasting-storing the data of one type into another type
	cout<<c<<endl;

	int* p = &i;	
	char* pc = (char*)p;// explicit typecasting-forced to convert one type of data into another 

	cout<<p<<endl;
	cout<<pc<<endl;

	cout<<*p<<endl;
	cout<<*pc<<endl;
	cout<<*(pc+1)<<endl;
	cout<<*(pc+2)<<endl;
	cout<<*(pc+3)<<endl;
}