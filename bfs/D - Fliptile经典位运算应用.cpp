#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tile[20][20];
int flip[20][20];
int opt[20][20];
int M,N;
int dx[5]={-1,0,0,0,1};
int dy[5]={0,-1,0,1,0};
const int INF=100000000;

int get(int i,int j){
	int c=tile[i][j];
	for(int k=0;k<5;k++){
		int fx=i+dx[k];
		int fy=j+dy[k];
		if(fx>=0&&fx<M&&fy>=0&&fy<N){
				c+=flip[fx][fy];			
		}
	}	
	return c%2; 
}

int  col(){

	for(int i=1;i<M;i++)
		for(int j=0;j<N;j++){
			if(get(i-1,j))
				flip[i][j]=1;
		}
	
	for(int j=0;j<N;j++)
		if(get(M-1,j))
			return -1;	
	
	int ans=0;	
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			ans+=flip[i][j];
		
		
	return ans;

}

void solve(){
	int ans=-1;
	for(int i=0;i<1<<N;i++){
       	memset(flip, 0, sizeof(flip));
		for(int j=0;j<N;j++){
			flip[0][N-j-1]=i>>j&1;
		}
		int num=col();
		if(num>=0&&(ans<0||ans>num))
		{

			ans=num;
			memcpy(opt,flip,sizeof(flip));
		}
	}
	
	if(ans<0)
		cout<<"IMPOSSIBLE"<<endl;
	else 
		{
			for(int i=0;i<M;i++){
				for(int j=0;j<N;j++){
					cout<<opt[i][j]<<(j + 1 == N ? '\n' : ' ');
				}
			}
		}
}

int main(){
	while(cin>>M>>N){
		memset(tile,0,sizeof(tile));
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>tile[i][j];
			}
		}
		solve();
	}
}
