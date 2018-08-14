#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

char map[20][20];
int n,k;
int visited[20];
int ans=0;
void dfs(int r,int k){
	if(k==0){
		ans++;
		return;
	}
	for(int i=r;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='#'&&visited[j]==0){
				visited[j]=1;
				dfs(i+1,k-1);
				visited[j]=0;
			}
		}
	}
}

int main(){
	while(cin>>n>>k&&n+k>=0){
		ans=0;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j];
			}
		}
		dfs(0,k);
		cout<<ans<<endl;
	}
	
}
