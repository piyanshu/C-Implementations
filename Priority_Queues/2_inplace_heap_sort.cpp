/* In this que the input array is already given 
	so we can create a min heap in input array itself and when we remove elements
	we get the elements in decreasing order
*/
// time complexity -> O(nlogn)
// space complexity -> O(1) because we cannot use any extra n sized array

#include<iostream>
using namespace std;
void removemin(int arr[], int n)
{
    while(n > 1)
    {
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp;
        n--;
        int parentindex = 0;
        int lci = 2*parentindex+1;
        int rci = 2*parentindex+2;
        while(lci < n)
        {
            int minindex = parentindex;
            if(arr[minindex] > arr[lci])
            {
                minindex = lci;
            }
            if(arr[minindex] > arr[rci] && rci < n)
            {
                minindex = rci;
            }
            if(minindex == parentindex)
            {
                break;
            }
            int temp = arr[parentindex];
            arr[parentindex] = arr[minindex];
            arr[minindex] = temp;
            parentindex = minindex;
            lci = 2*parentindex+1;
            rci = 2*parentindex+2;
        }
    }
}
void minHeap(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int childindex = i;
        while(childindex > 0)
        {
            int parentindex = (childindex-1)/2;
            if(arr[parentindex] > arr[childindex])
            {
                int temp = arr[parentindex];
                arr[parentindex] = arr[childindex];
                arr[childindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
    	}
    }
}
void heapSort(int arr[], int n) {
    minHeap(arr, n);
    removemin(arr, n);
}
int main()
{
	int input[] = {5, 1, 2, 0, 8};
	heapSort(input, 5);
	for(int i=0; i<5; i++)
	{
		cout<<input[i]<<" ";
	}
}