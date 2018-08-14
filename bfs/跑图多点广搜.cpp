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
	int x,y,step;
};
queue<Node>que;
int bfs(){
	while(!que.empty()){
		Node p=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			int fx=dx[i]+p.x;
			int fy=dy[i]+p.y;
			if(fx<=n&&fx>=0&&fy>=0&&fy<=m&&vis[fx][fy]==0){
				vis[fx][fy]=p.step+1;
				Node temp;
				temp.x=fx;
				temp.y=fy;
				temp.step=p.step+1; 
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
			 	if(map[i][j]){
			 		Node p;
			 		p.x=i;
			 		p.y=j;
			 		p.step=0;
			 		que.push(p);
			 		vis[i][j]=-1;
				 }
			 } 
		} 
		bfs();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vis[i][j]!=-1)
					cout<<vis[i][j]<<" ";
				else 
				     cout<<"0 ";	
			 } 		
			 cout<<endl;
			}

}} 

