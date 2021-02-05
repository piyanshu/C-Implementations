#include<iostream>
using namespace std;
class vehicle
{
public:
	int maxspeed;
	void print()
	{
		cout<<maxspeed<<" "<<"vehicle"<<endl;
	}
};
class car : public vehicle
{
	// Here func and property is overriding because vehicle has maxspeed and print and class inherit from it. but we can make another property and func with same name as in the vehicle class thats why it is overriding.
public:
	int maxspeed;
	void print()
	{
		cout<<maxspeed<<" "<<"car"<<endl;
	}
};
int main()
{
	car c;
	vehicle* v2;

	v2 = &c;
	v2->print();	//At compile time, v2 is the object of class vehicle then it pints to vhicle class and prints the print func of vehicle class 

	v2->maxspeed = 100;	//at compile time v2 is the object of vehicle class it updates the value maxspeed only in vehicle class.
	v2->print();
	c.print();

}