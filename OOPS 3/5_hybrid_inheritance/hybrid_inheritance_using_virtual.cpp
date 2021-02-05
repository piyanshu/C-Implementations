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
	vehicle(int x)
	{
		cout<<"vehicles parametrised construtor"<<" "<<x<<endl;
	}
	void print()
	{
		cout<<color<<"vehicle"<<endl;
	}
};
/*	By creating vehicle class virtual in car class, the car class doesnt have the copy of vehicle class.It can only points to vehicle class*/
/* by creating virtual it doesnt mean that we cant inherit properties and func*/
class car : virtual public vehicle 
{
public:
	int numgears;
	car() : vehicle(3) 
	{
		cout<<"cars default constructor"<<endl;
	}
	void print()
	{
		cout<<"car"<<endl;
	}
};
class truck : virtual public vehicle
{
public:
	truck() : vehicle(4)
	{
		cout<<"trucks default constructor"<<endl;
	}
	void print()
	{
		cout<<"truck"<<endl;
	}
};
class bus : public car, public truck
{
public:
	bus() : vehicle(5)
	{
		cout<<"bus default constructor"<<endl;
	}
};
int main()
{
	bus b;
	b.vehicle::print();
}