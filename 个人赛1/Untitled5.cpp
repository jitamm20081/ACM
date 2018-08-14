#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int t,n;
	cin>>t;

	for(int h=0;h<t;h++){
		cin>>n;
		int a[10];
		int i;
		int p;
		for(i=1;i<n;i++){
			p=i;
			int q=p;
			int k=0;
			
			while(q)
			{
				
				a[k]=q%10;
				q=q/10;
				k++;
			}
			int sum1=0;
			for(int j=0;j<k;j++){
				sum1+=a[j];
			}
	
			if(p+sum1==n){
				cout<<p<<endl;
				break;
			}
							
		}
	  if(i==n)
	  	cout<<"0"<<endl;
		
	}
	
} 
