#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
int b[8];
char jieguo[8];
int index2=0;
int index1=0;
void change(char a[]){
	int len=strlen(a);
	for(int i=0;i<len;i++){
		switch(a[i]){
			case'A':b[index2]=10;break;
			case'B':b[index2]=11;break;
			case'C':b[index2]=12;break;
			case'D':b[index2]=13;break;
			case'E':b[index2]=14;break;
			case'F':b[index2]=15;break;
			default:b[index2]=a[i]-'0';break;
		}
		index2++;
	}
}

void changeback(int c[],int k){
	int i;
	
	for(i=0;i<k;i++){
		switch(c[i]){
			case 10:jieguo[index1]='A';break;
			case 11:jieguo[index1]='B';break;
			case 12:jieguo[index1]='C';break;
			case 13:jieguo[index1]='D';break;
			case 14:jieguo[index1]='E';break;
			case 15:jieguo[index1]='F';break;
			default:jieguo[index1]=c[i]+'0';break;
		}
		index1++;
	}
}

int main(){
	char a[8];
	int c[100];
	int m,n;
	while(~scanf("%s %d %d",a,&m,&n)){
		memset(c,0,sizeof(c));
		int len=strlen(a);
		change(a);
		int i,j;
		int sum=0;
		for(i=len-1;i>=0;i--){
			int e=b[len-1-i];
			int j=i;
			while(j>0){
				e*=m;
				j--;
			}
		//	cout<<e;
			sum+=e;
		}
		int r,k=0;
		//cout<<sum;
		while(sum){
			r=sum%n;
			sum=sum/n;
			c[k++]=r;
		}
		if(k>7){
			 cout<<"  ERROR"<<endl;
			 index2=0;
			 index1=0;
			 continue;
		}
		int h;
		h=7-k;
		while(h>0){
			cout<<" ";
			h--;
		}
		changeback(c,k);
		for(i=k-1;i>=0;i--){
			cout<<jieguo[i];
		}
		cout<<endl;
		index2=0;
		index1=0;
	}
}
