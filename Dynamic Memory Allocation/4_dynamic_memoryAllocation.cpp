// In static memory allocation the memory release automatically
// But in case of dynamic memory allocation the memory release manually
#include<iostream>
using namespace std;
int main()
{
	int* p = new int;
	delete p;		// p jisko point kar rha hai vo delete hoga

	p = new int;
	delete p;

	p = new int[50];
	delete[]p;
}