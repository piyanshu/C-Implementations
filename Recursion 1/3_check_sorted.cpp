/* Recursion in case of arrays
1. Base Case
2. 1 pe kaam karana hoga
3. Induction hypothesis
4. Induction step

Hum log step 2 or step 3 ko reverse bhi kar sakte hain, it depends on que
*/
#include<iostream>
using namespace std;
bool is_sorted2(int arr[], int size)
{
// Base case
	if(size == 0 || size == 1)
	{
		return true;
	}
// Induction hypothesis
	bool ans = is_sorted2(arr+1, size-1);
	if(!ans)
	{
		return false;
	}		
// 1 pe kaam 
	if(arr[0] > arr[1])
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool is_sorted1(int arr[], int size)
{
// Base case
	if(size == 0 || size == 1)
	{
		return true;
	}
// 1 pe kaam 
	if(arr[0] > arr[1])
	{
		return false;
	}
// Induction hypothesis
	bool ans = is_sorted1(arr+1, size-1);
	return ans;
}
int main()
{
	int arr[100];
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements of an array: ";
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<is_sorted1(arr, n)<<endl;
	cout<<is_sorted2(arr, n);
}