#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,min1=0,sum=0,ans=-200000000;
	cin>>n;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		ans=max(ans,sum-min1);
		min1=min(min1,sum);
	}
	cout<<ans<<endl;
}