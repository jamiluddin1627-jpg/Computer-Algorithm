//Count of connected nodes in a graph
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
 
int main()
{
    int n, e;
    cin >> n >> e;
    a.resize(n);
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int node;
    cin>>node;
    int cnt = 0;
    for(int i: a[node])
    {
         cnt++;
    }
    cout<<cnt;
    return 0;
}