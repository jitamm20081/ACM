#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
 
using namespace std;

struct node
{
    int x,y,z;
    int step;
} now,nex;

int dx[]= {0,0,1,-1};
int dy[]= {-1,1,0,0};
char s[2][15][15];
int vis[2][15][15];
int n,m,T,ex,ey,ez;
int bfs()
{
    queue<node>q;
    while(!q.empty())q.pop();
    memset(vis,0,sizeof(vis));
    now.x=now.y=now.z=now.step=0;
    q.push(now);
    vis[0][0][0]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];
            int nz=now.z;
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nz][nx][ny]==0&&s[nz][nx][ny]!='*')
            {
                vis[nz][nx][ny]=1;
                if(s[nz][nx][ny]=='.')
                {
                    nex.x=nx;
                    nex.y=ny;
                    nex.z=nz;
                    nex.step=now.step+1;
                    q.push(nex);
                }
                ///太坑了也，如果两个面都是#就不传送
                else if(s[nz][nx][ny]=='#')
                {
                    if(s[nz^1][nx][ny]=='.'&&vis[nz^1][nx][ny]==0)
                    {
                        vis[nz^1][nx][ny]=1;
                        nex.x=nx;
                        nex.y=ny;
                        nex.z=nz^1;
                        nex.step=now.step+1;
                        q.push(nex);
                    }
                    else if(s[nz^1][nx][ny]=='P')
                    {
                        return now.step+1;
                    }
                }
                else if(s[nz][nx][ny]=='P')
                {
                    return now.step+1;
                }
            }
        }
    }
    return 0x3f3f3f3f;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&T);
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[0][i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%s",s[1][i]);
        }
        int k=bfs();
        cout<<k<<endl;
        if(k>T)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
