#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int map[10][10];
int n;

bool place(int r,int c){
	for(int i=r;i>=0;i--){
		if(map[i][c]<0)return false;
		if(!map[i][c])break;
	}
	for(int j=c;j>=0;j--){
		if(map[r][j]<0)return false;
		if(!map[r][j])break;
	}
	return true;
}

int dfs(int i,int j){
	int mx=0;
	int cnt=0;	
	while(i<n){
		if(map[i][j]&&place(i,j)){
			map[i][j]=-1;//放置
			cnt = dfs(i,j+1)+1;
			if(cnt>mx)mx=cnt;
			map[i][j]=1;//恢复 依次搜索每一个点 
		}
		if(j>=n-1){
			i++;
			j=0;
		} 
		else
			j++;
	}
	return mx;
}

int main(){

	while(cin>>n){
		if(n==0) break;
		char s[20];
		for(int i=0;i<n;i++){
			scanf("%s",s);{
				for(int j=0;j<n;j++){
					if(s[j]=='.'){
						map[i][j]=1;
					}	
					else
						map[i][j]=0;
				}
			}
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<map[i][j];
			}			
			cout<<endl;
			}*/

		cout<<dfs(0,0)<<endl;
	}
	return 0;
}
