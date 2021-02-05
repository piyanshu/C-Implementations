#include<iostream>
using namespace std;
class fraction
{
public:
	int numerator;
	int denominator;
	fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	friend void operator << (ostream &out, const fraction &f1); 
    friend void operator >> (istream &in,  fraction &f1); 
};
// fraction class ke functions ke pass jo this pointer uske undar adress sirf fraction ka hi aa sakta hai..cin istream class ka object hai
	void operator>>(istream & in, fraction & f1)
	{
		cout<<"Enter numerator: "<<endl;
		in>>f1.numerator;
		cout<<"Enter denominator: "<<endl;
		in>>f1.denominator;
		// return in;
	}
// fraction class ke functions ke pass jo this pointer uske undar adress sirf fraction ka hi aa sakta hai..cout ostream class ka object hai
	void operator<<(ostream & out, fraction const & f1)
	{
		cout<<f1.numerator;
		cout<<f1.denominator;
	}
int main()
{
	fraction f1(15, 4);
	cin>>f1;
	cout<<f1;
}