//Find the nodes at a given level in a graph using BFS
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<bool> vis;
vector<int> level;

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    
    vis[src] = true;
    level[src] = 0;
    
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int chil: a[par])
        {
            if(!vis[chil])
            {
                q.push(chil);
                vis[chil] = true;
                level[chil] = level[par] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    a.resize(n);
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vis.assign(n, false);
    level.assign(n, -1);
    bfs(0);
    int l;
    cin>>l;
    for(int i = n-1; i>=0; i--)
    {
        if(level[i] == l)
        {
            cout<<i<<" ";
        }
    }
     
    return 0;
}