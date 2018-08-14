#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[1000001];
int tree[1000001*4];
//创建一棵线段树，l为区间左端点，r为区间右端点，rt为根节点位置
int build(int l,int r,int rt)
{
    //叶子节点，直接保存数组的值就好
    if(l==r)
    {
        tree[rt]=a[l];
        return 0;
    }
    //创建左子树
    build(l,(l+r)/2,2*rt);
    //创建右子树
    build((l+r)/2+1,r,2*rt+1);
    //状态合并，求得左右子区间的最大值。
    tree[rt]=max(tree[2*rt],tree[2*rt+1]);
}
//这是一个区间的查询函数,l表示递归的左区间端点，r表示递归的右区间端点，L，R分别是要查询的左右区间端点
int query(int l,int r,int rt,int L,int R)
{
    //要查询的区间已经在递归区间了：直接返回改递归区间的最大值就好。
    if(l>=L && r<=R)
        return tree[rt];
    int ret=-1;
    //查询左区间；
    if((l+r)/2>=L)
        ret=max(ret,query(l,(l+r)/2,2*rt,L,R));
    //查询右区间：
    if((l+r)/2+1<=R)
        ret=max(ret,query((l+r)/2+1,r,2*rt+1,L,R));
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",query(1,n,1,l,r));
    }
    return 0;
}
