// BFS Traversal with Level Calculation
#include <bits/stdc++.h>
using namespace std;
vector<int> a[1005];
bool vis[1005];
int level[1005];
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
    int src;
    cin>>src;
    memset(vis, false, sizeof(vis));
    memset(level, -1 , sizeof(level));
    bfs(src);
    // Print the level of each vertex
    for(int i = 0; i<n; i++)
    {
        cout<< i <<" "<< level[i]<<endl;
    }
    return 0;
}