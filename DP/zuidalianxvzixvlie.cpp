#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int dp[10010];
int a[10010];
int n;
int main(){
	while(cin>>n){
		if(n==0)break;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			dp[i]=a[i];
		}
		int ans=-1000000;
		for(int i=1;i<=n;i++){
						dp[i]=max(dp[i-1]+a[i],dp[i]);
						ans=max(ans,dp[i]);
		}
		int q=0,p=0,flag=0;
		//cout<<ans<<"ss"<<endl;
		for(int i=1;i<=n;i++){
			if(flag==1)break;
			if(dp[i]==ans){
					//cout<<ans<<"ssss"<<i<<endl;
					p=i;
					//cout<<p<<"e"<<endl;
					flag=1;
				int sum=0;
				for(int j=p;j>=1;j--){
					//cout<<j<<"eded"<<endl;
					sum+=a[j];
					if(sum==ans)
					{
						
						q=j;
					//	cout<<q<<"ddd"<<endl;
						break;
					}

				}
			}
		}

			if(ans<0)cout<<"0"<<" "<<a[1]<<" "<<a[n]<<endl;
			else cout<<ans<<" "<<a[q]<<" "<<a[p]<<endl;
		
	}
}