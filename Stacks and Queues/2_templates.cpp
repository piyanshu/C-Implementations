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
// Humne ek object banaya hai p jiske pass do data member hain T x and V y
// T = int, V = pair<double, char> 
// iska matlab x int type ka hai aur y ek object hai pair class ka jiske pass do data member hain x and y
	Pair<int, Pair<double, float>>p;
	p.setX(10);
	Pair<double, float>p1;
	p1.setX(20.456);
	p1.setY(30.456);
	p.setY(p1);

	cout<<p.getX()<<endl;
	Pair<double, float> ans = p.getY();
	cout<<ans.getX()<<" "<<ans.getY()<<endl;
}