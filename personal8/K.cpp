#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long k=0;
int n,m;
int vis[10001][10001];
int map[10001][10001];
void dfs(int i,int j){
	if(i==n&&j==m)
	{
		k++;
	}
	for(int k=i;k<=n;k++){
			if(map[k][j]==0&&vis[k][j]==0){
				vis[k][p]=1;
				dfs(i,j+1);
				vis[k][p]=0;
			}
	}

}


int main(){
	while(cin>>n>>m){
		int q,p;
		for(int i=1;i<=m;i++){
			cin>>q>>p;
			map[q][p]=1;
		}
		dfs(1,1);
		cout<<k%100003;
	}
}

