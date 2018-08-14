#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
char Map[11][11];
int visit[11][11];
int n;
bool isok(int i,int j)
{
    int k,m;
    for(k=j;k>=0;k--)
    {
        if(visit[i][k]==-1)
            break;
        if(visit[i][k])
            return false;
    }
    for(m=i;m>=0;m--)
    {
        if(visit[m][j]==-1)
            break;
        if(visit[m][j])
            return false;
    }
    return true;
}
int DFS(int i,int j)
{
    int maxnum=0,num=0;
    while(i<n)
    {
        if(visit[i][j]==0&&isok(i,j)&&Map[i][j]!='X')
        {
            visit[i][j]=1;
            num=DFS(i,j+1)+1;
            if(num>maxnum) maxnum=num;
            visit[i][j]=0;
        }
        if(j>=n-1)
        {
            i++;
            j=0;
        }
        else
            j++;
    }
    return maxnum;
}
int main()
{
    while(cin>>n&&n)
    {
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
        {
            scanf("%s",Map[i]);
            for(int j=0;j<n;j++)
            {
                if(Map[i][j]=='X')
                    visit[i][j]=-1;
            }
        }
        cout<<DFS(0,0)<<endl;
    }
    return 0;
}
