#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
} 

int main(){
	int test;
	int m,n;
	cin>>test;
	while(test--){
		cin>>m>>n;
		int c=2*n;
		while(gcd(m,c)!=n)
		c+=n;
		printf("%d\n",c); 
	}
	
}
