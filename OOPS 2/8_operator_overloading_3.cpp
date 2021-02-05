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
	fraction operator++(int)
	{
		fraction fnew(numerator, denominator);
		numerator = numerator + denominator;
		fnew.simplify();
		simplify();
		return fnew;
	}
	fraction & operator+=(fraction const & f2)
	{
		int lcm = denominator * f2.denominator;
		int x = (lcm/denominator) * numerator;
		int y = (lcm/f2.denominator) * f2.numerator;
		int num = x + y;
		numerator = num;
		denominator = lcm;
		simplify();
		return *this;
	}
};
int main()
{
	fraction f1(10, 2);
	fraction f2 = f1++;
	f2.print();
	f1.print();


	fraction f3(10, 2);
	fraction f4(15, 4);
	(f3 += f4) += f4;
	f3.print();
}