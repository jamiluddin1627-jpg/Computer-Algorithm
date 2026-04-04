#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adjL[N];
bool visited[N];
bool cycle;
bool pathVisited[N];
void dfs(int src)
{
    visited[src] = true;
    pathVisited[src] = true;
    for(int child : adjL[src])
    {
        if(!visited[child])
        {
            dfs(child);
        }
        else if(pathVisited[child]) // if the child is already visited and is in the current path, then there is a cycle
        {
            cycle = true;
            return;
        }
    }
    pathVisited[src] = false; // backtrack
}
 
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v); // directed graph
    }
    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));
    cycle = false;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            if(cycle)
            {
                cout << "Cycle Detected\n";
                return 0;
            }
        }
    }
    cout << "No Cycle Detected\n";

    return 0;
}