#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
const int pi=3.1415926535898;
const int e=2.718281828459;

using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		double n;
		cin>>n;
	double a=0;
		a=sqrt(2*pi*n)*pow(n/e,n);
	double b;
	   b=int(log10(a)/log10(8))+1;
		cout<<b<<endl;
	}
}
