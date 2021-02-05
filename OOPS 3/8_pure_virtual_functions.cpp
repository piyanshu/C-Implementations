#include<iostream>
using namespace std;
class vehicle
{
public:
	//this is a pure virtual func which makes vehicle class abstract class.
	//abstract class means it is an incomplete class which doesnt make its objects
	virtual void print() = 0;
	vehicle()
	{
		
	}
};
class car : public vehicle
{
	// if we inherit an abstract class, we have two options
	// 1. complete the pure virtual func
	// 2. otherwise this class is abstract
public:
	int numgears;
	void print()
	{
		cout<<"car";
	}
};
int main()
{
	car c;
}