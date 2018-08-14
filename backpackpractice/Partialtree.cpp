#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF=100000000;
int dp[10050];
int f[10050];
int n;

int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>n;
		for(int i=0;i<n-1;i++){
			cin>>f[i];
		}
		
		for(int i=0;i<n;i++){
			dp[i]=-INF;
		}	

		for(int i=1;i<n;i++){
			f[i]=f[i]-f[0];
		}
		dp[0]=n*f[0];
		n=n-2;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j]=max(dp[j],dp[j-i]+f[i]);
			}
		}
		cout<<dp[n]<<endl;
	}
}