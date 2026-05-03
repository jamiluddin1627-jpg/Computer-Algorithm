#include <bits/stdc++.h>
using namespace std;
void convertAdjToMatrix(int n, vector<int> adj[])
{
    int matrix[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j: adj[i])
        {
            matrix[i][j] = 1;
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
    vector<int> v[n];
    while(e--)
    {
        int a, b;
        cin>> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    convertAdjToMatrix(n, v);
    return 0;
}