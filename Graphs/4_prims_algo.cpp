#include <iostream>
#include<climits>
using namespace std;
int findVertex(bool* visited, int* weight, int n)
{
    int min = INT_MAX;
    int vertex = -1;
    for(int i=0; i<n; i++)
    {
        if(visited[i] == false && weight[i] < min)
        {
            min = weight[i];
            vertex = i;
        }
    }
    return vertex;
}
void prims(int** graph, int n, int e)
{
    bool* visited = new bool[n];
    int* parent = new int[n];
    int* weight = new int[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    for(int j=0; j<n; j++)
    {
        int currentvertex = findVertex(visited, weight, n);
        visited[currentvertex] = true;
        for(int i=0; i<n; i++)
        {
            if(graph[currentvertex][i] != 0 && visited[i] == false)
            {
                if(graph[currentvertex][i] < weight[i])
                {
                    weight[i] = graph[currentvertex][i];
                    parent[i] = currentvertex;
                }
            }
        }
    }
    cout<<"/********/"<<endl;
    for(int i=1; i<n; i++)
    {
        if(parent[i] < i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}
int main() {
    // Write your code here
    int n, e;
    cout<<"Enter num of vertices and num of edges: ";
    cin>>n>>e;
    int** graph = new int*[n];
    for(int i=0; i<n; i++)
    {
        graph[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout<<"Enter your edges: ";
    for(int i=0; i<e; i++)
    {
        int first, second, weight;
        cin>>first>>second>>weight;
        graph[first][second] = weight;
        graph[second][first] = weight;
    }
    prims(graph, n, e);
}