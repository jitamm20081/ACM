#include<cstdio>
#include<iostream>
using namespace std; 

int n,k;
int ans;
int map[9][9],column[9];
char ch;

void dfs(int now,int k)
{
    if (now==n+1 || k==0)
    {
        if (k==0)
            ans++;
        return;
    }
    dfs(now+1,k);
    for(int i=1;i<=n;i++)
        if (map[now][i]==0 && !column[i])
        {
            column[i]=1;
            dfs(now+1,k-1);
            column[i]=0;
        }
    return; 
}

int main()
{
    while (scanf("%d%d\n",&n,&k)&&(n!=-1 && k!=-1))
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                scanf("%c",&ch);
                map[i][j]=(ch=='.');
            }
            scanf("\n");
        }
        ans=0;
        for (int i=1;i<=n;i++)
            column[i]=0; 
        dfs(1,k);
        printf("%d\n",ans);
    }
    return 0;
}
