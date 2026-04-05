// Dijkstra's Algorithm - Optimized Implementation
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int, int>> adjL[N];
int dist[N];
class cmp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // Min-heap based on distance
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dist[src] = 0;
    while(!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for(pair<int, int> child: adjL[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dist[childNode])
            {
                //Path relaxation
                dist[childNode] = cost + childCost;
                pq.push({childNode, dist[childNode]});
            }
        }
    }   
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
        adjL[v].push_back({u, w});
    }
    memset(dist, 0x3f, sizeof(dist)); // Initialize distances to infinity
    dijkstra(0);
    for(int i = 0; i < n; i++)
    {
        cout << "Distance from source to node " << i << " is: " << dist[i] << endl;
    }
    return 0;
}