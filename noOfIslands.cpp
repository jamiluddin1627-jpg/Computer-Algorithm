// LeetCode Problem: Number of Islands
#include <iostream>
#include <vector>
#include <cstring> // Required for memset

using namespace std;

class Solution {
public:
    int n, m;
    // Using 301x301 based on typical LeetCode constraint (grid max size 300x300)
    bool visited[301][301]; 
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        visited[i][j] = true;
        
        for(int d = 0; d < 4; d++)
        {
            int ni = i + directions[d].first;
            int nj = j + directions[d].second;
            
            if(isValid(ni, nj) && !visited[ni][nj] && grid[ni][nj] == '1')
            {
                dfs(grid, ni, nj);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Edge case check to prevent out-of-bounds error on empty grid
        if (grid.empty()) return 0; 
        
        n = grid.size();
        m = grid[0].size();
        
        memset(visited, false, sizeof(visited));
        
        int count = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    // --- Test Case 1 ---
    // One large connected island
    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    // --- Test Case 2 ---
    // Three separate islands
    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Execute and print results
    cout << "Test Case 1 (Expected output: 1) -> Actual output: " << sol.numIslands(grid1) << endl;
    cout << "Test Case 2 (Expected output: 3) -> Actual output: " << sol.numIslands(grid2) << endl;

    return 0;
}