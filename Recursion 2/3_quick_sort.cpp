#include<iostream>
using namespace std;
int partition(int input[], int si, int ei)
{
    int count = 0;
    for(int i=si+1; i<=ei; i++)
    {
        if(input[si] >= input[i])
        {
            count++;
        }
    }
    int index = si+count;
	int temp = input[si];
    input[si] = input[index];
    input[index] = temp;
    int i = si, j = ei;
    while(i<index && j>index)
    {
        if(input[i] <= input[index])
        {
            i++;
        }
        else if(input[j] > input[index])
        {
            j--;
        }
        else
        {
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }
	return index;
}
void quickSort(int input[], int si, int ei)
{
    if(si >= ei)
    {
        return ;
    }
    int index = partition(input, si, ei);
    quickSort(input, si, index-1);
    quickSort(input, index+1, ei);
}
void quickSort(int input[], int size)
{
	quickSort(input, 0, size-1);
}
int main()
{
	int n;
	cout<<"Enter the num of nodes: ";
	cin>>n;
	int* input = new int[n];
	cout<<"Enter your elements: ";
	for(int i=0; i<n; i++)
	{
		cin>>input[i];
	}
	quickSort(input, n);
	for(int i=0; i<n; i++)
	{
		cout<<input[i]<<" ";
	}
}