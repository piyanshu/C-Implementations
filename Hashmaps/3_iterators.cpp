#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<string, int>ourmap;
	ourmap["abc"] = 1;
	ourmap["abc1"] = 2;
	ourmap["abc2"] = 3;
	ourmap["abc3"] = 4;
	ourmap["abc4"] = 5;
	ourmap["abc5"] = 6;
	unordered_map<string, int>::iterator it;
	it = ourmap.begin();
	while(it != ourmap.end())
	{
		cout<<"Key: "<<it->first<<" "<<"value: "<<it->second<<endl;
		it++;
	}
	it = ourmap.find("abc");
	cout<<"find"<<"Key: "<<it->first<<" "<<"value: "<<it->second<<endl;

	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it1;
	it1 = v.begin();
	while(it1 != v.end())
	{
		cout<<*it1<<" ";	// 1 2 3 4 5 6
		it1++;
	}
	cout<<endl;

	it1 = v.begin();
	v.erase(it1, it1+4);	// delete it1, it1+1, it1+2, it1+3
	cout<<*it1<<endl;		// 5
	v.erase(it1);
	cout<<*it1<<endl;		// 6
	
}