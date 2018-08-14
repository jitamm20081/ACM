#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second

char  nm[810][810];

int n,m;
ii G,M,Z[2];
int s;
queue<ii>q[2];

int div1[4][2]={1,0,-1,0,0,-1,0,1};

bool judge(ii temp){
	if(temp.x<1||temp.x>n||temp.y<1||temp.y>m)return 0;
	int s1,s2;
	s1=abs(temp.x-Z[0].x)+abs(temp.y-Z[0].y);
	s2=abs(temp.x-Z[1].x)+abs(temp.y-Z[1].y);
	if(s1<=2*s||s2<=2*s||nm[temp.x][temp.y]=='X'||nm[temp.x][temp.y]=='\0')
		return 0;
	return 1;
}

bool bfs(int t,int v,int h,int e){
	while(v--){
		queue<ii>qt=q[t];
		while(!qt.empty()){
			ii ne=qt.front();
			qt.pop();
			q[t].pop();
			if(!judge(ne))continue;
			for(int i=0;i<4;i++){
				ii yes(ne.x+div1[i][0],ne.y+div1[i][1]);
				if(!judge(yes)||nm[yes.x][yes.y]==h)continue;
				if(nm[yes.x][yes.y]==e)return 1;
				nm[yes.x][yes.y]=h;
				q[t].push(yes);			
			}
		}
	}
	return 0;
}

int solve(){
	s=0;
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	q[0].push(G);
	q[1].push(M);
	while(!q[0].empty()&&!q[1].empty()){
		s++;
		bool s2=bfs(1,3,'M','G');
		bool s1=bfs(0,1,'G','M');

		if(s1||s2)return s;
	}
	return -1;
}



int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>n>>m;
		int k=0;
		memset(nm,'X',sizeof(nm));
		for(int i=1;i<=n;i++){
			scanf("%s",nm[i]+1);
			for(int j=1;j<=m;j++){
				if(nm[i][j]=='G'){
					G.x=i;
					G.y=j;
				}
				if(nm[i][j]=='M'){
					M.x=i;
					M.y=j;
				}
				if(nm[i][j]=='Z'){
					Z[k].x=i;
					Z[k++].y=j;
				}
			}
		}
		cout<<solve()<<endl;
	}
}