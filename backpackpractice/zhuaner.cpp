#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n;	
	int k=0;
	while(cin>>n){
		int a[10000];
		k=0;
		while(n!=0){
			a[k]=n%2;
			n/=2;
			k++;
		}
		for(int i=k-1;i>=0;i--){
			cout<<a[i];
		}		
		cout<<endl;
	}

}