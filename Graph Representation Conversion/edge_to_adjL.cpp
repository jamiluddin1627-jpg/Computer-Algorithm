#include <bits/stdc++.h>
using namespace std;
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
    for (int i = 0; i < n; i++)
    {
        cout<< i << "-> ";
        for(pair<int, int> child: v[i])
        {
            cout<< "{" << child.first << ", " << child.second << "} ";
        }
        cout<< endl;
    }
    return 0;
}