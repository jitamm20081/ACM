#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[10010];
int dp[10010];

int jisuan(int dp[]){
	dp[0]=1;
	int max1=0;
	int len =strlen(a);
	for(int i=0;i<len;i++){
		for(int j=0;j<i;j++){
			if(a[j]<a[i]&&dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>=max1){
			max1=dp[i];
		}		
	}

	return max1;
}



int main(){
	int times;
	cin>>times;
	while(times--){
		int max1;
		scanf("%s",a);
		memset(dp,0,sizeof(dp));
		max1=jisuan(dp);
		cout<<max1<<endl;
	}
}