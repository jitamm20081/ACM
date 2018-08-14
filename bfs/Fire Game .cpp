#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
char map[20][20];
int vis[20][20];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1}; 
struct node{
	int step,x,y;	
}v[20];


int pan(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]=='#'&&vis[i][j]==0)
				return 0;
		}
	}
	return 1;
}
int bfs(node s,node p){
	queue<node>que;
	que.push(s);
	que.push(p);
	int steps=0;
	 memset(vis, 0, sizeof(vis));
	vis[s.x][s.y]=vis[p.x][p.y]=1;
	while(!que.empty()){
		node q=que.front();
		steps=q.step;
		que.pop();
		for(int i=0;i<4;i++){
			int fx=q.x+dx[i];
			int fy=q.y+dy[i];
			if(fx>=0&&fx<n&&fy>=0&&fy<m&&map[fx][fy]=='#'&&vis[fx][fy]==0){
				vis[fx][fy]=1;
				node temp;
				temp.x=fx;
				temp.y=fy;
				temp.step=q.step+1;
				que.push(temp);
			}
		}
	}
	return steps;
} 

int main(){
	int test;
	int g;
	cin>>test;
	for(g=1;g<=test;g++){
		cin>>n>>m;
		int t=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>map[i][j];
				if(map[i][j]=='#'){
					v[t].step=0;
					v[t].x=i;
					v[t++].y=j;
				}
			}
		}
		int ans=1 << 30;
		for(int i=0;i<t;i++){
			for(int j=i;j<t;j++){
				int l=bfs(v[i],v[j]);
				if(l<ans&&pan()){
					ans=l;
				}
			}
		}
		printf("Case %d: ",g);
		
		if(ans==1 << 30){
			cout<<"-1\n";
		}
		else 
			cout<<ans<<endl;
	}
	
}
