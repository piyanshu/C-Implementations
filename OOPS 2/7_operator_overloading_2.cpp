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
	void print()
	{
		cout<<numerator<<"/"<<denominator<<endl;
	}
	void simplify()
	{
		int gcd = 1;
		int minimum = min(numerator, denominator);
		for(int i=gcd; i<= minimum; i++)
		{
			if(numerator%i == 0 && denominator%i == 0)
			{
				gcd = i;
			}
		}
		numerator = numerator/gcd;
		denominator = denominator/gcd;
	}
// We have to return pass by reference when we have to do nesting to overload any operator
	fraction & operator++()
	{
		numerator = numerator + denominator;
		simplify();
		return *this;
	}
};
int main()
{
	fraction f1(10, 2);
	fraction f2(15, 4);
	fraction f3 = ++(++f1);
	f1.print();
	f3.print();
}