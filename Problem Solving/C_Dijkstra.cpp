#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll, ll>
using namespace std;

const int N = 1e5 + 10;
vector<pl> adj[N];
ll dista[N];
ll parent[N];
class cmp
{
public:
    bool operator()(pl a, pl b)
    {
        return a.second > b.second; // min-heap
    }
};

void dijkstra(ll src)
{
    priority_queue<pl, vector<pl>, cmp> pq;

    dista[src] = 0;
    pq.push({src, 0});

    while (!pq.empty())
    {
        pl node = pq.top();
        pq.pop();

        ll parentNode = node.first;
        ll parentCost = node.second;

        if (parentCost > dista[parentNode]) continue; // if the cost is greater than the already found shortest distance, skip

        for (pl child : adj[parentNode])
        {
            ll childNode = child.first;
            ll childCost = child.second;

            if (parentCost + childCost < dista[childNode])
            {
                dista[childNode] = parentCost + childCost;
                parent[childNode] = parentNode;
                pq.push({childNode, dista[childNode]});
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;

    while (e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // undirected
    }

    for (ll i = 1; i <= n; i++)
    {
        dista[i] = 1e18;
        parent[i] = -1;
    }

    dijkstra(1);
    vector<ll> path;
    ll x = n;
    if(dista[n] == 1e18)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        while(x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        for(ll node: path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
