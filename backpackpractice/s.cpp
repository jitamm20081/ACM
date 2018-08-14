#include<stdio.h>
#include<string.h>
int c[105];
int w[105];
int n,m;
int f[100000];


int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(f,0,sizeof(f));
        if(n==0&&m==0)
        break;
        for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
        f[0]=1;
        for(int i=0;i<n;i++)
        {
            int amount=c[i];
            for(int k=1;k<=amount;k<<=1)//二进制的思想
            {
                for(int j=m;j>=k*w[i];j--)
                {
                    f[j]+=f[j-k*w[i]];
                    printf("%d %d %d\n",j,j-k*w[i],f[j]);
                }
            amount-=k;
            }
            if(amount)
            {
                for(int j=m;j>=amount*w[i];j--)
                f[j]+=f[j-amount*w[i]];
            }
        }

        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            printf("***%d***\n",f[i]);
            if(f[i])
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
