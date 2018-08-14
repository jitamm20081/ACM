#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long 
ll vis[100010];
ll n;

int main(){
	ll dp[100005];
	dp[0]=1;
	vis[1]=1;
	while(cin>>n){
		for(ll i=2;i<=sqrt(n);i++){
			if(vis[i]==0)
			for(ll j=i*i;j<=n;j+=i){
				vis[j]=1;
			}
		}

		for(ll i=2;i<=n;i++){
			if(vis[i]==0)
			for(ll j=i;j<=n;j++){
					dp[j]+=dp[j-i];
			}
		}
		cout<<dp[n]<<endl;
	}

}