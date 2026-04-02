#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
bool visited[N];
int parent[N];
bool cycle;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int children : graph[node])
        {
            if(!visited[children])
            {
                visited[children] = true;
                parent[children] = node;
                q.push(children);
            }
            else
            {
                if(parent[node] != children)
                {
                    cycle = true;
                }
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for(int i = 0; i < n; i++) // 0-based indexing
    {
        if(!visited[i]) 
        {
            bfs(i);
        }
    }
    if(cycle)
    {
        cout << "Cycle Detected!" << endl;
    }
    else
    {
        cout << "No Cycle Detected!" << endl;
    }
    return 0;
}