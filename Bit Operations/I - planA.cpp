#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

struct data{
	int step;
	int x,y,z;
}s;

int n,m,t;
char map[2][15][15];
int dvi[4][2]={0,1,0,-1,1,0,-1,0};
int vis[2][15][15];

int bfs(){
	queue<data>que;
	while(!que.empty())que.pop();
	vis[0][0][0]=1;
	data q;
	q.x=0;
	q.y=0;
	q.z=0;
	q.step=0;
	que.push(q);
	while(!que.empty()){
		data p=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			data tem;
			tem.x=p.x;
			tem.y=p.y+dvi[i][0];
			tem.z=p.z+dvi[i][1];
			if(!vis[tem.x][tem.y][tem.z]&&tem.y>=0&&tem.y<n&&tem.z>=0&&tem.z<m&&map[tem.x][tem.y][tem.z]!='*'){
				vis[tem.x][tem.y][tem.z]=1;
				if(map[tem.x][tem.y][tem.z]=='.'){
					tem.step=p.step+1;
					que.push(tem);
				}
				else if(map[tem.x][tem.y][tem.z]=='#'){
					if(map[tem.x^1][tem.y][tem.z]=='.'&&!vis[tem.x^1][tem.y][tem.z]){
							vis[tem.x^1][tem.y][tem.z]=1;
							tem.x^=1;
							tem.step=p.step+1;
							que.push(tem);						
					}
					else if(map[tem.x^1][tem.y][tem.z]=='P'){
						return p.step+1;
					}	
				}						
				
				else if(map[tem.x][tem.y][tem.z]=='P')
					{
						return p.step+1;
					}				
			}	
		}
		
		}
	return 0x3f3f3f3f;	
}



int main(){
	int test;
	cin>>test;
	while(test--){
		int temp;
		cin>>n>>m>>t;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<m;k++){
					cin>>map[i][j][k];
				}
			}
		}
		temp=bfs();
	//	cout<<temp<<endl;
		if(temp>t)printf("NO\n");
		else printf("YES\n");		
	}
}
