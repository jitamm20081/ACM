#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int map[5][5],vis[5][5];
int f[30];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(){
	memset(vis,0,sizeof(vis));
	queue<int>que;
	que.push(0);
	vis[0][0]=1; 
	int x,y;
	while(!que.empty()){
		int now;
		now=que.front();
		que.pop();
		x=now/5;
		y=now%5;
		if(x==4&&y==4)
			break;
		int p,q;
		int i;
		for(i=0;i<4;i++){
			int p=x+dx[i];
			int q=y+dy[i];
			if(vis[p][q]==0&&p>=0&&p<=4&&q>=0&&q<=4&&map[p][q]!=1){
				vis[p][q]=1;
				f[5*p+q]=now;
				que.push(5*p+q);
			}
		}
	}
	
}

int main(){
	memset(f,0,sizeof(f));
	stack<int>stc;
	int n=24;
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cin>>map[i][j];
		}
	}
	bfs();
	stc.push(n);
	while(f[n]!=0){
		n=f[n];
		stc.push(n);
	} 
	stc.push(0);
	while(!stc.empty()){
		int now=stc.top();	
		printf("(%d, %d)\n",now/5,now%5);
		stc.pop();
	}
	return 0;
} 
