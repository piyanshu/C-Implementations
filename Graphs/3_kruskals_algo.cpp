#include <iostream>
#include<algorithm>
using namespace std;
class Edge
{
    public:
	int source;
    int dest;
    int weight;
};
int findparent(int v, int* parent)
{
    if(parent[v] == v)
    {
        return v;
    }
    return findparent(parent[v], parent);
}
bool compare(Edge e1, Edge e2)
{
// If we want to sort our input array in increasing order we can write it like this
    return e1.weight < e2.weight;
}
void kruskals(Edge* input, int n, int e)
{
// We can tell to compiler to sort an input array using compare func
    sort(input, input+e, compare);
    int* parent = new int[n];
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    Edge* output = new Edge[n-1];
    int i=0;
    int count = 0;
    while(count != n-1)
    {
        Edge currentedge = input[i];
        int sourceparent = findparent(currentedge.source, parent);
    	int destparent = findparent(currentedge.dest, parent);
    	if(sourceparent != destparent)
        {
            output[count] = currentedge;
        	count++;
            parent[sourceparent] = destparent;
        }
 		i++;       
    }
    cout<<endl<<"/********/"<<endl;
    for(int i=0; i<n-1; i++)
    {
 		if(output[i].source < output[i].dest)
        {
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main() {
    // Write your code here
    int n, e;
    cout<<"Enter num of vertices and num of edges: ";
    cin>>n>>e;
    Edge* input = new Edge[e];
    cout<<"Enter your edges: ";
	for(int i=0; i<e; i++)
    {
        int s, d, w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskals(input, n, e);
}

