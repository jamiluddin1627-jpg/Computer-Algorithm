#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int N = 2e5 + 10;
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
    if(parent[u] == u) return u;
    return parent[u] = find_parent(parent[u]);
}

void dsu_union(int u, int v)
{
    int leaderA = find_parent(u);
    int leaderB = find_parent(v);

    if(leaderA != leaderB)
    {
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
}

bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    dsu_init(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), cmp);

    long long mst_weight = 0;
    int cnt = 0;

    for(Edge &edge : edges)
    {
        if(find_parent(edge.u) != find_parent(edge.v))
        {
            dsu_union(edge.u, edge.v);
            mst_weight += edge.w;
            cnt++;
        }
    }

    if(cnt == n-1)
    {
        cout << mst_weight << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
