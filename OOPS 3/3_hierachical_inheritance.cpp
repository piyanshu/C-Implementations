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
public:
	int numgears;
};
class hondacity : public vehicle
{

};
int main()
{
/*	car and hondacity class inherit properties from vehicle	 */
/*	when there is one parent class and many child classes inherit properties from parent class */
/*	Hierarchical structure is tree like structure	*/

}