#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define mod 1000007
int d[5][8]{
	0, 0, 0, 0, 0 ,0, 0, 0,
    11,12,13,14,15,16,17,0,
    21,22,23,24,25,26,27,0,
    31,32,33,34,35,36,37,0,
    41,42,43,44,45,46,47,0
};


struct data{
	int g[10][10];
	int step;
}e,w,s,q[mod>>1];

bool b[mod+10];
int ha1sh(int g[][10]){
	long long tot=0,hash=0,s[101]={0};
	for(int i=1;i<=4;i++){
		for(int j=0;j<=7;j++){
			s[++tot]=g[i][j]%10;
			s[++tot]=g[i][j]/10;
		}
	}

	for(int i=1;i<=tot;i++)
		hash=hash*7+s[i];

	return (hash&0x7fffffff)%mod;
}


void change(int x,int x1,int x2){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=7;j++){
			if(w.g[i][j]==x){
				swap(w.g[i][j],w.g[x1][x2]);
				return ;
			}
		}
	}
}


bool jd(data e){
	for(int i=1;i<=4;i++){
		for(int j=0;j<=7;j++){
			if(d[i][j]!=e.g[i][j])
				return false;
		}
	}
	return true;
}

bool bfs(){
	int head=0,tail=1;
	s.g[1][0]=11;
	s.g[2][0]=21;
	s.g[3][0]=31;
	s.g[4][0]=41;
	s.step=0;
	b[ha1sh(s.g)]=true;
	q[tail]=s;
	while(head<tail){
		head++;
		e=q[head];
		if(jd(e)){
			printf("%d\n",e.step);
			return true;
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=7;j++){
				w=e;
				if(!e.g[i][j]){
					int x=e.g[i][j-1];
					if(x==17||x==27||x==37||x==47||x==0)continue;
					change(x+1,i,j);
					int xx=ha1sh(w.g);
					if (!b[xx])
					{
						b[xx]=true;
						w.step++;
						tail++;
						q[tail]=w;
					}
				}				
			}
		}

	}
	return false;
}


int main(){
	int test;
	cin>>test;
	while(test--){
		int x;
		memset(s.g,0,sizeof(s.g));
		memset(b,0,sizeof(b));
		for(int i=1;i<=4;i++){
			for(int j=1;j<=7;j++){
				cin>>x;
				s.g[i][j]=x;
				if(s.g[i][j]==11||s.g[i][j]==21||s.g[i][j]==31||s.g[i][j]==41){
					s.g[i][j]=0;
				}
			}
		}
		if(bfs()==true)continue;
		else printf("-1\n");
	}
}