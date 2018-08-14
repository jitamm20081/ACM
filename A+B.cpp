#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main(){
	char a[100000];

	while(gets(a)){
			long long sum=0;
		int length=strlen(a);
		char brr[10];
		int index=0;
		for(int i=0;i<=length;i++){
			if(a[i]==' '||a[i]=='\0'){
				int k=0;
				for(int j=index;j<i;j++){
					brr[k]=a[j];
					k++;
				}
			/*	for(int h=0;h<k-1;h++){
					cout<<brr[h];
				}*/
				brr[k]='\0';
				index=i+1;
				sum+=atoi(brr);
			}
		}
		cout<<sum<<endl;
		
	}
	
}
