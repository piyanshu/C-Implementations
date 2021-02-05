// user ko jitne bhi size ka stack create karna hoga sabse pehle hum utne hi size ke stack ko create karenge
// dynamically baad me banayenge aur templates bhi baad me use karenge

#include<iostream>
#include<climits>
using namespace std;
template<typename T>
class StackusingArray
{
/* Hume in dono ko private rakhna hoga 
   kyunki agar humne inka access user ko de diya to vo kisi bhi index ko access kar sakta hai 
   jo ki galat hai humare stack ke elements kisi particular order me hi access hone chahiye  */
	T* arr;
	int nextindex;
	int capacity;
public:
	StackusingArray()
	{
		arr = new T[4];
		nextindex = 0;
		capacity = 4;
	}
	int size()
	{
		return nextindex;
	}
	bool isEmpty()
	{
		return nextindex == 0;
	}
	T top()
	{
		if(nextindex == 0)
		{
			return 0;
		}
		return arr[nextindex-1];
	}
	void push(T element)
	{
		if(nextindex == capacity)
		{
			T* newarray = new T[2*capacity];
			for(int i=0; i<capacity; i++)
			{
				newarray[i] = arr[i];
			}
			delete [] arr;
			arr = newarray;
			capacity *= 2; 
		}
		arr[nextindex] = element;
		nextindex++;
	}
	T pop()
	{
		if(nextindex == 0)
		{
			cout<<"Stack empty"<<endl;
			return 0;
		}
		nextindex--;
		return arr[nextindex];
	}
};
int main()
{
	StackusingArray<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
}
// The time complexity for all the functions is O(1). 