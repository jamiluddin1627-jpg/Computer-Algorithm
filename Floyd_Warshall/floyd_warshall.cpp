// Floyd Warshall Algorithm in C++
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, e;
    cin>>n>>e;
    ll adj[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INT_MAX;
            }
        }
    }
    while(e--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j] && adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj[i][j] == INT_MAX)
            {
                cout<<"INF ";
            }
            else
            {
                cout<<adj[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++)
    {
        if(adj[i][i] < 0)
        {
            cout<<"Negative Cycle Detected"<<endl;
            break;
        }
        else
        {
            cout<<"No Negative Cycle Detected"<<endl;
            break;
        }
     }
    return 0;
}