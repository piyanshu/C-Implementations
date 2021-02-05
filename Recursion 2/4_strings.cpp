#include<iostream>
using namespace std;
int main()
{
// Using string statically
	string s;
	s = "abc";
	cout<<s<<endl;
	string s1 = "def";
	cout<<s1<<endl;

// Using string dynamically
	string* sp = new string;
	*sp = "xyz";
	cout<<sp<<endl;
	cout<<*sp<<endl;

// If we want that it doest not breaks on space 
	getline(cin, s);
	cout<<s<<endl;

// Using string like an array
	s = "defdef";
	cout<<s[0]<<endl;
	s[0] = 'a';
	cout<<s<<endl;

// string concatenation
	s = "abc";
	s1 = "def";
	string s2 = s+s1;
	cout<<s2<<endl;
	s += s1;
	cout<<s<<endl;

// Using size func()
	s = "abcdef";
	cout<<s.size()<<endl;

// Using substr func()
	s = "abcdefabc";
	string s3 = s.substr(3);	// this func does not change s
	cout<<s3<<endl;
	s3 = s.substr(3, 5);		// 2nd arguement is length
	cout<<s3<<endl;

// find func()
	s3 = "aefdefdef";
	cout<<s3.find("def")<<endl;	// 3 (start index of def is 3)
// If def is not present it will prints garbage 
}