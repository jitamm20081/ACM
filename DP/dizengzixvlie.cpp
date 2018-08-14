#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1010];
int a[1010];
int n;
int main(){
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int max1=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(a[j]<a[i])dp[i]=max(dp[j]+1,dp[i]);
			}
			max1=max(max1,dp[i]);
		}
		cout<<max1<<endl;
	}
}