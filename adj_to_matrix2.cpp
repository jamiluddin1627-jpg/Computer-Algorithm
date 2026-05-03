#include <bits/stdc++.h>
using namespace std;
void convertAdjToMatrix(int n, vector<pair<int, int>> adj[])
{
    int matrix[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = -1;
            if(i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(auto j: adj[i])
        {
            matrix[i][j.first] = j.second;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<< matrix[i][j] << " ";
        }
        cout<< endl;
    }
}
int main()
{
    int n, e;
    cin>> n >> e;
    vector<pair<int, int>> v[n];
    while(e--)
    {
        int a, b, w;
        cin>> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    convertAdjToMatrix(n, v);
    return 0;
}