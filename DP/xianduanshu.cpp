#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int Max[4000020];
int a[1000100];
int n;
void create(int rt,int l,int r){
	if(l==r){
		Max[rt]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	create(rt<<1,l,mid);
	create(rt<<1|1,mid+1,r);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}

int inquerymax(int rt,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return Max[rt];
	}	
	int mid=(l+r)>>1;
	if(R<=mid){
		return inquerymax(rt<<1,l,mid,L,R);
	}
	else if(L>mid){
		return inquerymax(rt<<1|1,mid+1,r,L,R);
	}
	else {
		return max(inquerymax(rt<<1,l,mid,L,mid),inquerymax(rt<<1|1,mid+1,r,mid+1,R));
	}
}

int main(){
	int test;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	create(1,1,n);
	scanf("%d",&test);
	int ll,rr,max1;
	while(test--){
		scanf("%d%d",&ll,&rr);
		max1=inquerymax(1,1,n,ll,rr);
		printf("%d\n",max1);
	}
}