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
class car : protected vehicle
{
/*
	Inherit properties from vehicle class
	protected:
		int maxspeed;
	protected:
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
	// c.color = "Black";	These properties are protected and cannot be used outside the car class
	// c.maxspeed = 130;

	c.numgears = 3;
	c.print();
}
