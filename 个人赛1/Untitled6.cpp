#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
	int n,m,i,j,k;
	while(cin>>n>>m){
	   	unsigned long long sum1=1,sum2=1,sum3=1;
	   	for(int i=1;i<=n;i++)
	   		sum1*=i;
	   	for(int j=1;j<=m;j++)
	   		sum2*=j;
	   	for(int k=1;k<=n-m;k++)
			sum3*=k;
		cout<<sum1/(sum2*sum3)<<endl;;					
	}
	

	
}
