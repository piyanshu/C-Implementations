/*
subsequences of string are not continuous.There are 2^n subsequences of a string
substrings are continuous
There is a string given, we have to add all its subsequences in a string array 
But we cannot return this string array because we dont know the size os string array in main()
so we can add all subsequences in string array and return the size of string array 
*/
#include<iostream>
#include<string>
using namespace std;
int subs(string input, string output[])
{
	if(input.empty())
	{
		output[0] = "";
		return 1;
	}
	string smallstring = input.substr(1);
	int size = subs(smallstring, output);	// in recursive call we cannot pass input+1
	for(int i=0; i<size; i++)
	{
		output[i+size] = input[0] + output[i];
	}
	return 2*size;
}
int main()
{
	string input;
	cout<<"Enter string: ";
	cin>>input;
	string output[1000];
	int size = subs(input, output);
	for(int i=0; i<size; i++)
	{
		cout<<output[i]<<endl;
	}
}