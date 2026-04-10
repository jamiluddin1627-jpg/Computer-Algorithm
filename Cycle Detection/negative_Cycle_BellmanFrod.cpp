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
const int N = 1e5 + 5;
int dist[N];
int main()
{
    int n, e;
    cin>>n>>e;
    vector<Edge> edges;
    while(e--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u, v, w));
    }
    for(int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(Edge edge: edges)
        {
            if(dist[edge.u] + edge.w < dist[edge.v] && dist[edge.u] != INT_MAX)
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }
    bool hasNegativeCycle = false;
    for(Edge edge: edges)
    {
        if(dist[edge.u] + edge.w < dist[edge.v] && dist[edge.u] != INT_MAX)
        {
            hasNegativeCycle = true;
            break;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    if(hasNegativeCycle)
    {
        cout<<"Negative Cycle Detected"<<endl;
    }
    else
    {
        cout<<"No Negative Cycle Detected"<<endl;
    }
    return 0;
}