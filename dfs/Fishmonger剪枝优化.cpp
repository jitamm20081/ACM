#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int limittime,n,limitexpense;
int t1[100][100],e[100][100],visited[100][100];
int mint=1000000,mine=1000000;
void dfs(int u,int t,int ex){
	if(u==n){
		if(t<=limittime&&mine>ex){
			mint=t;
			mine=ex;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(i==u)continue;
		if(!visited[u][i]&&(t+t1[u][i])<=limittime&&(ex+e[u][i])<=mine){//¼ôÖ¦Ìõ¼þ 
			visited[u][i]=1;
			dfs(i,t+t1[u][i],ex+e[u][i]);
			visited[u][i]=1;
		}
	} 
}

int main(){
	while(cin>>n>>limittime&&n+limittime>0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>t1[i][j];
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>e[i][j];
			}
		}
		
		dfs(1,0,0);
		cout<<mine<<" "<<mint<<endl;
		
	}
} 
