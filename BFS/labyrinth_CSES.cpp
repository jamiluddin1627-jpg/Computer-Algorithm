#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];
bool visited[N][N];

pair<int,int> parent[N][N];
char pathDir[N][N];

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'U', 'D'};

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1 && !visited[x][y]);
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while(!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int newX = cell.first + dx[i];
            int newY = cell.second + dy[i];

            if(isValid(newX, newY))
            {
                visited[newX][newY] = true;

                parent[newX][newY] = cell;     // add
                pathDir[newX][newY] = dir[i];  // add

                q.push({newX, newY});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int, int> src, dest;

    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
        {
            if(row[j] == '#') maze[i][j] = -1;
            else maze[i][j] = 0;

            if(row[j] == 'A') src = {i, j};
            if(row[j] == 'B') dest = {i, j};
        }
    }

    memset(visited, false, sizeof(visited));

    bfs(src);

    if(!visited[dest.first][dest.second])
    {
        cout << "NO\n";
        return 0;
    }

    // path build (new add)
    string path;
    pair<int,int> cur = dest;

    while(cur != src)
    {
        path += pathDir[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}
