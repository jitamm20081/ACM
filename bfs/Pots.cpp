#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
char num[12][12]={"FILL(1)","FILL(2)","POUR(2,1)","POUR(1,2)","DROP(1)","DROP(2)"};
//char num[12][12] = {"FILL(1)","FILL(2)", "DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
int A,B,C;

struct node{
	int x,y,step,oi;
}v[110][110];

struct point{
	int x,y;
};

void DFS(int x,int y){
	if(x==0&&y==0)return;
	DFS(v[x][y].x,v[x][y].y);
	printf("%s\n",num[v[x][y].oi]);
}


int bfs(){
	queue<point>que;
	point p;
	p.x=0;
	p.y=0;
	que.push(p);
	v[0][0].step=0;
	while(!que.empty()){
		point s=que.front();
		que.pop();
		if(s.x==C||s.y==C){
			printf("%d\n",v[s.x][s.y].step);
			DFS(s.x,s.y);
			return 0;
		}
		for(int i=0;i<6;i++){
			point q=s;
			if(i==0){
				q.x=A;
			}
			else if(i==1){
				q.y=B;
			}
			else if(i==2){
				if(q.x+q.y<=A){
					q.x=q.x+q.y;
					q.y=0;	
				}
				else 
				{
					q.y=q.x+q.y-A;
					q.x=A;
					
				}
			}
			else if(i==3){
				if(q.x+q.y<=B){
					q.y=q.x+q.y;
					q.x=0;
					
				}
				else {
					q.x=q.x+q.y-B;
					q.y=B;
				}
			}
			else if(i==4){
				q.x=0;
			}
			else 
				q.y=0;
            
			if(v[q.x][q.y].step==0){//下标保存现在的状态，值保存以前的状态 
				v[q.x][q.y].step=v[s.x][s.y].step+1;
			//	cout<<v[q.x][q.y].step;
				v[q.x][q.y].oi=i;
				v[q.x][q.y].x=s.x;
				v[q.x][q.y].y=s.y;
				que.push(q);
				
			}
			
		}
		
	}
	return -1;
}

int main(){
	while(cin>>A>>B>>C){
		memset(v, 0, sizeof(v));	
		int ans=bfs();
		if(ans==-1)
			cout<<"impossible\n";
	}
}
