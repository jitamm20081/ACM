#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int map[10][10];
int visited[10][10];
int fangan;

bool placeb(int r,int c){
	int i,j;
	for(i=r;i>=0;i--){
		if(map[i][c]==2)
			return false;
	}
	for(j=c;j>=0;j--){
		if(map[r][j]==2)
			return false;
	}
	
	for(i=r,j=c;i>=0,j<=n;i--,j++){
		if(map[i][j]==2)
			return false;
	}
	
	return true;
}

bool placeh(int r,int c){
	int i,j;
	for(i=r;i>=0;i--){
		if(map[i][c]==-1)
			return false;
	}
	for(j=c;j>=0;j--){
		if(map[r][j]==-1)
			return false;
	}
	
	for(i=r,j=c;i>=0,j<=n;i--,j++){
		if(map[i][j]==-1)
			return false;
	}
	
	return true;
}

void dfs(int baisum,int heisum){
	if(baisum==n&&heisum==n)
	{
		fangan++;
		return;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){

			if(map[i][j]==1&&placeb(i,j)&&!placeh(i,j)){
				map[i][j]=2;
				dfs(baisum+1,heisum);
				map[i][j]=1;
						
			}
			if(map[i][j]==1&&placeh(i,j)&&!placeb(i,j)){
				map[i][j]=-1;
				dfs(baisum,heisum+1);
				map[i][j]=1;
			}	
			if(map[i][j]==1&&placeh(i,j)&&placeb(i,j)){
				map[i][j]=2;
				dfs(baisum+1,heisum);
				map[i][j]=1;
			}	
		}
	}
		
	
}
int main(){
	int i,j;
	while(cin>>n){
		fangan=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>map[i][j];
			}
		}
		dfs(0,0);
		cout<<fangan*2<<endl;
	}	
	
}
