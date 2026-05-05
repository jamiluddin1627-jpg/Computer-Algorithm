#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> a[N];
bool vis[N];
int level[N];
int parent[N];
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
        //cout<<par<<" ";
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
    //cout<<endl;  
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
    vector<int> path;
    if(!vis[x])
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<level[x]<<endl; // Print the length of the path
        while(x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        // Print the path in reverse order (from source to destination)
        for(int i = path.size() - 1; i >= 0; i--)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}