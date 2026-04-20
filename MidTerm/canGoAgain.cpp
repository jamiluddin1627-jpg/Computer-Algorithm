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
long long dist[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edges;

    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    for(int i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
    }

    int s;
    cin >> s;
    dist[s] = 0;

    // Relax n-1 times
    for(int i = 1; i <= n - 1; i++)
    {
        for(auto edge : edges)
        {
            if(dist[edge.u] != LLONG_MAX &&
               dist[edge.u] + edge.w < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Check Negative Cycle
    bool hasNegativeCycle = false;
    for(auto edge : edges)
    {
        if(dist[edge.u] != LLONG_MAX &&
           dist[edge.u] + edge.w < dist[edge.v])
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if(hasNegativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;

    while(t--)
    {
        int d;
        cin >> d;

        if(dist[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}
