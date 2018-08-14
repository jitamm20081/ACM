#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(){	
	long long result=0;
	long long  digit[65];
	long long temp;
	int n;
	memset(digit,0,sizeof(digit));
	scanf("%d",&n);
	while(~scanf("%lld",&temp)){
		for(int i=0;i<64;i++){
			digit[i]+=(temp>>i)&1;
		}		
	}

	for(int i=0;i<64;i++){
		result|=(digit[i]%n)<<i;
	}

	printf("%lld",result);

}