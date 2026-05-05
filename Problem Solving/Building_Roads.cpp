#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int parent[N];
int group_size[N];

void dsu_set(int n)
{
    for(int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int find_set(int u)
{
    if(parent[u] == -1)
        return u;

    return parent[u] = find_set(parent[u]);
}

void union_set(int a, int b)
{
    int leaderA = find_set(a);
    int leaderB = find_set(b);

    if(leaderA == leaderB) return;

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_set(n);  
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        union_set(a, b);
    }

    vector<int> leaders;

    for(int i = 1; i <= n; i++)
    {
        if(parent[i] == -1)
        {
            leaders.push_back(i);
        }
    }
    sort(leaders.begin(), leaders.end());
    leaders.erase(unique(leaders.begin(), leaders.end()), leaders.end());
    cout << leaders.size() - 1 << endl;
    for(int i = 0; i < (int)leaders.size() - 1; i++)
    {
        cout << leaders[i] << " " << leaders[i + 1] << endl;
    }

    return 0;
}
