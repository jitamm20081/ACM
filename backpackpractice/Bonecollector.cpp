#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1200];

int weight[1050];
int value[1050];
int n,v;
int main(){
	int test;
	cin>>test;
	while(test--){
		scanf("%d%d",&n,&v);
		memset(dp,0,sizeof(dp));

		for(int i=0;i<n;i++){
			scanf("%d",&value[i]);
		}

		for(int i=0;i<n;i++)
			scanf("%d",&weight[i]);

		for(int i=0;i<n;i++){
			for(int j=v;j>=weight[i];j--)
				dp[j]=max(dp[j-weight[i]]+value[i],dp[j]);
		}

		cout<<dp[v]<<endl;
	}
}