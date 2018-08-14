#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	int a[100200];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		int l,r;
		int i;
		cin>>l>>r;
	/*	int b[100200];
		int k=l;
		for(i=1;i<=r-l+1;i++){
			b[i]=a[k];
			k++;
		}
		sort(&b[1],&b[i]);
		int un=1;
		int dif=b[1];*/
    	int num=0;
		for(i=1;i<=r-l+1;i++){
			for(int k=i+1;k<=r-l+1;k++){
				if(a[i]==a[k])
					num++;		
			}
		}
		cout<<r-l+1-num<<endl;	
	}
}
