#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> adjL[N];

class cmp{
public:
    bool operator()(pair<int,ll> a, pair<int,ll> b)
    {
        return a.second > b.second;
    }
};

vector<ll> dijkstra(int src, int n)
{
    vector<ll> dist(n+1, LLONG_MAX);

    priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> pq;

    dist[src] = 0;
    pq.push({src, 0});

    while(!pq.empty())
    {
        auto [node, cost] = pq.top();
        pq.pop();

        if(cost > dist[node]) continue;

        for(auto [childNode, childCost] : adjL[node])
        {
            if(cost + childCost < dist[childNode])
            {
                dist[childNode] = cost + childCost;
                pq.push({childNode, dist[childNode]});
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjL[u].push_back({v, w});
    }

    int q;
    cin >> q;

    map<int, vector<ll>> mp;  
    while(q--)
    {
        int x, y;
        cin >> x >> y;

        if(mp.find(x) == mp.end())
        {
            mp[x] = dijkstra(x, n);  
        }

        if(mp[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << mp[x][y] << endl;
    }

    return 0;
}
