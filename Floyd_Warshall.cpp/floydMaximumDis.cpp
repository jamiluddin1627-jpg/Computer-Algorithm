/* Given a directed weighted graph, find the pair of vertices such that the shortest distance from one to the other is maximal among all pairs of vertices.

Input
The first line contains the number of vertices n (1≤n≤100). The next n lines each contain n numbers and represent the weight matrix of the graph. A value of −1 means there is no edge between the corresponding vertices; any non-negative number represents the weight of an edge. All elements on the main diagonal are always zero.

Output
Print the required maximum shortest distance.


Examples
Input #1
4
0 5 9 -1
-1 0 2 8
-1 -1 0 7
4 -1 -1 0 */
#include<bits/stdc++.h>
#define ll long long int
#define INF (ll)1e15
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll adj[n][n];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>adj[i][j];
            if(adj[i][j] == -1)
                adj[i][j] = INF;
        }
    }

    return 0;
}