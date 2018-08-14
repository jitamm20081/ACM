#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int j;
bool vis=false;
void dfs(unsigned __int64 m,int n,int k){
	if(vis)
		return ;
	if(k==19){
		return ;
	}
	if(m%n==0)
	{
		printf("%I64u\n",m);
		vis=true;
		return;
	}
	dfs(m*10,n,k+1);
	dfs(m*10+1,n,k+1);
}

int main(int argc, char const *argv[])
{
	while(cin>>j&&j!=0){
		vis=false;
		dfs(1,j,0);	
	}
	return 0;
}
