#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int map[10][10];
int sum=0;
bool place(int r,int c,int s){
	int i,j;
	for(i=r;i>=0;i--){
		if(map[i][c]==s)
			return false;
	}
/*	for(j=c;j>=0;j--){
		if(map[r][j]==s)
			return false;
	}*/
	for(i=r,j=c;i>=0,j>=0;i--,j--){
		if(map[i][j]==s)
			return false;
	}
	for(i=r,j=c;i>=0&&j<n;i--,j++){
		if(map[i][j]==s)
			return false;
	}
	return true;
}

void dfs(int x,int s){
	if(x==n){
		if(s==2) dfs(0,3);//bai
		else sum++;
	}
	for(int i=0;i<n;i++){
		if(map[x][i]!=1)continue;
		if(place(x,i,s))
			map[x][i]=s;
		else continue;
			dfs(x+1,s);
			map[x][i]=1;
	}
}

int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j];
			}
		}
		dfs(0,2);
		cout<<sum<<endl;		
	}
}
