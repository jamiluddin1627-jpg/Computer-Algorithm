#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *adjList;// Dynamic array of lists
public:
    Graph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    void printAdjList()
    {
        for(int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ": ";
            for(int neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.printAdjList();
    return 0;
}