#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int map[1000][1000],vis[1000][1000],map1[1000][1000];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,m;
struct Node{
	int x,y;
};
queue<Node>que;
int bfs(int i,int j){
	Node node;
	node.x=i;
	node.y=j;
	que.push(node);
	while(!que.empty()){
		Node p=que.front();
		que.pop();
		if(map[p.x][p.y]==1){
			return (abs(i-p.x)+abs(j-p.y));
		}
		for(int i=0;i<4;i++){
			int fx=dx[i]+p.x;
			int fy=dy[i]+p.y;
			if(fx<=n&&fx>=0&&fy>=0&&fy<=m&&vis[fx][fy]==0){
				vis[fx][fy]=1;
				Node temp;
				temp.x=fx;
				temp.y=fy;
				que.push(temp);
			}
		}
	}
}

int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			 	cin>>map[i][j];
			 	map1[i][j]=map[i][j];
			 } 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			 	if(map[i][j]==0)
			 		map1[i][j]=bfs(i,j);
			 		memset(vis,0,sizeof(vis)); 
			 		while(!que.empty()){
			 			que.pop();
					 }
				if(map[i][j]==1){
					map1[i][j]=0;
				}
			 } 
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<map1[i][j]<<" ";
			 } 
			 cout<<endl;
		}		
	}

}
