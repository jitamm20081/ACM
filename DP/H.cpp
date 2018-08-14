#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[100000];
	while(~scanf("%s",s)){
		int len=strlen(s);
		int flag1=0;
		int flag2=0;
		int flag3=0;

		for(int i=0;i<len;i++){
			if(s[i]=='1')
				flag1=1;
			if(s[i]=='0')
				flag2=1;
			if(s[i]=='1'&&s[i-1]=='0')
				flag3=1;
		}
		
		if(flag1==0){
			printf("1\n");
			continue;}
		if(flag2==0){
			printf("0\n");
			continue;
		}
		if(flag3==0){
			printf("2\n");
		}
		else {
			printf("%d\n",len);
		}
	}
	
}