#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
char map[220][220];
int vis[220][220];
int vis2[220][220];
int dx[8]={-1,1,0,0,1,-1,-1,1,};
int dy[8]={0,0,-1,1,-1,1,-1,1,};
int n,m;
int count2[220][220];
int count1=0;
struct node{
	int x,y;
};

/*void bfs(int i,int j){
	queue<node>que;
	node q;
	q.x=i;
	q.y=j;
	que.push(q);
	while(!que.empty()){
		node s=que.front();
		que.pop();
		for(int i=0;i<9;i++){
			int fx=s.x+dx[i];
			int fy=s.y+dy[i];
			if(vis2[fx][fy]==0&&map[fx][fy]=='@'){
				vis2[fx][fy]=1;
				map[fx][fy]='*';
				node temp;
				temp.x=fx;
				temp.y=fy;
				que.push(temp);
			}
		}
	}

}*///BFS不适合这道题，搜索的是最短路径，可能导致有油田没有被放置为* 


void dfs(int i,int j){
	map[i][j]='*';
	for(int k=0;k<8;k++){
			int fx=i+dx[k];
			int fy=j+dy[k];
			if(fx>=0&&fx<n&&fy>=0&&fy<m&&map[fx][fy]=='@'){
				dfs(fx,fy);
			}
	}
	return ;
}


int main(){
	while(cin>>n>>m&&n+m>0){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>map[i][j];
			}
		}
		count1=0;
		memset(count2,0,sizeof(count2));
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
					if(map[i][j]=='@')
					{
						dfs(i,j);
						count1++;
					}
					
				}
			}
			


	/*	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
					cout<<map[i][j];
				}
					cout<<endl;
			}*/
		
				
		cout<<count1<<endl;
	}
}




