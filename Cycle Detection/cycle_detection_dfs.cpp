#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
bool visited[N];
int parent[N];
bool cycle;
void dfs(int src)
{
    visited[src] = true;
    for(int children : graph[src])
    {
        if(!visited[children])
        {
            parent[children] = src;
            dfs(children);
        }
        else
        {
            if(parent[src] != children)
            {   
                cout<<"Cycle Detected at node: "<< children <<endl;
                cout<<"Parent of node "<< src << ": "<< parent[src] 
                <<" and children: "<< children <<endl;
                cycle = true;
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
            dfs(i);
        }
    }
    if(cycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }
    return 0;
}