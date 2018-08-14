#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long  dp[3500];
int a[20];
int main(){
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=15;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int t;
	long long x;
	cin>>t;

	while(t--){
		cin>>x;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int  i=1;i<=15;i++){
			for(int j=a[i];j<=x;j++){
				dp[j]+=dp[j-a[i]];
			}
		}
		printf("%lld\n",dp[x]%1000000009);	}
}