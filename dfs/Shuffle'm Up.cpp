#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;
char s1[105],s2[105],s12[250];
char a[105],b[105],c[250];
int N,flag=0;
int length;
void xipai(){
	for(int i=0,j=0;j<length;j++,i+=2){
		c[i]=b[j];
		c[i+1]=a[j];
	}
}

void fapai(){
	for(int i=0;i<length;i++){
		a[i]=c[i];
	}
	
	for(int i=length,j=0;i<length*2;i++,j++){
		b[j]=c[i];
	}
}

int main(){
	cin>>N;
	int i;

	for(i=1;i<=N;i++){
		int cnt=0;
		scanf("%d",&length);
		scanf("%s%s%s",s1,s2,s12);
		strcpy(a,s1);
		strcpy(b,s2);
		strcpy(c,s12);
		flag=0;
		while(1){
			xipai();
			cnt++;
			if(strcmp(s12,c)==0)
			{
				flag=1;
				break;
			}
			fapai();
			if(strcmp(b,s2)==0&&strcmp(a,s1)==0)
				break;
		}
		if(flag==1)
			printf("%d %d\n",i,cnt);
		else 
			printf("%d %d\n",i,-1);
	}
}
