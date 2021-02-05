// Algorithm:

/*
Name: Piyanshu Mangla
Reg No: 201900008

Step 1: Create a class DM
         Step 1.1 Data Members
                  m
                  cm
         Step 1.2 Create Functions
         		  parameterised constructor DB() 
                  friend add()
                  Display()
Step 2: Create a class DB
         Step 2.1 Data Members
                 f
                 in
         Step 2.2 Create Functions
                 parameterised constructor DM()
                 friend add()
Step 3: Define the entire friend add() func
Step 4: main()
         Step 4.1 Create object of each class
         Step 4.2 Call add()
         Step 4.3 Display output
 Sample input
 	m: 3
 	cm: 50
 	f: 3
 	in: 50
 Sample output
 	5m 65cm
*/

#include<iostream>
using namespace std;
void helper();
class DM;
class DB
{
	int m;
	int cm;
public:
	DB(int m, int cm)
	{
		this->m = m;
		this->cm = cm;
	}
	void print()
	{
		cout<<m<<" "<<"metres"<<" "<<cm<<" "<<"centimeters"<<endl;
	}
	friend DB add(DB, DM);
};
class DM
{
	int f;
	int in;
public:
	DM(int f, int in)
	{
		this->f = f;
		this->in = in;
	}
	friend DB add(DB, DM);
};
DB add(DB a, DM b)
{
	int metres = a.m;
	int centimeters = a.cm;
	int b_total_inch = b.in + (12*b.f);
	int b_total_cm = 2.5*b_total_inch;
	centimeters = centimeters + b_total_cm;
	if(centimeters > 100)
	{
		metres = metres + (centimeters/100);
		centimeters = centimeters % 100;
	}
	DB ans(metres, centimeters);
	return ans;
}
int main()
{
	int m, cm, f, in;
	cout<<"Enter the distance in metres: ";
	cin>>m;
	cout<<"Enter the distance in centimeters: ";
	cin>>cm;
	cout<<"Enter the distance in feet: ";
	cin>>f;
	cout<<"Enter the distance in inches: ";
	cin>>in;
	DB a(m, cm);
	DM b(f, in);
	DB ans = add(a, b);
	ans.print();
}



