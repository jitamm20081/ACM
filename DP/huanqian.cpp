#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int  dp[32800];
int n;
int main(){
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=3;i++){
			for(int j=i;j<=n;j++){
				dp[j]+=dp[j-i];
			}
		}
		cout<<dp[n]<<endl;
	}

}