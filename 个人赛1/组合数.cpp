#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
	int n,m,i,j,k;
	while(cin>>n>>m){
	   long long sum1=1,sum2=1,sum3=1;
	   if(n-m>m){
	   		m=n-m;
	   }
	   	for(int i=m+1;i<=n;i++)
	   		sum1*=i;
	   	for(int j=1;j<=n-m;j++)
	   		sum1/=j;
		cout<<sum1<<endl;				
	}
	

	
}
