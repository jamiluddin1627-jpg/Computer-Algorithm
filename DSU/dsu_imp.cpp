#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int group_size[N];
int level[N]; //optional, can be used to store the level or rank of each set for union by rank optimization
void dsu_set(int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
        level[i] = 0; //initialize the level/rank of each set to 0
    }
}
int find_set(int u)
{
    if(parent[u] == -1)
    {
        return u; //u is the representative of its set
    }
    return parent[u] = find_set(parent[u]); //path compression optimization
}
void union_set(int a, int b)
{
    int leaderA = find_set(a); //find the representative of the set to which a belongs
    int leaderB = find_set(b); //find the representative of the set to which b belongs
    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA; //make leaderA the parent of leaderB
        group_size[leaderA] += group_size[leaderB]; //update the size of the set represented by leaderA
    }
    else
    {
        parent[leaderA] = leaderB; //make leaderB the parent of leaderA
        group_size[leaderB] += group_size[leaderA]; //update the size of the set represented by leaderB
    }
}
void union_set_by_rank(int a, int b)
{
    int leaderA = find_set(a); //find the representative of the set to which a belongs
    int leaderB = find_set(b); //find the representative of the set to which b belongs
    if(level[leaderA] > level[leaderB])
    {
        parent[leaderB] = leaderA; //make leaderA the parent of leaderB
        group_size[leaderA] += group_size[leaderB]; //update the size of the set represented by leaderA
    }
    else if(level[leaderA] < level[leaderB])
    {
        parent[leaderA] = leaderB; //make leaderB the parent of leaderA
        group_size[leaderB] += group_size[leaderA]; //update the size of the set represented by leaderB
    }
    else
    {
        parent[leaderA] = leaderB; //make leaderB the parent of leaderA
        group_size[leaderB] += group_size[leaderA]; //update the size of the set represented by leaderB
        level[leaderB]++; //increment the level/rank of the new representative (leaderB) since both sets had the same level/rank
    }
}
int main()
{
    dsu_set(7); //initialize DSU for 7 elements (0 to 6)
    // union_set(1, 2); //union the sets containing 1 and 2
    // union_set(2, 3); //union the sets containing 2 and 3
    // union_set(4, 5); //union the sets containing 4 and 5
    // union_set(5, 6); //union the sets containing 5 and 6
    // cout << "Representative of set containing 1: " << find_set(1) << endl; //should print the representative of the set containing 1
    // cout << "Representative of set containing 4: " << find_set(4) << endl; //should print the representative of the set containing 4
    // cout << "Representative of set containing 0: " << find_set(0) << endl; //should print the representative of the set containing 0 (which is itself)
    // cout << "Representative of set containing 3: " << find_set(3) << endl; //should print the representative of the set containing 3 (which should be the same as that of 1 and 2)
    // union_set(3, 4); //union the sets containing 3 and 4 (which will also union the sets containing 1, 2, 5, and 6)
    // cout << "Representative of set containing 3 after union with 4: " << find_set(3) << endl;
    union_set_by_rank(1, 2); //union the sets containing 1 and 2 using union by rank
    union_set_by_rank(2, 3); //union the sets containing 2 and 3 using union by rank
    union_set_by_rank(4, 5); //union the sets containing 4 and 5 using union by rank
    union_set_by_rank(5, 6); //union the sets containing 5 and 6 using union by rank
    cout << "Representative of set containing 1: " << find_set(1) << endl; //should print the representative of the set containing 1
    cout << "Representative of set containing 4: " << find_set(4) << endl; //should print the representative of the set containing 4
    cout << "Representative of set containing 0: " << find_set(0) << endl; //should print the representative of the set containing 0 (which is itself)
    cout << "Representative of set containing 3: " << find_set(3) << endl; //should print the representative of the set containing 3 (which should be the same as that of 1 and 2)
    union_set_by_rank(3, 4); //union the sets containing 3 and 4 (which will also union the sets containing 1, 2, 5, and 6) using union by rank
    cout << "Representative of set containing 3 after union with 4: " << find_set(3) << endl;
    return 0;
}