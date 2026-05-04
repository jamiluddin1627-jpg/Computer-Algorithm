#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool visited[N];
int distance[N];
vector<int> adj[N];
void bfs(int src)
{
    visited[src] = true;
    distance[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int child: adj[node])
        {
            if(!visited[child])
            {
                visited[child] = true;
                distance[child] = distance[node] + 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin>> n >> e;
    while(e--)
    {
        int a, b;
        cin>> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(distance, -1, sizeof(distance));
    int src, des, k;
    cin>> src >> des >> k;
    bfs(src);
    if(distance[des] != -1 && distance[des] <= k * 2)
    {
        cout<< "YES" << endl; 
    }
    else
    {
        cout<< "NO" << endl;
    }
    return 0;
}