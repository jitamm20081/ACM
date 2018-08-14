#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int a[2000];
int dp[2300][2001];
int main(){
	while(cin>>n>>k){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i/2;j++){
				if(i==2*j)dp[i][j]=dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);//如果i==2j，则说明前i个全部取走了
				else dp[i][j]=min(dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]),dp[i-1][j]);//如果第i个取走，则第i-1个也取走，
			}
		}
		cout<<dp[n][k]<<endl;
	}

}