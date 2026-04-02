#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> a[n];
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u); // For undirected graph
    }
    //a[0] contains all the adjacent vertices of vertex 0
    for(int i = 0; i <(int) a[0].size(); i++)
    {
        cout<<a[0][i] << " ";
    }
    return 0;
}