#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 101
int m,n,s;
int visit[maxn][maxn];
struct node{
	int all,x,y,t;
}; 

void dfs(){
	queue<node>que;
	node p,q;
	p.all=s,p.x=0,p.y=0;
	memset(visit,0,sizeof(visit));
	que.push(p);
	while(!que.empty()){
		p=que.front();
		que.pop();
		if(p.all==p.y&&p.y==s/2){
			cout<<p.t<<endl;
			return ;
		}
		if(p.all+p.x>m){
			q.x=m;q.y=p.y;q.all=p.all+p.x-m;q.t=p.t+1;
			if(!visit[q.x][q.y])
			visit[q.x][q.y]=1,que.push(q);
		}
		else{
			q.x=p.all+p.x;q.y=p.y;q.all=0;q.t=p.t+1;
			if(!visit[q.x][q.y])
			visit[q.x][q.y]=1,que.push(q);
		}
		q.all=p.all+p.x;q.x=0;q.y=p.y;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);	
		if(p.x+p.y>m){
			q.x=m;q.y=p.x+p.y-m;q.all=p.all;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);				
		}
		else{
			q.x=p.x+p.y;q.y=0;q.all=p.all;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);	
		}
		if(p.x+p.y>n){
			q.x=p.x+p.y-n;q.y=n;q.all=p.all;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);	
		}
		else{
			q.x=0;q.y=p.x+p.y;q.all=p.all;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);	
		}
		if(p.all+p.y>n){
			q.x=p.x;q.y=n;q.all=p.all+p.y-n;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);			
		}	
		else{
			q.x=p.x;q.y=p.all+p.y;q.all=0;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);			
		}
		q.all=p.all+p.y;q.x=p.x;q.y=0;q.t=p.t+1;
			if(!visit[q.x][q.y])
				visit[q.x][q.y]=1,que.push(q);			
	}
	if(s%2==0)
	cout<<"NO"<<endl;
}


int main()
{
	while(cin>>s>>m>>n){
		if(s%2!=0)
			cout<<"NO"<<endl;
		if(m>n)swap(m,n);
		dfs();
	}
} 
