#include<iostream>
using namespace std;
/* jab humne func ko inline declare kara to uska matlab hai ki 
	us func ki jo body hai vo vaha chali jayegi jaha humne us func ko call kara hai
*/
/*
agar func ki body 1 line hai to compiler inline kar deta hai, 2 or 3 lines depends on compiler
agar usse zyada hoga to compiler inline karega hi nahi
*/
inline int max(int a, int b)
{
	return (a>b) ? a : b;
}

// We have to set the default arguements from right to left
// If we cannot pass the value of any default arguement it will set it as 0.

int sum(int a, int b, int c = 0, int d = 0) // a = 2, b = 3, c = 0, d = 0
{
	return a+b+c+d;
}
int main()
{
	int a, b;
	cin>>a>>b;
	int c = max(a, b);
	int x, y;
	cin>>x>>y;
	int z = max(x, y);
	sum(2, 3, 4);
}