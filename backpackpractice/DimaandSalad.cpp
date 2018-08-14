#include<bits/stdc++.h>
const int INF=0x3f3f3f3f;
using namespace std;
int dp[110][200000];
int a[120];
int b[120];
int c[120];
int n,k;
int N;
int bb;
int main(){
		cin>>n>>k;
		N=n*100;
		memset(dp,-INF,sizeof(dp));
		dp[0][N]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&bb);
			bb=a[i]-k*bb;
			for(int j=2*N;j>=c[i];j--){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-bb]+a[i]);
			}
		}
		if(dp[n][N]==0)printf("-1\n");
		else printf("%d\n",dp[n][N]);
}