#include<iostream>
#include<cstring>
using namespace std;
class student
{
	int age;
public:
	char* name;
	student(int age, char* name)
	{
		this->age = age;
		//this->name = name;	//shallow copy

		this->name = new char[strlen(name) + 1];	//deep copy	
		strcpy(this->name, name);
	}
	student(student const &s)	// jab kabhi bhi func arguements me object pass karayenge 								to hamesha const & hi pass karayenge..jisse ki copy 									constructor call na ho.
	{
		this->age = s.age;
		//this->name = name;	//shallow copy

		this->name = new char[strlen(s.name) + 1];	//deep copy	
		strcpy(this->name, s.name);

	}
	void display()
	{
		cout<<age<<" "<<name<<endl;
	}
};
int main()
{
	char name[] = "abcd";
	student s1(10, name);
	s1.display();

	student s2(s1);		// Inbuilt copy constructor always do shallow copy
						// so in the case like arrays we always make our own copy constructor
	s2.name[0] = 'x';

	s2.display();
	s1.display();
}