/* 3 steps of recursion
1. Base case - Hume base case aisa choose karna hota hai 
				ki recursive call last mein isko hit kare
2. Induction Hypothesis - Recursive call(Assume kar lena hai ki humare pass
							small input ka ans aa chuka hai)
3. Induction Step - Hume apna final ans return karna hoga\
*/
#include<iostream>
using namespace std;
int factorial(int n)
{
// Base case
	if(n == 0)
	{
		return 1;
	}
// Hypothesis
	int ans = factorial(n-1);
// Final ans
	return n*ans; 
}
int main()
{
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<factorial(n);
}