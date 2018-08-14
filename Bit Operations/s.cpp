#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    long long temp;
    scanf("%d",&n);
   /* if(n%2==0)
    {
        long long begins=0;
        while(scanf("%lld",&temp)!=EOF)
        {
            begins^=temp;
        }
        cout<<begins<<endl;
    }
    else
    {
        /*int len=0;
        long long a[1012];
        long long temp=0;
        bool flag=true;
        while(scanf("%lld",&a[len])!=EOF)
        {
            temp^=a[len];
            len++;
            if(len==n)
            {
                if(!flag){
                    len=0;
                    continue;
                }
                if(a[0]!=a[1])
                {
                    cout<<temp<<endl;
                    len=0;
                    flag=false;
                }
                else
                {
                    if(temp==a[0])
                    {
                        len=0;
                        temp=0;
                    }
                    else
                    {
                        cout<<temp<<endl;
                        len=0;
                        flag=false;
                    }
                }
            }
        }
        if(flag)
            cout<<a[len-1]<<endl;*/
        long long result=0;
        long long digit[65];
        memset(digit,0,sizeof(digit));
        while(scanf("%lld",&temp)!=EOF)
        {
            for(int i=0;i<64;i++)
                digit[i]+=(temp>>i)&1;
        }
        for(int i=0;i<64;i++)
        {
            result |=(digit[i]%n) << i;
        }
        cout<<result<<endl;
    
    return 0;
}