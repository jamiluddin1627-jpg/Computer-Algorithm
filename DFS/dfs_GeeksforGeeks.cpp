#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> v;
    vector<bool> vis;
    
    void dfsHelper(int node, vector<vector<int>>& adj)
    {
        vis[node] = true;
        v.push_back(node);
        for(int i: adj[node])
        {
            if(!vis[i])
            {
                dfsHelper(i, adj);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vis.assign(n, false);
        v.clear();
        dfsHelper(0, adj);
        return v;
    }
};

// Helper function to print the result vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // --- Test Case 1 ---
    // Graph structure: 
    // 0 is connected to 1 and 2
    // 1 is connected to 0 and 3
    // 2 is connected to 0 and 4
    // 3 is connected to 1
    // 4 is connected to 2
    vector<vector<int>> adj1 = {
        {1, 2},    // Neighbors of node 0
        {0, 3},    // Neighbors of node 1
        {0, 4},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {2}        // Neighbors of node 4
};

    cout << "Test Case 1 DFS Traversal: ";
    vector<int> result1 = sol.dfs(adj1);
    printVector(result1); // Expected output: 0 1 3 2 4


    // --- Test Case 2 ---
    // A linear graph: 0 -> 1 -> 2 -> 3
    vector<vector<int>> adj2 = {
        {1},       // Neighbors of node 0
        {2},       // Neighbors of node 1
        {3},       // Neighbors of node 2
        {}         // Neighbors of node 3
    };

    cout << "Test Case 2 DFS Traversal: ";
    vector<int> result2 = sol.dfs(adj2);
    printVector(result2); // Expected output: 0 1 2 3

    return 0;
}