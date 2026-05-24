#include<bits/stdc++.h>
using namespace std;
int n;
int maze[100][100];
bool visited[100][100];
int level[100][100];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool isValid(int x,int y)
{
    return (x>=0 && x<n &&
            y>=0 && y<n &&
            maze[x][y]!=-1 &&
            !visited[x][y]);
}

void bfs(pair<int,int> src)
{
    queue<pair<int,int> > q;

    q.push(src);
    visited[src.first][src.second]=true;

    while(!q.empty())
    {
        pair<int, int> cell=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            int newX=cell.first+dx[i];
            int newY=cell.second+dy[i];

            if(isValid(newX,newY))
            {
                visited[newX][newY]=true;
                level[newX][newY]=level[cell.first][cell.second]+1;
                q.push({newX,newY});
            }
        }
    }
}

int main()
{
    while(cin>>n)
    {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            maze[i][j]=0;
            visited[i][j]=false;
            level[i][j]=0;
        }
    }

    pair<int,int> src,dest;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            string s;
            cin>>s;

            if(s[0]=='T')
                maze[i][j]=-1;
            else
                maze[i][j]=0;

            if(s[0]=='S')
                src={i,j};

            if(s[0]=='E')
                dest={i,j};
        }
    }
    memset(visited, false, sizeof(visited));
    memset(level, 0, sizeof(level));
    bfs(src);

    cout<<level[dest.first][dest.second]<<endl;
    }
    return 0;
}