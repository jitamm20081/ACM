#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
	int n;
	int test;
	test=1;
	while(cin>>n){
		int hmax[10050],sum[10050],dp[10050]; 
		int shu[10050];
		sum[0]=0;
		hmax[0]=0;
		for(int i=1;i<=n;i++){
			cin>>shu[i];
			hmax[i]=max(shu[i],hmax[i-1]);
			sum[i]=sum[i-1]+shu[i];
		}
		
		for(int i=0;i<=10050;i++){
			dp[i]=1000000;
		}
		dp[0]=dp[1]=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=0;j--){
				if(hmax[j]<=sum[i]-sum[j]&&dp[j]+i-j-1<dp[i]){
					dp[i]=dp[j]+i-j-1;
					hmax[i]=sum[i]-sum[j];
					break;
				}
			}
		}
		
		printf("Case %d: ",test++);
		printf("%d\n",dp[n]);
	}
}
