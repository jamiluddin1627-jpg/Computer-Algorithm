#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
const int N = 1e5 + 10;
int parent[N];
int groupSize[N];
void dsu_init(int n)
{
    for(int i = 0; i < n; i++)
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
bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    vector<Edge> edges;
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end(), cmp);
    int mst_weight = 0;
    for(Edge &edge: edges)
    {
        if(find_parent(edge.u) != find_parent(edge.v))
        {
            dsu_union(edge.u, edge.v);
            mst_weight += edge.w;
        }
    }
    cout << mst_weight << endl;
    return 0;
}