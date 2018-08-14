#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n;
	int a[10000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l,r,x,N;
	cin>>N;
	for(int j=0;j<N;j++){
		cin>>l>>r>>x;
		int sum=0;
		for(int i=l;i<=r;i++){
			sum+=abs(a[i]-x);
		}
		cout<<sum<<endl;
	}
}
