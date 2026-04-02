#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<bool> visited;
void dfs(int node)
{
    visited[node] = true;
    cout<<node<<endl;
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
    int componentCount = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            componentCount++;
        }
    }
    cout << "Number of components: " << componentCount << endl;
    return 0;
}