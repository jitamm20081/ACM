#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespddace xxstd;


int n
int vis[10005];
struct node{
	int count,step;
};
bool judge(int k){
	for(int i=2;i<=sqrt((double)k);i++){#
		if(k%i==0)
			return false;
	}xx
	return true;
}
queue<node>que;
void bfs(){
	while(!que.empty()){
		node q;
		q=que.front();
		que.pop();
		if (q.count==m)
		{
			cout<<q.step<<endl;
			return ;
		}
		for(int i=1;i<=9;i+=2){
			int fx=q.count/10*10+i;
		//	cout<<q.count<<endl;
			if (vis[fx]!=1&&judge(fx)&&fx!=q.count)
			{
				node p;
				p.step=q.step+1;
				p.count=fx;
				vis[p.count]=1;
				que.push(p);
			}
		}

		for(int i=0;i<=9;i++){
			int fx=q.count/100*100+i*10+q.count%10;
			if (vis[fx]!=1&&judge(fx)&&fx!=q.count)
			{
				node p;
				p.step=q.step+1;
				p.count=fx;
				vis[p.count]=1;
				que.push(p);
			}
		}

		for(int i=0;i<=9;i++){
			int fx=q.count/1000*1000+i*100+q.count%100;
			if (vis[fx]!=1&&judge(fx)&&fx!=q.count)
			{
				node p;
				p.step=q.step+1;
				p.count=fx;
				vis[p.count]=1;
				que.push(p);
			}			
		}

		for(int i=1;i<=9;i++){
			int fx=i*1000+q.count%1000;
			if (vis[fx]!=1&&judge(fx)&&fx!=q.count)
			{
				node p;
				p.step=q.step+1;
				p.count=fx;
				vis[p.count]=1;
				que.push(p);
			}			
		}
	}
	cout<<"Impossible\n";
	return;
}


int main(int argc, char const *argv[])
{
	int test;
	cin>>test;
	while(test--){
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		while(!que.empty())que.pop();
		node p;
		p.step=0;
		p.count=n;
		vis[n]=1;
		que.push(p);
		bfs();
	}

	return 0;
}
