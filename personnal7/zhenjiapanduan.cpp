#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,k;
int bin[50050];
int main(){
	cin>>n>>k;
	int a,b,c;
	int count=0;
	for(int i=0;i<k;i++){
		cin>>a>>b>>c;
		if(a==2&&b==c){
			count++;
			continue;
		}
		if(b>a||c>a)
		{
			count++;
			continue;
		}
		if(a==1)
		{
			if(bin[b]==0){
				bin[c]=b;
				bin[b]=c;
				continue;
			}
		}
		if(a==2){
			if(bin[b]==c&&bin[c]==b)
			{
				count++;
				continue;
			}
			if(bin[c]==b){
				count++;
				continue;
			}
			bin[b]=c;
		}
	}
	cout<<count<<endl;
}