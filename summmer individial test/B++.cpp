#include<iostream>
#include<cstring>
using namespace std;

char a[10000];
int len;
int count,num1,num2;
int changshu=0;
int dengyu;

bool isdigit(char a){
	if(a>='0'&&a<='9')
		return true;
	return false;
}


bool iszimu(char a){
	if(a>='a'&&a<='z')
		return true;
	return false;
}

char zifu;
int main(){
	while(~scanf("%s",a)){
		changshu=0;
		count=0;
		len=strlen(a);
		for(int i=0;i<strlen(a);i++){
			if(a[i]=='=')
				dengyu=i;
			if(iszimu(a[i]))
				zifu=a[i];
		}

		for(int i=0;i<dengyu;i++){
			if(isdigit(a[i])){
				num2=i;
				num1=0;
				while(isdigit(a[i])){
					num1=num1*10+a[i]-'0';
					i++;
				}
				if(iszimu(a[i])){
					if(a[num2-1]=='\0'||a[num2-1]=='+')
						count+=num1;
					if(a[num2-1]=='-')
						count-=num1;
				}
				else {
					if(a[num2-1]=='\0'||a[num2-1]=='+')
						changshu+=num1;
					if(a[num2-1]=='-')
						changshu-=num1;
				}
				continue;
			}
			if(iszimu(a[i])){
					if(a[i-1]=='\0'||a[i-1]=='+')
						count++;
					if(a[i-1]=='-')
						count--;
			}
		}
		//cout<<count<<"dd"<<changshu<<endl;
		changshu-=2*changshu;
		for(int i=dengyu+1;i<len;i++){
			if(isdigit(a[i])){
				num2=i;
				num1=0;
				while(isdigit(a[i])){
					num1=num1*10+a[i]-'0';
					i++;
				}
				if(iszimu(a[i])){
					if(a[num2-1]=='='||a[num2-1]=='+')
						count-=num1;
					if(a[num2-1]=='-')
						count+=num1;
				}
				else {
					if(a[num2-1]=='='||a[num2-1]=='+')
						changshu+=num1;
					if(a[num2-1]=='-')
						changshu-=num1;
				}
				continue;
			}
			if(iszimu(a[i])){
					if(a[i-1]=='='||a[i-1]=='+')
						count--;
					if(a[i-1]=='-')
						count++;
			}
		}		
		//cout<<count<<"dd"<<changshu<<endl;
		if(changshu==0){
					printf("%c=0.000\n",zifu);
							}
		else 
			printf("%c=%.3f\n",zifu,changshu*1.0/count);
	}
}