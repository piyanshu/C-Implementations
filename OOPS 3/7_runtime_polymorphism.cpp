#include<iostream>
using namespace std;
class vehicle
{
public:
	//if we have to use run time polymorphism, we have to add virtual keyword in base class
	virtual void print()
	{
		cout<<"vehicle"<<endl;
	}
};
class car : public vehicle
{
public:
	void print()
	{
		cout<<"car"<<endl;
	}
};
int main()
{
	car c;
	vehicle* v2;
	
/*	jab kabhi base class ka object point karega derived class ke object ko to humlogo ko ye dekhna hoga ki vaha runtime hai ya compiletime polymorphism hai*/

	v2 = &c;

	v2->print();	//At run time, v2 points to class car object then it prints the print of func of car class.
}