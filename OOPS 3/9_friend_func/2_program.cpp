/*
ALGORITHM
Name: Piyanshu Mangla
Reg no: 201900008
1. Start
2. A class named Twovalues is declared
	a. default constructor->Twovalues is called
	b. Declare class Min_Max as friend of Twovalues
3. A class named Min_Max is declared 
	a. Minimum and Maximum operation is done inside find(Twovalues const & t) func
4. In main() func
	a. The values of the Twovalues(object) t is declared
	b. Call the find func with the help of Min_Max object m and pass the object t.

Sample input and output:
	INPUT:
Enter the value of first integer type data member: 50
Enter the value of second integer type data member: 10
	OUTPUT: 
Minimum value: 10
Maximum value: 50

*/
#include<iostream>
using namespace std;
class Twovalues
{
	int x;
	int y;
public:
	Twovalues(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	friend class Min_Max;
};
class Min_Max
{
public:
	void find(Twovalues const & t)
	{
		int minimum = min(t.x, t.y);
		int maximum = max(t.x, t.y);
		cout<<"Minimum value: "<<minimum<<endl;
		cout<<"Maximum value: "<<maximum<<endl;
	}
};
int main()
{
	int x, y;
	cout<<"Enter the value of first integer type data member: ";
	cin>>x;
	cout<<"Enter the value of second integer type data member: ";
	cin>>y;
	Twovalues t(x, y);
	Min_Max m;
	m.find(t);

}