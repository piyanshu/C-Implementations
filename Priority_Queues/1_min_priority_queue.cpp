// In priority_queues the value of elements and their priority are same
// In this we can store the elements in an array and visualise like a binary tree
/* When we can do insert, deletion and anything else
   we have to always follow the properties complete binary tree and heap order property
*/
// lci = 2*i+1, rci = 2*i+2 where i is the parentindex
// parentindex = (c.i. - 1)/2 where c.i. is the childindex
// In Min Heap every node is smaller then its children
// In Max Heap every node is greater then its children 

#include<iostream>
#include<vector>
using namespace std;
class Priority_Queue
{
	vector<int>pq;
public:
	Priority_Queue()
	{

	}
	bool isEmpty()
	{
		return pq.size() == 0;
	}
	int getsize()
	{
		return pq.size();
	}
	int getMin()
	{
		if(isEmpty())
		{
			return 0;
		}
		return pq[0];
	}
	void insert(int element)
	{
		pq.push_back(element);
		int childindex = pq.size()-1;
		while(childindex > 0)
		{
			int parentindex = (childindex-1)/2;
			if(pq[childindex] < pq[parentindex])
			{
				int temp = pq[childindex];
				pq[childindex] = pq[parentindex];
				pq[parentindex] = temp;
			}
			else
			{
				break;
			}
			childindex = parentindex;
		}
	}
	int removeMin()
	{
		if(isEmpty())
		{
			return 0;
		}
		int size = pq.size();
		int ans = pq[0];
		pq[0] = pq[size-1];
        pq.pop_back();
		size--;
		int parentindex = 0;
		int lci = 2*parentindex+1;
		int rci = 2*parentindex+2;
		while(lci < size)
		{	
			int minindex = parentindex;
			if(pq[minindex] > pq[lci])
			{
				minindex = lci;
			}
			if(pq[minindex] > pq[rci] && rci < size)
			{
				minindex = rci;
			}
			if(minindex == parentindex)
			{
				break;
			}
			int temp = pq[parentindex];
			pq[parentindex] = pq[minindex];
			pq[minindex] = temp;
			parentindex = minindex;
			lci = 2*parentindex+1;
			rci = 2*parentindex+2;
		}
		return ans;
	}
};
int main()
{
	Priority_Queue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);
	cout<<p.getsize()<<endl;
	cout<<p.getMin()<<endl;

	while(!p.isEmpty())
	{
		cout<<p.removeMin()<<" ";
	}
	cout<<endl;
}
// When insert and remove all the elements we get the elements in increasing order
// In this the time complexity is -> O(nlogn)
/* space cpmplexity is -> O(n) because we used n sized vector to insert all the elements 
	to create a Min/Max Heap 
*/
// Our space complexity is bad, So we have to improve the space complexity see the next approach