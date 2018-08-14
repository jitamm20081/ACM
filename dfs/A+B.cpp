#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool panduan(int q){
	int i;
	for(int i=2;i<=sqrt(q);i++){
		if(q%i==0)
			return false;
	}
	return true;
}
int main(){
	int dp[10010];
	memset(dp,0,sizeof(dp));
	int n;
	dp[0]=0;
	dp[1]=1;
	while(cin>>n){
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=0;j--){
					if(panduan(i-j)&&dp[j]+1>dp[i]){
						dp[i]=dp[j]+1;
					}
			}
		}
		cout<<dp[n]<<endl;
	}
}