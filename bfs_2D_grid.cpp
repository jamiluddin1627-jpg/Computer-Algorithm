#include<bits/stdc++.h>
using namespace std;
char a[100][100];
bool vis[100] [100];
int dis[100] [100]; //distance or level of each cell from the source cell
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right, Left, Up, Down
int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j]); // Check if the cell is within the grid boundaries
}
void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  q.push({si, sj});
  vis[si][sj] = true;
  dis[si][sj] = 0;
  cout<<"Processing cell: "<<endl;
  while(!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    cout<<par.first<<" "<<par.second<<endl;
    for(int i = 0; i < 4; i++)
    {
        int ci = par.first + directions[i].first;
        int cj = par.second + directions[i].second;
        if(isValid(ci, cj))
        {
            q.push({ci, cj});
            vis[ci][cj] = true;
            dis[ci][cj] = dis[par.first][par.second] + 1;
        }
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
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    
    cout<<"Distances from the source cell:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}