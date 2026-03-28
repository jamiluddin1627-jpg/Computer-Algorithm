#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int n, m;
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor)
    {
        image[i][j] = newColor;
        
        for(int d = 0; d < 4; d++)
        {
            int ni = i + directions[d].first;
            int nj = j + directions[d].second;
            
            if(isValid(ni, nj) && image[ni][nj] == oldColor)
            {
                dfs(image, ni, nj, oldColor, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        n = image.size();
        m = image[0].size();
        
        int oldColor = image[sr][sc];
        
        if(oldColor == color) return image;
        
        dfs(image, sr, sc, oldColor, color);
        
        return image;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> image(n, vector<int>(m));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> image[i][j];
        }
    }
    
    int sr, sc, color;
    cin >> sr >> sc >> color;
    
    Solution obj;
    vector<vector<int>> result = obj.floodFill(image, sr, sc, color);
    
    // print output
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
