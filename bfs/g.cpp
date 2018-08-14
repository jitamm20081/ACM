#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second
char nm[810][810];
int n,m,s;
int mo[4][2] = {1,0,-1,0,0,1,0,-1};
ii G,M,Z[2];
queue<ii> q[2];
bool judge(ii t)    //判断是否被鬼抓到
{
    if(t.x<1 || t.x>n || t.y<1 || t.y>m)    return 0;
    int l1,l2;
    l1 = abs(t.x-Z[0].x)+abs(t.y-Z[0].y);
    l2 = abs(t.x-Z[1].x)+abs(t.y-Z[1].y);
    if(l1<=2*s || l2<=2*s || nm[t.x][t.y]=='X' || nm[t.x][t.y]=='\0')
        return 0;
    return 1;
}
bool bfs(int bj,int t,char h,char e)
{
    while(t--)
    {
        queue<ii> qt = q[bj];   //qt为临时队列，拷贝在该时刻所有q[bj]中的状态
        while(!qt.empty())
        {
            ii no = qt.front();
            qt.pop();q[bj].pop();
            if(!judge(no))  continue;
            int i;
            for(i=0;i<4;i++)
            {
                ii ne(no.x+mo[i][0],no.y+mo[i][1]);
                if(!judge(ne) || nm[ne.x][ne.y]==h) continue;
                if(nm[ne.x][ne.y] == e)   return 1;
                nm[ne.x][ne.y] = h;
                q[bj].push(ne);
            }
        }
    }
    return 0;
}
int solve()
{
    s = 0;
    // q[0]代表bfs M的队列，q[1]代表bfs G的队列
    while(!q[0].empty()) q[0].pop();
    while(!q[1].empty()) q[1].pop();
    q[0].push(M);
    q[1].push(G);
    while(!q[0].empty() && !q[1].empty())
    {
        s++;
        bool bj1 = bfs(0,3,'M','G');
        bool bj2 = bfs(1,1,'G','M');
        if(bj1 || bj2)  return s;
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(nm,'X',sizeof(nm));
        int i,j,k=0;
        for(i=1;i<=n;i++)
        {
            scanf("%s",nm[i]+1);
            for(j=1;j<=m;j++)
            {
                if(nm[i][j] == 'M') M.x=i,M.y=j;
                if(nm[i][j] == 'G') G.x=i,G.y=j;
                if(nm[i][j] == 'Z') Z[k].x=i,Z[k++].y=j;
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
