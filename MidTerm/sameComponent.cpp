#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int maze[N][N];
bool visited[N][N];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m && maze[i][j] == 0 && !visited[i][j]);
}
void bfs(pair<int, int> src)
{
    visited[src.first][src.second] = true;
    queue<pair<int, int>> q;
    q.push(src);
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        for(int i = 0; i<4; i++)
        {
            int ci = node.first + directions[i].first;
            int cj = node.second + directions[i].second;
            if(isValid(ci, cj))
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    cin>> n >> m;
    for(int i = 0; i<n; i++)
    {
        string st;
        cin>>st;
        for(int j = 0; j<m; j++)
        {
            if(st[j] == '-') maze[i][j] = -1;
            else maze[i][j] = 0;
        }
    }
    pair<int, int> src, dest;
    cin >> src.first >> src.second >> dest.first >> dest.second;
    memset(visited, false, sizeof(visited));
    bfs(src);
    if(visited[dest.first][dest.second])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}