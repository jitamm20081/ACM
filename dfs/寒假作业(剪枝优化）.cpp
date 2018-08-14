#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int ans=0;
int a[20]; 
int visited[20];
bool judge(int u){//¼ôÖ¦º¯Êı 
	if(u==3){
		if(a[0]+a[1]==a[2])
			return true;
		else 
			return false;
	}
	if(u==6){
		if(a[3]-a[4]==a[5])
			return true;
		else 
			return false;
	}
	if(u==9){
		if(a[6]*a[7]==a[8])
			return true;
		else 
			return false;
	}
	if(u==12){
		if(a[11]*a[10]==a[9])
		{
			ans++;
			return true;
		}
		else 
			return false;
	}
}

void dfs(int u){
	if(u==3||u==6|u==9||u==12){
		if(!judge(u)){
			return;
		}
	}
	if(u==12){
		return ;
	}
	for(int i=1;i<=13;i++){
		if(!visited[i]){
			visited[i]=1;
			a[u]=i;
			dfs(u+1);
			visited[i]=0;
		}
	}
}

int main(){
	
	dfs(0);
	cout<<ans<<endl;
}
