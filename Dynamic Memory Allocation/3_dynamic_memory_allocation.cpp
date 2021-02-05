// We have now to solve the biggest problems in array i.e. we cannot make variable sized arrays
// int n;
// cin>>n;
// int arr[n]. user will tell the value of n at run time
/* Upar vala case mein compiler kuch stack memory leke chalega agar usne n ki 
	value zyada daldi to compiler utne size ka array create hi nahi kar payega
*/

// There are two types of memory stack and heap. Size of stack < size of heap
/* In stack memory we tell to compiler the size of an array at compile time 
	but in case of heap memory we tell its size at run time*/
/* if we create the memory in stack it is known as static memory allocation 
but if we create the memory in heap it is dynamic memory allocation */
// int i=10, int arr[20]. These types of memory will allocated in stack memory

// Creating dynamic memory allocation
#include<iostream>
using namespace std;
int main()
{
	int* p = new int;	// 4 bytes on heap and 8 bytes on stack
	*p = 10;

	double* pd = new double;

	int* pa = new int[50];	// 200 bytes on heap and 8 bytes on stack

	int n;
	cout<<"Enter the no. of elements: ";
	cin>>n;
	int* pa2 = new int[n]; 
	for(int i=0; i<n; i++)
	{
		cin>>pa2[i];
	}
	int max = -1;
	for(int i=0; i<n; i++)
	{
		if(max < pa2[i])
		{
			max = pa2[i];
		}
	}
	cout<<max<<endl;
}