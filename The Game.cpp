#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int x1,y1,x2,y2,h,w;;
int sharp[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//上下左右前后

struct Node{
	int x,y,step,dir;//步数方向
};

char map[77][77];
bool visit[77][77];

int bfs(){
	memset(visit,0,sizeof(visit));
	queue<Node>q;
	Node s,e;
	s.x=x1;
	s.y=y1;
	s.dir=0;
	s.step=0;//初始化步数为0
	visit[s.x][s.y]=1;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			e.x=s.x+sharp[i][0];
			e.y=s.y+sharp[i][1];
			if(e.x==s.x)e.dir=1;//横向移动
			else e.dir=2;
			if(e.x>=0&&e.x<=h+1&&e.y>=0&&e.y<=w+1&&!visit[e.x][e.y])
			{	
				if(s.dir==0)e.step=1;
				else
				{
					if(e.dir==s.dir)e.step=s.step;
					else e.step=s.step+1;
					}
				
				if(e.x==x2&&e.y==y2) return e.step;
				
				 if(map[e.x][e.y]==' '){
				 	visit[e.x][e.y]=1;
				 	q.push(e);
				 }
			}
		}
	}
	return false;
}

int main(){

	int step,board=1;

	while(cin>>w>>h){
		int i,j;
		memset(map,' ',sizeof(map));
		if(w+h==0)break;
		for(i=1;i<=h;i++){
		
			getchar();
			for(j=1;j<=w;j++){
				map[i][j]=getchar();
			}
    }
		printf("Board #%d:\n",board++);
		int qu=1;
		while(cin>>y1>>x1>>y2>>x2){
			
			if(x1+x2+y1+y2==0)break;
			step=bfs();
			if(!step){
				printf("Pair %d: impossible.\n",qu++);
			}
			else 
				printf("Pair %d: %d segments.\n",qu++,step);
				
		}
		printf("\n");  
	}
	return 0;
}
