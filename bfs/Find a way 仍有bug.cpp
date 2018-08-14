#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int small;
int g1=0,l=0;
int sx1,sy1,sx2,sy2;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
const int INF=0x1f1f1f1f;
int map1[250][250],vis1[250][250],vis2[250][250],g[250][250],visited[250][250];
char map2[250][250];
struct node{
	int x,y;
};


void solve(int i,int j,char ch){
		if(ch=='#'){
			map1[i][j]=-1;
			vis1[i][j]=INF;
			vis2[i][j]=INF;
		}
		if(ch=='.'){
			map1[i][j]=0;
			vis1[i][j]=INF;
			vis2[i][j]=INF;
		}
		if(ch=='Y'){
			map1[i][j]=0;
			vis1[i][j]=0;
			vis2[i][j]=INF;
			sx1=i;
			sy1=j;
		}
		if(ch=='M'){
			map1[i][j]=0;
			vis1[i][j]=INF;
			vis2[i][j]=0;
			sx2=i;
			sy2=j;
		}
		if(ch=='@'){
			map1[i][j]=INF;
			vis1[i][j]=INF;
			vis2[i][j]=INF;
			g[i][j]=500;
			l++;
		}

}

void bfsy(){
	queue<node>quey;
	memset(visited,0,sizeof(visited));
	node q;
	q.x=sx1;
	q.y=sx2;
	quey.push(q);
	visited[q.x][q.y]=1;
	vis1[q.x][q.y]=0;
	while(!quey.empty()){
		node p;
		p=quey.front();
		quey.pop();
		if(map1[p.x][p.y]==INF){
			map1[p.x][p.y]=vis1[p.x][p.y];
		//	cout<<vis1[p.x][p.y]<<endl;
			g1++;
		}
		if(g1==l)
			return;
		for(int i=0;i<4;i++){
			int fx=p.x+dx[i];
			int fy=p.y+dy[i];
			if(fx>=1&&fx<=n&&fy<=m&&fy>=1&&map2[fx][fy]!='#'&&visited[fx][fy]==0){
					visited[fx][fy]=1;
					vis1[fx][fy]=vis1[p.x][p.y]+1;
					node temp;
					temp.x=fx;
					temp.y=fy;
					quey.push(temp);
			}

		}
		
	}
}


void bfsm(){
	queue<node>quem;
	memset(visited,0,sizeof(visited));
	node q;
	q.x=sx2;
	q.y=sy2;
	quem.push(q);
	visited[q.x][q.y]=1;
	vis2[q.x][q.y]=0;
	while(!quem.empty()){
		node p;
		p=quem.front();
		quem.pop();
		if(g[p.x][p.y]==500){
			map1[p.x][p.y]=vis1[p.x][p.y]+vis2[p.x][p.y];
			cout<<vis1[p.x][p.y]<<endl<<vis2[p.x][p.y]<<endl;	
		//	cout<<"ddsad"<<endl;
			g1++;
		}
		if(g1==l)
			return ;
		for(int i=0;i<4;i++){
			int fx=p.x+dx[i];
			int fy=p.y+dy[i];
			if(fx>=1&&fx<=n&&fy<=m&&fy>=1&&map2[fx][fy]!='#'&&visited[fx][fy]==0){
					visited[fx][fy]=1;
					vis2[fx][fy]=vis2[p.x][p.y]+1;
					node temp;
					temp.x=fx;
					temp.y=fy;
					quem.push(temp);
			}

		}
		
	}
}

int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(map1,0,sizeof(map1));
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(g,0,sizeof(g));
		char ch;
		g1=0,l=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>ch;
				map2[i][j]=ch;
				solve(i,j,ch);
			}		
		}
	//	cout<<l<<endl;
		bfsy();
		g1=0;
		bfsm();
	//	cout<<g1<<endl;
		small=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<map1[i][j]<<' ';
					//cout<<vis1[i][j]<<endl<<vis2[i][j]<<endl;	
				if(g[i][j]==500){
					if(small>map1[i][j])
						small=map1[i][j];					
				}

				
			}
			 cout<<endl;
		}  
		cout<<small*11<<endl;
	}
}
