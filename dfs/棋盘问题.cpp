#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

int status[10];
int map[10][10];
int c,n,k;
void dfs(int j,int m){
	if(m==0){
		c++;
		return ;
	}	
	if(j>n)
	 return ;
	else {
		for(int y=j;y<=n-m;y++){
			for(int i=0;i<n;i++){
				if(map[i][y]==1&&status[i]==0){
					status[i]=1;
					dfs(j+1,m-1);
					status[i]=0;
				}
				
			}
		}
	}

}

int main(){

	while(cin>>n>>k&&n+k>0){
		memset(map,0,sizeof(map));
		memset(status,0,sizeof(status));
		char s[101];
		c=0;
		for(int i=0;i<n;i++){
			
			scanf("%s",s);
			
				for(int h=0;h<n;h++){
					if(s[h]=='#')
						map[i][h]=1;
					else 
						map[i][h]=0;
				}
			
		}
		

		dfs(0,k);
		cout<<c<<endl;		
	}

}
