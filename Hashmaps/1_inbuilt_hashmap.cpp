// Hum log hashmaps ko vaha use karte hain jaha hume check karana ho ki vo aa chuka hai ya nahi
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
// 1.Insert
	unordered_map<string, int>ourmap;
	pair<string, int>p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 1;

// 2.Find or Access
	cout<<ourmap["abc"]<<endl;
	cout<<ourmap.at("def")<<endl;

// 3.Size
	cout<<"size: "<<ourmap.size()<<endl;

// 4. Check presence
	if(ourmap.count("abc") > 0)
	{
		cout<<"abc is present"<<endl;
	}

// 5. Erase
	ourmap.erase("abc");
	cout<<"size: "<<ourmap.size()<<endl;
}