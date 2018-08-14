#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
int vis[100001];
int step[100001]; 
int Time;
	int N,K;
struct node{
	int x,step;
};

void bfs(){
	queue<node>que;
	while(!que.empty())que.pop();
	node p;
	p.x=N;
	vis[p.x]=1;
//	step[p.x]=0;
	p.step=0;
	que.push(p);
	while(!que.empty()){
		node q=que.front();
		que.pop();
		if(q.x==K){
			Time =q.step;
			break;
		}
		for(int i=0;i<3;i++){
			int fx;
			if(i==0)
				fx=q.x+1;
			if(i==1)
				fx=q.x-1;
			if(i==2)
				fx=q.x*2;
			if(fx<0||fx>100000)continue;
			if(vis[fx]==0){
				vis[fx]=1;
				//step[fx]=step[q.x]+1;
				node p;
				p.x=fx;
				p.step=q.step+1;
				que.push(p);
			}
		}
	}
	return ;
}


int main(){

	while(cin>>N>>K){
		memset(vis,0,sizeof(vis));
		bfs();
		cout<<Time<<endl;
	}
	
} 
