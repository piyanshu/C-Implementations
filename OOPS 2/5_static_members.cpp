#include<iostream>
using namespace std;
class student
{
	/*Every object creates a copy of non static properties and non static func*/
	/*object can access the non static properties with the help of (.) , but static properties can be access on the line 28*/
	static int totalstudents;
public:
	int rollnumber;
	int age;
	// static int totalstudents;
	student()
	{
		totalstudents++;
	}
	/*staic func can access only static properties */
	/*static func do not have this keyword*/
	static int gettotalstudents()
	{
		return totalstudents;
	}
};
int student :: totalstudents = 0;
int main()
{
	student s1, s2, s3, s4, s5;
	// cout<<student :: totalstudents;
	cout<<student :: gettotalstudents();
}