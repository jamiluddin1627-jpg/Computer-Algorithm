/* Output Format

Output the number of rooms in each of the apartments in ascending order.
Sample Input

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output

2 2 8 */

#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int grid[N][N];
bool visited[N][N];
int level[N][N];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right, Left, Up, Down
bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && !visited[x][y]);
}

void bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 1; // Start level from 1 for counting rooms
    while(!q.empty())
    {
        pair<int, int> cell = q.front();
        q.pop();
        for(auto dir : directions)
        {
            int newX = cell.first + dir.first;
            int newY = cell.second + dir.second;
            if(isValid(newX, newY))
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
                level[newX][newY] = level[cell.first][cell.second] + 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
        {
            if(row[j] == '#') grid[i][j] = -1; // Mark walls
            else grid[i][j] = 0; // Mark open spaces
        }
    }
    memset(visited, false, sizeof(visited));
    memset(level, 0, sizeof(level));
    vector<int> apartmentSizes;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 0 && !visited[i][j])
            {
                bfs({i, j});
                int roomCount = 0;
                for(int x = 0; x < n; x++)
                {
                    for(int y = 0; y < m; y++)
                    {
                        if(level[x][y] > 0) roomCount++;
                    }
                }
                apartmentSizes.push_back(roomCount);
            }
        }
    }
    sort(apartmentSizes.begin(), apartmentSizes.end());
    for(int size : apartmentSizes)
    {
        cout << size << " ";
    }
    return 0;
}