#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
float dp[10050];
int w[10050];
float v[10050];


int main(){
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			scanf("%d%f",&w[i],&v[i]);
		}
		for(int i=0;i<=n;i++)
			dp[i]=1.0;

		for(int i=1;i<=m;i++){
			for(int j=n;j>=w[i];j--){
					dp[j]=min(dp[j-1],dp[j-w[i]]*(1-v[i]));			
			}
		}
		printf("%.1f%%\n",(1.0-dp[n])*100);
	}
}