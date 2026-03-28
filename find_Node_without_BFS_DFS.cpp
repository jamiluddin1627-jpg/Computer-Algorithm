#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

int main()
{
    int n, e;
    cin>>n>>e;
    a.resize(n);
    while(e--)
    {
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);//directed
    }
    int q;
    cin >> q;
    while(q--)
    {
        int s, d;
        cin>> s >> d;
        if (s == d) 
        {
            cout << "YES\n";
            continue;
        }
        if (find(a[s].begin(), a[s].end(), d) != a[s].end()) 
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }
    return 0;
}
