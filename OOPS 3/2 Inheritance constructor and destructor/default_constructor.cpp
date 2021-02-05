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
		cout<<"vehicles default constructor"<<endl;
	}
	~vehicle()
	{
		cout<<"vehicles destructor"<<endl;
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
	~car()
	{
		cout<<"cars destructor"<<endl;
	}
	void print()
	{
		cout<<"numgears: "<<numgears;
	}
};
class hondacity : public car
{
public:
	hondacity()
	{
		cout<<"hondacity default constructor"<<endl;
	}
	~hondacity()
	{
		cout<<"hondacity destructor"<<endl;
	}
};
int main()
{
	/*	child ka constructor call hone se pehle parent ka constructor call hoga	*/
	/*	Implicitly parent ka default constructor call hoga, agar parent ka parameterised constructor call karna hai to explicitly karna hoga*/
	/*	 constructor jis order me call hote hain use reverse order me destructor call honge*/
	hondacity h;
}
