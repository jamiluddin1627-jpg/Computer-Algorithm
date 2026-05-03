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
    int n, e;
    cin>> n >> e;
    vector<pair<int, int>> v[n];
    while(e--)
    {
        int a, b, w;
        cin>> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    vector<Edge> edgelist;
    for (int i = 0; i < n; i++)
    {
        for(pair<int, int> child: v[i])
        {
            edgelist.push_back(Edge(i, child.first, child.second));
        }
    }
    for (auto edge : edgelist)
    {
        cout<< edge.a << " " << edge.b << " " << edge.w << endl;
    }
    return 0;
}