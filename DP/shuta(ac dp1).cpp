#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[150][150];
int high;
int a[150][150];
int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>high;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=high;i++){
			for(int j=1;j<=i;j++){
				cin>>a[i][j];
			}
		}
		int max1=0;
		for(int i=1;i<=high;i++){
			for(int j=1;j<=i;j++){
					dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);	

					}
				
		}

		for(int i=1;i<=high;i++){
			max1=max(max1,dp[high][i]);
		}
		cout<<max1<<endl;
	}
}