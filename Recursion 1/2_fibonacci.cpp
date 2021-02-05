#include<iostream>
using namespace std;
int fib(int n)
{
// Base case
/* Here there are two base cases because if we have to find any fibonacii no
	we have to find the sum of two previous fibonacii numbers */
	if(n == 0 || n == 1)
	{
		return n;
	}
// Hypothesis
	int fib1 = fib(n-1);
	int fib2 = fib(n-2);
// Final step
	return fib1+fib2;
}
int main()
{
	int n;
	cout<<"Enter the which fibonacii number you want to access: ";
	cin>>n;
	cout<<fib(n);
}