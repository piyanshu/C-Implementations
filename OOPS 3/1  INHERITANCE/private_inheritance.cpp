#include<iostream>
using namespace std;
class vehicle
{
private:
	int numtyres;
protected:
	int maxspeed;
public:
	string color;
};
class car : private vehicle
{
/*
	Inherit properties from vehicle class
	private:
		int maxspeed;
	private:
		string color;
*/
public:
	int numgears;
	void print()
	{
		cout<<"numgears: "<<numgears;
	}
};
int main()
{
	car c;
	// c.color = "Black";	These properties are private and cannot be used outside the car class 
	// c.maxspeed = 130;

	c.numgears = 3;
	c.print();
}
