#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 1;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout<<par<<" ";
        for(int child: a[par])
        {
            if(!vis[child])
            {
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
                q.push(child);
            }
        }
        
    }
    cout<<endl;  
}
int main() {
    int n, e;
    cin>>n>>e;
    while(e--)
    {
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1 , sizeof(level));
    memset(parent, -1 , sizeof(parent));
    bfs(1);

    int x = n; // Assuming we want to find the path to the last node
    
    if(!vis[x])
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<level[x]<<endl; // Print the length of the path
        while(x != -1)
        {
            cout<<x<<" "; // Print the path from destination to source
            x = parent[x]; 
        }
    }
    return 0;
}