/*  We have given an array and the value of K. We have to sort that array 
	after sorting it always a valid example of k sorted array
*/
/*
If the size of heap is n then time complexity of inserting one element into heap is O(logn)
*/
#include<iostream>
#include<queue>
using namespace std;
void Ksorted_Array(int arr[], int k, int n)
{
	priority_queue<int>pq;
	for(int i=0; i<k; i++)
	{
		pq.push(arr[i]);		// Time complexity of this loop is O(klogk)
	}
	int j = 0;
	for(int i=k; i<n; i++)
	{
		arr[j] = pq.top();
		pq.pop();				// Time complexity of this loop is O((n-k)logk) 
		pq.push(arr[i]);
		j++;
	}
	while(!pq.empty())
	{
		arr[j] = pq.top();
		pq.pop();				// Time complexity of this loop is O(klogk)
		j++;
	}
	/* 
	Time complexity of this func is 
		= klogk + nlogk - klogk + klogk
		= (n+k)logk
		= nlogk			n >> k
		= n             n >> k
		= O(n)
	*/
}
int main()
{
	int arr[] = {10, 12, 15, 6, 9};
	int k = 3;
	Ksorted_Array(arr, 3, 5);
	for(int i=0; i<5; i++)
	{
		cout<<arr[i]<<" ";
	}
}