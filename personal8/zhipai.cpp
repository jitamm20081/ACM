#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[150];
int sum=0;
int count;
int main(){
	while(cin>>n){
		count=0;
		int avr;
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		avr=sum/n;
		for(int i=0;i<n;i++){
			if(a[i]>avr){
				a[i+1]+=(a[i]-avr);
				count++;
			}
			else if(a[i]<avr){
				a[i+1]-=(avr-a[i]);
				count++;
			}
			else ;
		}
		cout<<count<<endl;


	}
}