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
	vehicle()
	{
		cout<<"vehicles default construtor"<<endl;
	}
	void print()
	{
		cout<<"vehicle"<<endl;
	}
};
class car : public vehicle
{
public:
	int numgears;
	car()
	{
		cout<<"cars default constructor"<<endl;
	}
	// void print()
	// {
	// 	cout<<"car"<<endl;
	// }
};
class truck : public vehicle
{
public:
	truck()
	{
		cout<<"trucks default constructor"<<endl;
	}
};
class bus : public car, public truck
{
public:
	bus()
	{
		cout<<"bus default constructor"<<endl;
	}
};
int main()
{
	bus b;
	// b.print();	//this creates ambiguity because car and truck both have print func inherited from vehicle. 
	b.car::print();
}