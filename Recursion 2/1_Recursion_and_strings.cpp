#include<iostream>
using namespace std;
void removeX(char arr[])
{
	if(arr[0] == '\0')
	{
		return;
	}
	if(arr[0] == 'x')
	{
		int i=1;
		for(; arr[i] != '\0'; i++)
		{
			arr[i-1] = arr[i];
		}
		arr[i-1] = arr[i];
		removeX(arr);
	}
	else
	{
		removeX(arr+1);
	}
}
int len(char arr[])
{
	if(arr[0] == '\0')
	{
		return 0;
	}
	int l = len(arr+1);
	return l+1;
}
int main()
{
	char arr[100];
	cin>>arr;
	int l = len(arr);
	cout<<l<<endl;
	removeX(arr);
	cout<<arr;
}