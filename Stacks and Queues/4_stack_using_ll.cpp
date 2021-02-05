// Hum stack create kar rahe hain using linked list. Hum push or pop func banayenge
/* linked list ke andar agar hume push or pop func banana hai to 
hume head ki zarrot hoti hai isliye hum stack class me head data member ki zaroorat padegi
*/
#include<iostream>
using namespace std;
/* Hum jis bhi class ko template banaya aur class ka naam hum jaha kahi bhi use hoga
	uske angular brackets me hume data type mention karna hoga */
template<typename T>
class node
{
public:
	node<T>* next;
	T data;
	node(T data)
	{
		this->data = data;
		next = NULL;
	}
};
// is class T data type nahi pta to phir se template mention karna hoga
template<typename T>
class stack
{
	node<T>* head;
	int tsize;
public:
	stack()
	{
		head = NULL;
		tsize = 0;
	}
	void push(T element)
	{
		node<T>* newnode = new node<T>(element);
		newnode->next = head;
		head = newnode;
		tsize++;
	}
	T pop()
	{
		if(tsize == 0)
		{
			return -1;
		}
		node<T>* temp = head;
		head = head->next;
		temp->next = NULL;
		T ans = temp->data;
		delete temp;
		tsize--;
		return ans;
	}
	T top()
	{
		if(tsize == 0)
		{
			return -1;
		}
		return head->data;
	}
	int size()
	{
		return tsize;
	}
	bool isEmpty()
	{
		return tsize == 0;
	}
};
int main()
{
	stack<char> s;
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