#include<iostream>
#include<cstdio>
using namespace std;
int L;
int n;
int a[10005];
int main(){
	int min1=0;
	int max1=0;
	cin>>L;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		max1=max(max1,max(a[i],L-a[i]+1));
		min1=max(min1,min(a[i],L-a[i]+1));
	}
	cout<<min1<<" "<<max1<<endl;
}