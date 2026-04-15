#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<pair<int, int>> adjL[N];
long long dist[N];

class cmp{
public:
    bool operator()(pair<int, long long> a, pair<int, long long> b){
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq;

    pq.push({src, 0});
    dist[src] = 0;

    while(!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();

        int node = parent.first;
        long long cost = parent.second;

        if(cost > dist[node]) continue;

        for(auto child: adjL[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(cost + childCost < dist[childNode])
            {
                dist[childNode] = cost + childCost;
                pq.push({childNode, dist[childNode]});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjL[u].push_back({v, w});
    }

    int src;
    cin >> src;

    fill(dist, dist + N, 1e18);

    dijkstra(src);

    int t;
    cin >> t;

    while(t--)
    {
        int d;
        long long dw;
        cin >> d >> dw;

        if(dist[d] <= dw)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
