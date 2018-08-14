#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tag[1010][1010];
int dp[1010][1010];
int main(){
	int i,j;
	int n,m;
	int x,y;
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		memset(tag,0,sizeof(tag));
		dp[0][1]=1;
		while(m--){
			cin>>x>>y;
			tag[x][y]=1;
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%100003;
				if(tag[i][j]==1)
					dp[i][j]=0;
			}
		}
		cout<<dp[n][n]<<endl;		
	}

}