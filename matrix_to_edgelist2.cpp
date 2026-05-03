#include <bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
int main()
{
    int n;
    cin>> n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>> mat[i][j];
        }
    }
    vector<Edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(mat[i][j] != 0 && mat[i][j] != -1 && i != j)
            {
                edgelist.push_back(Edge(i, j, mat[i][j]));
            }
        }
    }
    for (auto edge : edgelist)
    {
        cout<< edge.a << " " << edge.b << " " << edge.w << endl;
    }
    return 0;
}