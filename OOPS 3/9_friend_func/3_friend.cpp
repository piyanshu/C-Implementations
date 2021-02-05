#include<iostream>
using namespace std;
class bus
{
public:
	void print();
};
void test();
class truck 
{
private:
	int x;
protected:
	int y;
public:
	int z;
	friend void test();
	friend void bus :: print();
};
void test()
{
	truck t;
	t.x = 10;
	t.y = 20;
	t.z = 30;
	cout<<t.x<<" "<<t.y<<endl;
}
void bus :: print()
{
	truck t;
	t.x = 10;
	t.y = 20;
	cout<<t.x<<" "<<t.y;
}
int main()
{
	test();
	bus b;
	b.print();
}