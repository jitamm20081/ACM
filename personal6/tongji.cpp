#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	long long  n,m;
	while(cin>>n>>m){
		long long sum=n*m;
		long long  num =((n+1)*(m+1)*(m*n)/4);
		while(n--&&m--){
			sum+=n*m;
		}

		cout<<sum<<" "<<num-sum<<endl;
	}

}