#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int L,R,C;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};
char map[50][50][50];
int visited[50][50][50];
struct node{
	int x,y,z;
};
queue<node>que;
bool bfs(){
	while(!que.empty()){
		node q;
		q=que.front();
		que.pop();
		if(map[q.x][q.y][q.z]=='E'){
			return true;
		}
		for(int i=0;i<6;i++){
			int fx=q.x+dx[i];
			int fy=q.y+dy[i];
			int fz=q.z+dz[i];
			if(visited[fx][fy][fz]==0&&fx>=0&&fx<L&&fy>=0&&fy<R&&fz>=0&&fz<C&&map[fx][fy][fz]!='#'){
				visited[fx][fy][fz]=visited[q.x][q.y][q.z]+1;
				node temp;
				temp.x=fx;
				temp.y=fy;
				temp.z=fz;
				que.push(temp);
			}
		}
	}
	return false;
}

int main(){
	while(cin>>L>>R>>C&&L+R+C!=0){
		int sx,sy,sz;
		memset(visited,0,sizeof(visited));
		while(!que.empty())que.pop();
		for(int i=0;i<L;i++){
			for(int j=0;j<R;j++){
				for(int k=0;k<C;k++){
					cin>>map[i][j][k];
					if(map[i][j][k]=='S'){
						node p;
						p.x=i;
						p.y=j;
						p.z=k;
						que.push(p);						
					}
					if(map[i][j][k]=='E'){
						sx=i;
						sy=j;
						sz=k;
					}

				}
			}
		}
		if(bfs()){
			printf("Escaped in %d minute(s).\n",visited[sx][sy][sz]);
		}
		else 
			printf("Trapped!\n");
	}	
}
