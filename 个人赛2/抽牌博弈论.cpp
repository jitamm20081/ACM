#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	int n ;
	while(cin>>n){
		if(n==0)break;
		if(n>=3)printf("Bob\n");
		else printf("Alice\n");
	}
	
} 
