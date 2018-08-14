#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n,m,k,life;
bool vis[110][110][1001];
int dv[5][2] = {0,1,1,0,0,-1,-1,0,0,0};

struct node{
	int x,y,step;
};

struct ta{
	int v2,t;
	char c;
}v[110][110];


void bfs(){
	queue<node>que;
	node p;
	int flag;
	int j;
	int temp;
	p.x=0;
	p.y=0;
	p.step=0;
	que.push(p);
	vis[0][0][0]=1;
	while(!que.empty()){
		node q=que.front();

		que.pop();
		if(q.step>life)
			break;
		if(q.x==n&&q.y==m)
		{
			printf("%d\n",q.step);
			return ;
		}

			for(int i=0;i<5;i++){
				node next=q;
				next.x+=dv[i][0];
				next.y+=dv[i][1];
				next.step++;
				if(next.x<=n&&next.x>=0&&next.y>=0&&next.y<=m){
					if(!v[next.x][next.y].t&&!vis[next.x][next.y][next.step]&&next.step<=life){
						flag=1;
						for(j=next.x-1;j>=0;j--){
							if(v[j][next.y].t&&v[j][next.y].c=='S'){
								if((next.x-j)%v[j][next.y].v2)break;
								temp=next.step-(next.x-j)/v[j][next.y].v2;
								if(temp<0)break;
								if(temp%v[j][next.y].t==0)
							    {
									flag=0;
									break;
								}
							}
							if(v[j][next.y].t)
								break;
						}
						if(!flag)continue; 

						for(j=next.y-1;j>=0;j--){
							if(v[next.x][j].t&&v[next.x][j].c=='E'){
								if((next.y-j)%v[next.x][j].v2)break;
								temp=next.step-(next.y-j)/v[next.x][j].v2;
								if(temp<0)break;
								if(temp%v[next.x][j].t==0)
								{
									flag=0;
									break;
								}
							}
							if(v[next.x][j].t)
								break;
						}
						if(!flag)continue; 

						for(j=next.x+1;j<=n;j++){
							if(v[j][next.y].t&&v[j][next.y].c=='N'){
								if((j-next.x)%v[j][next.y].v2)break;
								temp=next.step-(j-next.x)/v[j][next.y].v2;
								if(temp<0)break;
								if(temp%v[j][next.y].t==0)
								 {
									flag=0;
									break;
								}
							}
							if(v[j][next.y].t)
								break;
						}
						if(!flag)continue; 

						for(j=next.y+1;j<=m;j++){
							if(v[next.x][j].t&&v[next.x][j].c=='W'){
								if((j-next.y)%v[next.x][j].v2)break;
								temp=next.step-(j-next.y)/v[next.x][j].v2;
								if(temp<0)break;
								if(temp%v[next.x][j].t==0)
								 {
									flag=0;
									break;
								}
							}
							if(v[next.x][j].t)
								break;
						}
						if(!flag)continue; 
						vis[next.x][next.y][next.step]=1;
						que.push(next);
					}
				}
			}
	}
	printf("Bad luck!\n");
	
}




int main(){
	char str[3];
	int t,v1,x,y;
	while(~scanf("%d%d%d%d",&n,&m,&k,&life)){
		memset(v,0,sizeof(v));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<k;i++){
			scanf("%s%d%d%d%d",str,&t,&v1,&x,&y);
			v[x][y].c=str[0];
			v[x][y].t=t;
			v[x][y].v2=v1;
		}
		bfs();
	}
	return 0;
}
