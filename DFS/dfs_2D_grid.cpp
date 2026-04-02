#include<bits/stdc++.h>
using namespace std;
int a[100][100];
bool visited[100][100];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right, Left, Up, Down
int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m); // Check if the cell is within the grid boundaries
}
void dfs(int si, int sj)
{
    visited[si][sj] = true; // Mark the current cell as visited
    cout <<si << " " << sj << endl; // Process the current cell (e.g., print its value)
    for(int i = 0; i < 4; i++) // Explore all four directions
    {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if(isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    memset(visited, false, sizeof(visited)); // Initialize visited array to false
    dfs(si, sj);
    return 0;
}