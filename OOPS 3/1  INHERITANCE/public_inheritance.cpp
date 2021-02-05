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
class car : public vehicle
{
/*
	Inherit properties of class vehicle
	protected:
		int maxspeed;
	public:
		string color;
	// Private properties cant be inherited
*/
public:
	int numgears;
	void print()
	{
		cout<<"color: "<<color<<" "<<"numgears: "<<numgears<<endl;
	}
};
int main()
{
	vehicle v;
	car c;
	c.color = "black";
	c.numgears = 4;
	// protected properties can only be accessible within child classes
	// c.maxspeed = 130;

	c.print();
}