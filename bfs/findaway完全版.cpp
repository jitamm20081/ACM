#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=206;
const int INF=0x3f3f3f3f;
int dir[4][2]= {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
int dist1[maxn][maxn], dist2[maxn][maxn];
int vis[maxn][maxn];
char maps[maxn][maxn];
int n, m;
struct node
{
    int x, y, step;
};

void bfs(node start, int dist[][maxn])
{
    memset(vis, 0, sizeof(vis));
    queue<node>Q;
    node p, q;
    Q.push(start);
    vis[start.x][start.y]=1;
    dist[start.x][start.y]=0;
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();

        for(int i=0; i<4; i++)
        {
            q.x=p.x+dir[i][0];
            q.y=p.y+dir[i][1];
            if(!vis[q.x][q.y]&&q.x>=0&&q.x<n&&q.y>=0&&q.y<m&&maps[q.x][q.y]!='#')
            {
                vis[q.x][q.y]=1;
                dist[q.x][q.y]=dist[p.x][p.y]+1;
                Q.push(q);
            }
        }
    }
}
int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        node s1, s2;
        getchar();
        for(int i=0; i<n; i++,getchar())
        {
            for(int j=0; j<m; j++)
            {
                scanf("%c", &maps[i][j]);
                if(maps[i][j]=='Y')
                {
                    s1.x=i;
                    s1.y=j;
                    s1.step=0;
                }
                if(maps[i][j]=='M')
                {
                    s2.x=i;
                    s2.y=j;
                    s2.step=0;
                }
            }
        }
        memset(dist1, 0, sizeof(dist1));
        memset(dist2, 0, sizeof(dist2));
        bfs(s1, dist1);
        bfs(s2, dist2);
        int Min=INF;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maps[i][j]=='@'&&dist1[i][j]!=0&&dist2[i][j]!=0)
                    Min=min(Min, dist1[i][j]+dist2[i][j]);
            }
        }
        printf("%d\n", Min*11);
    }
    return 0;
}
