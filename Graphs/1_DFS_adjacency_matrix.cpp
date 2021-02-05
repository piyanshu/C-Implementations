#include<iostream>
using namespace std;

// In this print function we use Depth first search(DFS)
// see DFS and BFS traversal in detail from notes

void printDFS(int **edges, int n, int sv, bool visited[])
{
	cout<<sv<<endl;
	visited[sv] = true;
	for(int i=0; i<n; i++)
	{
		if(sv == i)
		{
			continue;
		}
		if(edges[sv][i] == 1)
		{
			if(visited[i] == false)
			{
				printDFS(edges, n, i, visited);
			}
		}
	}
}
void DFS(int** edges, int n)
{
	bool* visited = new bool[n];
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
	}
	for(int i=0; i<n; i++)
	{
		if(visited[i] == false)
		{
			printDFS(edges, n, i, visited);
		}
	}
	delete[] visited;
}
int main()
{
	int n;
	cout<<"Enter the no of vertices: ";
	cin>>n;
	int e;
	cout<<"Enter the no of edges: ";
	cin>>e;
	int** edges = new int*[n];
	for(int i=0; i<n; i++)
	{
		edges[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			edges[i][j] = 0;
		}
	}
	cout<<"Enter the vertex which makes edges"<<endl;
	for(int i=0; i<e; i++)
	{
		int first, second;
		cin>>first>>second;
		edges[first][second] = 1;
		edges[second][first] = 1;
	}
	DFS(edges, n);
	for(int i=0; i<n; i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
}