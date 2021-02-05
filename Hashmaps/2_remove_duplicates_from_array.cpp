#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>remove_duplicates(int* arr, int size)
{
	vector<int>output;
	unordered_map<int, bool>ourmap;
	for(int i=0; i<size; i++)
	{
		if(ourmap.count(arr[i]) > 0)
		{
			continue;
		}
		ourmap[arr[i]] = true;
		output.push_back(arr[i]);
	}
	return output;
}
int main()
{
	int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
	vector<int>output = remove_duplicates(a, 11);
	for(int i=0; i<output.size(); i++)
	{
		cout<<output[i]<<endl;
	}
}