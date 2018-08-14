#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
int n;
using namespace std;
int prime[1000000];
int  makeprime(){
	prime[0]=2;
	prime[1]=3;
	prime[2]=5;
	prime[3]=7;
	prime[4]=11;
	prime[5]=13;
	prime[6]=17;
	prime[7]=19;
	prime[8]=23;
	int i=9,m=29,j,sqrtn;
	while(m<n){
		sqrtn=sqrt(m);
		j=0;
		while(prime[j]<=sqrtn){
			if(m%prime[j]==0)break;
			j++;
		}
		if(prime[j]>sqrtn){
			prime[i]=m;
			i++;
		}
		m+=2;
	}
	return i;
}

int main(){
	cin>>n;
	int j;
	j=makeprime();
	for(int k=0;k<j;k++)
		cout<<prime[k]<<endl;
}
