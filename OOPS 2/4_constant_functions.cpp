#include<iostream>
using namespace std;
class student
{
public:
	int age;
	int rollnumber;
	/* To initialise the values of const object we have to always make our own constructor*/
	student()
	{
	    cout<<"default constructor!"<<endl;
	}
	/* 	constant functions are those which cannot changes the value of current object	*/
	void print() const
	{
		cout<<rollnumber<<" "<<age<<endl;
	}
};
int main()
{
	student const s;
	s.print();	/* constant objects can call only constant functions  */
}