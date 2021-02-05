#include <iostream>
#include<queue>
using namespace std;
void printBFS(int** edges, int n, bool visited[], int sv)
{
    queue<int>pendingvertices;
    pendingvertices.push(sv);
    visited[sv] = true;
    while(!pendingvertices.empty())
    {
        int front = pendingvertices.front();
        pendingvertices.pop();
        cout<<front<<" ";
        for(int i=0; i<n; i++)
        {
            if(front == i)
            {
                continue;
            }
            if(edges[front][i] == 1)
            {
                if(visited[i] == false)
                {
        			pendingvertices.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}
void BFS(int** edges, int n)
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
            printBFS(edges, n, visited, i);
        }
    }
    delete[] visited;
}
int main() {
    // Write your code here
    int n, e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i=0; i<e; i++)
    {
        int first, second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    BFS(edges, n);
    for(int i=0; i<n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}