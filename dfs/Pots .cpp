#include<iostream>
#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;

int A,B,C;

int visited[150][150];
struct node{
	int a,b;
	int step;
};
int k=0;
string s[20000];
queue<node>que;
void bfs(){
	while(!que.empty()){
		node q;
		q=que.front();
		que.pop();
		if(q.a==C||q.b==C){
			cout<<q.step<<endl;
			for(int i=0;i<k;i++)
				cout<<s[i]<<endl;
			return ;
		}
		int fx=A,fy=q.b;
		if(visited[fx][fy]==0){
			visited[fx][fy]=1;
			node p;
			p.a=fx;
			p.b=fy;
			s[k++]="FILL(1)";
			p.step=q.step+1;
			que.push(p);
		}
		
		int fx1=q.a,fy1=B;
		if(visited[fx1][fy1]==0){
			visited[fx1][fy1]=1;
			node p;
			p.a=fx1;
			p.b=fy1;
			s[k++]="FILL(2)";
			p.step=q.step+1;
			que.push(p);	
		}
		
		int fx2=A,fy2=q.b+q.a-A;
		if(visited[fx2][fy2]==0){
			visited[fx2][fy2]=1;
			node p;
			p.a=fx2;
			p.b=fy2;
			s[k++]="POUR(2,1)";
			p.step=q.step+1;
			que.push(p);		
		}
		
		int fx3=q.a+q.b-B,fy3=B;
		if(visited[fx3][fy3]==0){
			visited[fx3][fy3]=1;
			node p;
			p.a=fx3;
			p.b=fy3;
			s[k++]="POUR(1,2)";
			p.step=q.step+1;
			que.push(p);
		}
		
		int fx4=0,fy4=q.b;
		if(visited[fx4][fy4]==0){
			visited[fx4][fy4]=1;
			node p;
			p.a=fx4;
			p.b=fy4;
			s[k++]="DROP(1)";
			p.step=q.step+1;
			que.push(p);			
		}				
		
		int fx5=q.a,fy5=0;
		if(visited[fx5][fy5]==0){
			visited[fx5][fy5]=1;
			node p;
			p.a=fx5;
			p.b=fy5;
			s[k++]="DROP(2)";
			p.step=q.step+1;
			que.push(p);				
		}

		int fx6=q.b+q.a,fy6=0;
		if(visited[fx6][fy6]==0){
			visited[fx6][fy6]=1;
			node p;
			p.a=fx6;
			p.b=fy6;
			s[k++]="POUR(2,1)";
			p.step=q.step+1;
			que.push(p);					
		}
		
		
		int fx7=0,fy7=q.b+q.a;
		if(visited[fx7][fy7]==0){
			visited[fx7][fy7]=1;
			node p;
			p.a=fx7;
			p.b=fy7;
			s[k++]="POUR(1,2)";
			p.step=q.step+1;
			que.push(p);					
		}				
	}

}

int main(){
	cin>>A>>B>>C;
	node p;
	p.a=0;
	p.b=0;
	p.step=0;
	visited[0][0]=1;
	que.push(p);
	bfs();
}
