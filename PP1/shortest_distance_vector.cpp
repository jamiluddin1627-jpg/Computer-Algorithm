#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a; // adjacency list of the graph, vector of vectors to store the graph
vector<bool> vis;
vector<int> level;
vector<int> parent;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : a[par])
        {
            if(!vis[child])
            {
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    a.resize(n); // resize the adjacency list to accommodate n vertices

    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int q;
    cin >> q;

    while(q--)
    {
        int src, des;
        cin >> src >> des;

        // reset using vector
        vis.assign(n, false);
        level.assign(n, -1);
        parent.assign(n, -1);

        bfs(src);

        cout << level[des] << endl;
    }

    return 0;
}
