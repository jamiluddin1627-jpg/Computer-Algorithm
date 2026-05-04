#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
bool vis[N];
vector<int> adj[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adj[par])
        {
            if(!vis[child])
            {
                vis[child] = true;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp; // representative nodes

    for(int i = 1; i <= n; i++) // assuming nodes are numbered from 1 to n
    {
        if(!vis[i])
        {
            bfs(i);
            comp.push_back(i); // store one node from each component
        }
    }

    cout << comp.size() - 1 << endl;

    for(int i = 1; i < (int)comp.size(); i++)
    {
        cout << comp[i-1] << " " << comp[i] << endl;
    }

    return 0;
}
