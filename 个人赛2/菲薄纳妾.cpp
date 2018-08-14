#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){
	long long  F[100];
	int n;
	F[0]=1;
	F[1]=1;
	while(cin>>n){
		for(int i=2;i<n;i++){
			F[i]=F[i-1]+F[i-2];
		}
		int k=0;
		if(n<5){
			for(int i=0;i<n;i++){
				cout<<F[i]<<" ";
			}			
			cout<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				cout<<F[i]<<" ";
				k++;
				if(k%5==0)
				cout<<endl;
			}				
		}

	
	}

}
