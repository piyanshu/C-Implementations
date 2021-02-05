// queue - FIFO (First In First Out) structure
// sabse pehle hum circular queue ka size user se mangege uske baad hum use dynamic banayenge
#include<iostream>
using namespace std;
template<typename T>
class QueueUsingArray
{
// Agar humne array ko public kar diya to user kisi bhi order me elements ko access karega jo ki galat hai
	T* data;
public:
	int nextindex;
	int firstindex;
	int capacity;
	int size;
	QueueUsingArray()
	{
		data = new T[5];
		nextindex = 0;
		firstindex = -1;
		size = 0;
		capacity = 5;
	}
	int getsize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size == 0;
	}
	void enqueue(T element)
	{
		if(size == capacity)
		{
			T* temp = new T[2*capacity];
			int j=0;
			for(int i=firstindex; i<size; i++)
			{
				temp[j] = data[i];
				j++;
			}
			for(int i=0; i<nextindex; i++)
			{
				temp[j] = data[i];
				j++;
			}
			delete []data;
			data = temp;
			firstindex = 0;
			nextindex = size;
			capacity = capacity * 2;
		}
		data[nextindex] = element;
		nextindex = (nextindex+1) % capacity;
		if(firstindex == -1)
		{
			firstindex = 0;
		}
		size++;
	}
	T front()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty";
			return 0;
		}
		return data[firstindex];
	}
	T dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue is empty";
			return 0;
		}
		T ans = data[firstindex];
		firstindex = (firstindex+1)%capacity;
		size--;
		if(size == 0)
		{
			firstindex = -1;
			nextindex = 0;
		}
		return ans;
	}
};
int main()
{
	QueueUsingArray<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;

	cout<<q.getsize()<<endl;
	cout<<q.isEmpty()<<endl;	
}