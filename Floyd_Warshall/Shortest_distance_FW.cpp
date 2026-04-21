 #include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = LLONG_MAX;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));

    // initialize
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;

    // edges
    while(e--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w); // multiple edge handle
    }

    // Floyd Warshall
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int q;
    cin >> q;

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        if(dist[x][y] == INF)
            cout << -1 << endl;
        else
            cout << dist[x][y] << endl;
    }

    return 0;
}
