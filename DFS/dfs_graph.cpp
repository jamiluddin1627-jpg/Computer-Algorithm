#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<bool> visited;
void dfs(int node)
{
    visited[node] = true;
    cout<<node<<" ";
    for(int i: a[node])
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    a.resize(n);
    visited.resize(n, false);
    while(e--)
    {
        int u , v;
        cin>> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int node;
    cin>>node;
    dfs(node); 
    return 0;
}