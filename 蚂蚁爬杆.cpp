#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int INF=10000000;
int min1=-1,max1=0;
int main(){
	int a[100050];
	int c[100050];
	int l;
	int n;
	cin>>l;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]>max1){
			max1=a[i];
		}
		if(l-a[i]>max1){
			max1=l-a[i];
		}
	}
	
	for(int i=0;i<n;i++){
		if(a[i]<=l-a[i])
			c[i]=a[i];
		else 
			c[i]=l-a[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]>min1)
			min1=c[i];
	}
	
	cout<<"min="<<min1<<endl;
	cout<<"max="<<max1<<endl;
	
}
