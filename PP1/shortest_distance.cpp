#include<bits/stdc++.h>
using namespace std;
vector<int> a[1000]; // Assuming maximum 1000 vertices, array of vectors to store the adjacency list of the graph
bool vis[1000]; // To keep track of visited vertices during BFS
int level[1000]; // To store the level (distance) of each vertex from the source
int parent[1000]; // To store the parent of each vertex in the BFS tree
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true; // Mark the source vertex as visited
    level[src] = 0; // Level of source vertex is 0
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        //cout << par << " "; // Process the vertex (e.g., print it)
        for(int child: a[par])
        {
            if(!vis[child]) // If the adjacent vertex is not visited
            {
                q.push(child); // Enqueue the adjacent vertex
                vis[child] = true; // Mark the adjacent vertex as visited
                level[child] = level[par] + 1; // Set the level of the adjacent vertex
                parent[child] = par; // Set the parent of the adjacent vertex
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

    int q;
    cin >> q; // Number of queries
    while(q--)
    {
        memset(vis, false, sizeof(vis));
        memset(level, -1 , sizeof(level));
        memset(parent, -1 , sizeof(parent));
        int src, des;
        cin >> src >> des; // Source and destination vertices for the query
        bfs(src); // Perform BFS from the source vertex
        cout<<level[des]<<endl; // Print the level (distance) of the destination vertex from the source
    }
    return 0;
}