#include <bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second> b.second;
    }
};
int main() {
    int n, s, f;
    cin>> n >> s>> f;
    s--; f--;
    vector<vector<int>> mat(n, vector<int>(n));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<pair<int, int>> adj[n];
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(mat[i][j]>0) // if(mat[i][j] != -1 && i != j)
            {
                adj[i].push_back({j, mat[i][j]});
            }
        }
    }
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({s, 0});
    while(!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        if(cost > dist[node]) continue; // Skip if we have already found a better path
        for(auto child: adj[node])
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
    if(dist[f] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[f] << endl;
}
