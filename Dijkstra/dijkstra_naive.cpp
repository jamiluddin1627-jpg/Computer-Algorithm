// Dijkstra's Algorithm - Naive Implementation
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int, int>> adjL[N];
int dist[N];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dist[src] = 0;
    while(!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;
        for(pair<int, int> child: adjL[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(cost + childCost < dist[childNode])
            {
                dist[childNode] = cost + childCost;
                q.push({childNode, dist[childNode]});
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