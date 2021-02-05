#include<iostream>
using namespace std;
/* When we pass an array to any func it will internally pass as pointer and 
	we can use pointer like an array
*/
// int sum(int a[], int n) rewrite as
int sum(int* a, int n)
{
	int ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += a[i];
	}
	return ans;
}
int main()
{
	int a[10];
	cout<<sum(a, 10);
// We can also pass part of an array to both types
	cout<<sum(a+3, 7);
}