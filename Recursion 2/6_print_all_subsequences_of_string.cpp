/*  agar hume ek string ke sare subsequences ko print karana hai 
	to hume unhe array mein dalke return karane ki zaroorat ni hai, 
	return karane se space bahut zyada use ho rha hai i.e. 2^n.
	to isliye hum return ki jagah print karayenge
*/ 
/*
Jab hum return kara rahe hai to hum pehle recursion se kaam kara rahe hain 
but is approach me hum print karayenge to hum apna ek decision lenge or usko aage pass karayenge
*/
#include<iostream>
using namespace std;
#include<string>
void printSub(string input, string output)
{
	if(input.empty())
	{
		cout<<output<<endl;
		return;
	}
	printSub(input.substr(1), output);
	printSub(input.substr(1), output+input[0]);
}
int main()
{
	string input;
	cin>>input;
	string output;
	printSub(input, output);
}