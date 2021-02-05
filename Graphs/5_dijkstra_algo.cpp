#include <iostream>
#include<climits>
using namespace std;
int findVertex(int* distance, bool* visited, int n)
{
    int min_distance = INT_MAX;
    int vertex = -1;
    for(int i=0; i<n; i++)
    {
        if(visited[i] == false && distance[i] < min_distance)
        {
            min_distance = distance[i];
            vertex = i;
        }
    }
    return vertex;
}
void Dijkstras(int** graph, int n, int e)
{
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int* distance = new int[n];
    for(int i=0; i<n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int j=0; j<n; j++)
    {
        int currentvertex = findVertex(distance, visited, n);
        visited[currentvertex] = true;
        for(int i=0; i<n; i++)
        {
            if(graph[currentvertex][i] != 0 && visited[i] == false)
            {
                int d = distance[currentvertex] + graph[currentvertex][i];
                if(d < distance[i])
                {
                    distance[i] = d;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
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
    int first, second, weight;
    cout<<"Enter your edges: ";
    for(int i=0; i<e; i++)
    {
        cin>>first>>second>>weight;
        graph[first][second] = weight;
        graph[second][first] = weight;
    }
    Dijkstras(graph, n, e);
}