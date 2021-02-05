#include<iostream>
using namespace std;
template<typename T, typename V>
class Pair
{
	T x;
	V y;
public:
	void setX(T x)
	{
		this->x = x;
	}
	T getX()
	{
		return x;
	}
	void setY(V y)
	{
		this->y = y;
	}
	V getY()
	{
		return y;
	}
};
int main()
{
//  jab kabhi bhi hum class naam likhenge to hume angular brackets me data type mention karna hoga
/*  Humne ek pair class ka object banaya p jiske pass do data member hain T x and V y
	T = int, V = double */
	Pair<int, double>p;
	p.setX(30.14);
	p.setY(10.151);
	cout<<p.getX()<<" "<<p.getY()<<endl;
}