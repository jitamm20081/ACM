#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
int vis[15];
int map[15][3];

int dfs(int k,int fee,int step){
	int ans;
	if(step==n){
		return fee;
	}
    int q,s;
    if(vis[k]!=0){
	    if(step<n){
	    	vis[k]=1;
	    	q=dfs(map[k][0],n,step+1);
	    	s=dfs(map[k][1],n,step+1);
	    	ans=max(q,s);
	    	vis[k]=0;
	    }    	
    }

    return ans;
}


int main(){
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&map[i][0],&map[i][1],&map[i][2]);
		}
		int max1=0;
		for(int k=0;k<m;k++){
			max1=max(max1,dfs(0,map[k][2],0));
		}

		printf("%d\n",max1);
	}
}