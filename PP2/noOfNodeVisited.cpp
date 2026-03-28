//You will be given a directed graph as an input. Then you will be given a Node N. You need to tell the number of nodes that are visited from the node N. You can use either DFS or BFS to solve this problem.
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<bool> vis;
int countNode[] = {0};

void dfs(int node)
{
    vis[node] = true;
    countNode[0]++;
    for(int child: a[node])
    {
        if(!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    a.resize(n);
    vis.resize(n, false);

    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int src;
    cin >> src;

    dfs(src);

    cout << countNode[0] << endl;

    return 0;
}

