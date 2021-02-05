#include<iostream>
#include<cstring>
using namespace std;
class teacher
{
public:
	string name;
	int age;
	void print()
	{
		cout<<"teacher"<<endl;
	}
};
class student 
{
public:
	string name;
	void print()
	{
		cout<<"student"<<endl;
	}
};
class ta : public teacher, public student
{
public:
	void print()
	{
		cout<<"ta"<<endl;
	}
};
int main()
{
	ta a;
	a.print();
	/*	pehle ta class ka object a apne andar chack karega ki print func hai ya nahi hai to call ho jayega*/
	/* agar nahi hai to apne parent classes se inherit karega jisse ki ambiguity hogi to humlogo ko scope resolution operator ki madad leni hogi*/
	a.student::print();
	// a.name = "abcd";	//this creates ambiguity because both class have student and teacher */
	a.teacher::name = "abcd";
}