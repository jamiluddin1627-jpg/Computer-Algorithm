#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v; // pair<int, int> a[n]; // This is also correct but we will use vector of pairs. this vector will store all the edges of the graph. each edge is represented as a pair of vertices (a, b) where a and b are the vertices connected by the edge.
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    for(auto edge : v)
    {
        cout << edge.first << " " << edge.second << endl; // we have to use edge.first and edge.second because edge is a pair
    }
    // for(int i = 0; i < (int) v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    return 0;
}