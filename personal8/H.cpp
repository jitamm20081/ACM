#include<iostream>
#include<cstring>
using namespace std;

int num[100050];
char a[100050];

int main(){
	while(~scanf("%s",a+1)){
		int tot=0;
		int now=0;
		int flag=0;
		int length=strlen(a+1);
		for(int i=1;i<=length;i++)
			num[i]=a[i]-'0';
		if(num[1]==0)now=1;
		if(num[length]==0)tot++;
		for(int i=1;i<=length;i++){
			if(num[i]==0)flag=1;
			if(flag==1&&num[i]==1){
				flag=0;
				tot++;
			}
		}
		cout<<2*tot-now<<endl;
	}
}