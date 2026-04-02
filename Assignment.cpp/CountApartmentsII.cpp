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
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; // Right, Left, Up, Down
bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && !visited[x][y]);
}

int bfs(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    int roomCount = 1; // Count the starting cell as a room
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
                roomCount++; // Increment room count for each valid adjacent cell
            }
        }
    }
    return roomCount;
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
    vector<int> apartmentSizes;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 0 && !visited[i][j])
            {
                int size = bfs({i, j});
                apartmentSizes.push_back(size);
            }
        }
    }
    sort(apartmentSizes.begin(), apartmentSizes.end());
    if(apartmentSizes.empty())
    {
        cout << 0;
    }
    else
    {
        for(int size : apartmentSizes)
        {
            cout << size << " ";
        }
    }
    return 0;
}