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
	void print() const
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
	fraction operator+(fraction const & f2) const
	{
		int lcm = denominator * f2.denominator;
		int x = (lcm/denominator) * numerator;
		int y = (lcm/f2.denominator) * f2.numerator;
		int num = x + y;
		fraction fnew(num, lcm);
		fnew.simplify();
		return fnew;
	}
	fraction operator*(fraction const & f2) const 
	{
		int num = numerator * f2.numerator;
		int lcm = denominator * f2.denominator;
		fraction fnew(num, lcm);
		fnew.simplify();
		return fnew;
	}
	bool operator==(fraction const & f2) const 
	{
		return numerator == f2.numerator && denominator == f2.denominator;
	}
};
int main()
{
	fraction f1(10, 2);
	fraction f2(15, 4);
	fraction f3 = f1 + f2;
	f3.print();
	fraction f4 = f1*f2;
	f4.print();
	if(f1 == f2)
	{
		cout<<"Equal"<<endl;
	}
	else
	{
		cout<<"Not equal";
	}
}