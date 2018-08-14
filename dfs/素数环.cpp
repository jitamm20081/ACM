#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int q=0;
int flag=0;
int a[30];
int visited[30];
bool  judge(int q){
	int i;
	for(i=2;i<=sqrt(q);i++){
		if(q%i==0)
			return false;
	}
	return true;
}

void dfs(int str){
	if(str>n||q==1)
		return ;
	
	if(str==n){
		if(judge(a[n]+1))
		{
			flag=1;
			for(int j=1;j<=n;j++)
				cout<<a[j]<<" ";
			printf("\n");
			q=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(visited[i]==0&&judge(a[str]+i)){
			a[str+1]=i;
			visited[i]=1;
			dfs(str+1);
			visited[i]=0;
		}
	}
}
	



int main(){

	while(cin>>n){
		memset(visited,0,sizeof(visited));
		memset(a,0,sizeof(a));
		a[1]=1;
		visited[1]=1;
		flag=0;
		q=0;
		if(n==1)
		{
			cout<<"1"<<endl;
			continue;

		}
		if(n%2==0)
			dfs(1);
		if(flag==0)
			cout<<"NO ANSWER"<<endl;	
	}
	return 0;
}
