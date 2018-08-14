#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[10050];

int n;
int v[600];
int w[600];
int e,f;
int p;
int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>e>>f;
		cin>>n;
		p=f-e;
		memset(dp,INF,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&v[i],&w[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=w[i];j<=p;j++){
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
			}

		}
		if(dp[p]==INF)printf("This is impossible.\n");
		else	printf("The minimum amount of money in the piggy-bank is %d.\n",dp[p]);
	}
}