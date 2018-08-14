#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std; 
const int INF = 1000000;
const int max1 = 1010;
int R,C;
int sx,sy;
int Time;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int g[max1][max1],visit[max1][max1],fire[max1][max1];
struct node{
	int x,y;
};

queue<node>Fire;
void solve(int i, int j, char ch){
	if(ch=='#'){
		g[i][j]=-1;
		visit[i][j]=INF;
		fire[i][j]=INF;
	}
	if(ch=='.'){
		g[i][j]=1;
		visit[i][j]=INF;
		fire[i][j]=INF;
	}
	if(ch=='J'){
		sx=i;
		sy=j;
		//g[i][j]=1;
		visit[i][j]=0;
		fire[i][j]=INF;
	}
	if(ch=='F'){
		node k;
		k.x=i;
		k.y=j;
		g[i][j]=0;
		visit[i][j]=INF;
		fire[i][j]=0;
		Fire.push(k);
	}
}


void fire_bfs(){
	while(!Fire.empty()){
			node p;
			p=Fire.front();
			Fire.pop();
			for(int i=0;i<4;i++){
				int fx=dx[i]+p.x;
				int fy=dy[i]+p.y;
				if(fx<=R&&fx>=1&&fy<=C&&fy>=1&&g[fx][fy]!=-1){
					if(fire[fx][fy]>fire[p.x][p.y]+1){
						fire[fx][fy]=fire[p.x][p.y]+1;
						node temp;
						temp.x=fx;
						temp.y=fy;
						Fire.push(temp);
					}
				}
			}					
	}
}

void road_bfs(){
	queue<node>Road;
	node k;
	k.x=sx;
	k.y=sy;
	Road.push(k);
	while(!Road.empty()){
		node p;
		p=Road.front();
		Road.pop();
			if(p.x==R||p.x==1||p.y==1||p.y==C){
				Time=visit[p.x][p.y];
				return;
			}
		for(int i=0;i<4;i++){
			int fx=dx[i]+p.x;
			int fy=dy[i]+p.y;
			if(fx>=1&&fx<=R&&fy>=1&&fy<=C&&g[fx][fy]!=-1){
				if(visit[fx][fy]>visit[p.x][p.y]+1&&visit[p.x][p.y]+1<fire[fx][fy])
				{
						visit[fx][fy]=visit[p.x][p.y]+1;
						node temp;
						temp.x=fx;
						temp.y=fy;
						Road.push(temp);
				}
			}
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		while(!Fire.empty()){
			Fire.pop();
		}
		cin>>R>>C;
		getchar();		
		char ch;
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++){
				scanf("%c",&ch);
				solve(i,j,ch);
			}
			getchar();
		}
		Time=INF; 
		fire_bfs();
		road_bfs();
		if(Time!=INF){
			printf("%d\n",Time+1);
		}
		else 
			printf("IMPOSSIBLE\n");
	}
}
