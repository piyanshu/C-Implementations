#include<iostream>
using namespace std;
void merge(int input[], int si, int ei, int mid)
{
    int arr[ei-si+1];
    int i=si, j=mid+1, k=0;
    while(i<=mid && j<=ei)
    {
        if(input[i] <= input[j])
        {
            arr[k] = input[i];
            i++;
            k++;
        }
        else if(input[j] < input[i])
        {
            arr[k] = input[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        arr[k] = input[i];
        i++;
        k++;
    }
    while(j <= ei)
    {
        arr[k] = input[j];
        j++;
        k++;
    }
    int m = 0;
    while(si <= ei)
    {
        input[si] = arr[m];
    	si++;
        m++;
    }
}
void helper(int input[], int si, int ei)
{
    if(si >= ei)
    {
        return;
    }
    int mid = (si + ei)/2;
    helper(input, si, mid);
    helper(input, mid+1, ei);
    merge(input, si, ei, mid);
}
void mergeSort(int input[], int size){
	// Write your code here
    helper(input, 0, size-1);
}
int main()
{
	int n;
	cout<<"Enter num of elements: ";
	cin>>n;
	int* input = new int[n];
	cout<<"Enter your elements: ";
	for(int i=0; i<n; i++)
	{
		cin>>input[i];
	}
	mergeSort(input, n);
	for(int i=0; i<n; i++)
	{
		cout<<input[i]<<" ";
	}
}