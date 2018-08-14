#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int dp[125000];

int main(){
	int value[1050];
	int num[1050];
	while(~scanf("%d",&n)){
		if(n<0)break;
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&value[i],&num[i]);
			sum=sum+value[i]*num[i];
		}
		int ave;
		ave=sum/2;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=num[i];j++){
				for(int k=ave;k>=value[i];k--)
					dp[k]=max(dp[k-value[i]]+value[i],dp[k]);
			}
		}
		printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);

	}

}