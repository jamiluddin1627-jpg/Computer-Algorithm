#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<bool> visited;
int countNode[] = {0};
void dfs(int node)
{
    visited[node] = true;
    countNode[0]++;
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
    for(int i = n - 1; i >= 0; i--)
    {
        if(!visited[i])
        {
            dfs(i);
            cout << countNode[0] << endl;
            countNode[0] = 0; // reset the count for the next component
        }
    }
    return 0;
}