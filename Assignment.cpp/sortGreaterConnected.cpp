#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;
vector<int> v;

int main()
{
    int n, e;
    cin>>n>>e;
    a.resize(n);
    while(e--)
    {
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin>>x;
        if(a[x].empty())
        {
            cout<<"-1"<<endl;
        }
        else
        {
            sort(a[x].begin(), a[x].end(), greater<int>());
            for(int i: a[x])
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
