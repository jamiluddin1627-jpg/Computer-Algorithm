// C++ program to perform BFS traversal on a graph
#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000]; // Assuming maximum 1000 vertices, array of vectors to store the adjacency list of the graph
bool vis[1000]; // To keep track of visited vertices during BFS
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true; // Mark the source vertex as visited
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " "; // Process the vertex (e.g., print it)
        for(int child: a[par])
        {
            // int child = a[par][i]; // Get the adjacent vertex
            if(!vis[child]) // If the adjacent vertex is not visited
            {
                q.push(child); // Enqueue the adjacent vertex
                vis[child] = true; // Mark the adjacent vertex as visited
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); 
        a[v].push_back(u); // For undirected graph
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));// Mark all vertices as unvisited
    bfs(src);
    return 0;
}