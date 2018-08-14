#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int test;
	int n;
	cin>>test;
	while(test--){
		int a[100010];
		cin>>n;

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int x=a[0];
		for(int i=1;i<n;i++){
			x^=a[i];
		}
		if(x==0)printf("PB\n");
		else printf("PA\n");
	}
}