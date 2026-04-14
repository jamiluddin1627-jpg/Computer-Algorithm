//0 10 11 30000 ; if there is no path print 30000
#include<bits/stdc++.h>
#define ll long long int
#define INF (long long int)1e15
using namespace std;
class Edge
{
    public:
    int u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
const int N = 1e5 + 5;
ll dist[N];
int main()
{
    int n, e;
    cin>>n>>e;
    vector<Edge> edges;
    while(e--)
    {
        ll u, v, w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u, v, w)); // directed graph
        // edges.push_back(Edge(v, u, w)); // undirected graph
    }
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[1] = 0;
    for(int i = 1; i <= n - 1; i++)
    {
        for(Edge edge: edges)
        {
            if(dist[edge.u] + edge.w < dist[edge.v] && dist[edge.u] != INF)
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == INF)
        {
            cout<<30000<<" ";
        }
        else
        {
            cout<<dist[i]<<" ";
        }
    }
    return 0;
}