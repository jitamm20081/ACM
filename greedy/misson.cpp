#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100000+10;
int n;
struct Node
{
    int r,o;
}node[N];
bool cmp(Node x, Node y)
{
    if(x.r-x.o!=y.r-y.o)
        return x.r-x.o>y.r-y.o;
    return x.o>y.o;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&node[i].r,&node[i].o);
    int ans=0;
    sort(node,node+n,cmp);
    int last=0;
    for(int i=0;i<n;i++)
    {
        if(node[i].r>last)
        {
            ans+=node[i].r-last;//last：上一个释放出来的空间
            last=node[i].r;
        }
        else
        {
            ;
        }
       /*if(node[i].o>last)
        {
            ans+=node[i].o-last;
            last=0;
        }
        else*/
        
            last-=node[i].o;
        
    }
    cout<<ans<<endl;
    return 0;
}