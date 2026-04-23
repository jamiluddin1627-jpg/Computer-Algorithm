#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int groupSize[N];
void dsu_init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
        groupSize[i] = 1;
    }
}
int find_parent(int u)
{
    if(parent[u] == u)
    {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}
void dsu_union(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);
    int leaderA = find_parent(u);
    int leaderB = find_parent(v);
    if(groupSize[leaderA] > groupSize[leaderB])
    {
        parent[leaderB] = leaderA;
        groupSize[leaderA] += groupSize[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        groupSize[leaderB] += groupSize[leaderA];
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    bool hasCycle = false;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        if(find_parent(u) == find_parent(v))
        {
            hasCycle = true;
           // break;
        }
        else
        {
            dsu_union(u, v);
        }
    }
    if(hasCycle)
    {
        cout << "Graph contains a cycle." << endl;
    }
    else
    {
        cout << "Graph does not contain a cycle." << endl;
    }
    return 0;
}