#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

int dp[1010][1010];
int a[1010][1010];
int n;
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n+5;j++){
				dp[i][j]=1000000;
			}
		}

		int max1=1000000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				//cout<<a[i][j];
				dp[i][j]=min(a[i][j]+dp[i-1][j-1],a[i][j]+dp[i-1][j]);
				//cout<<dp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			max1=min(max1,dp[n][i]);
			//cout<<dp[n][i]<<" ";
		}
		cout<<max1<<endl;

	}
}