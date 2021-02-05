#include<iostream>
using namespace std;
class student
{
public:
	int age;
	int const rollnumber;
	int & x;
	
	/*  const and refernce variables are initialise at the time of its creation  */
	/*  So we have to take use initialisation list. In case of initialisation list we have to create our own constructor*/
	
	student(int r, int age) : rollnumber(r), age(age), x(this->age)
	{
		cout<<"constructor called!";
	}
};
int main()
{
	student s(10, 20);
}