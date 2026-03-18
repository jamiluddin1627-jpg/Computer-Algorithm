// Online C++ compiler to run C++ program online
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
    level[src] = 0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout<<par<<" ";
        for(int child: a[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
    int src, des;
    cin>>src, des;
    memset(vis, false, sizeof(vis));
    memset(level, -1 , sizeof(level));
    memset(parent, -1 , sizeof(parent));
    bfs(src);
    int x = des;
    while(x!=-1)
    {
        cout<<x<<" ";
        x = parent[x];
    }
    return 0;
}