#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[10000];
int len;
double count=0;
double changshu=0;
double jieguo;
int denghao=0;
int main(){
	while(~scanf("%s",a)){
		len=strlen(a);
		changshu=0;
		count=0;
		for(int i=0;i<len;i++){
			if(a[i]=='=')
			{
				denghao=i;
			}
		}
		for(int i=0;i<denghao;i++){
			if(a[i]>='a'&&a[i]<='z'){
				if(i==0){
					count++;
					continue;
				}
				if(a[i-1]=='-')
						count--;
				if(a[i-1]=='+'||a[i-1]=='='){
					
					
						count++;
				}
				if(a[i-1]>='1'&&a[i-1]<='9')
					{
						int p=i-1;
						int num=0;
						while(a[p]>='1'&&a[p]<='9'){
							int g=a[p];
							for(int k=i-1-p;k>=0;k--){
								g=g*10;								
							}
							num+=g;
							p--;

						}
						cout<<num<<"op"<<endl;
						if(a[p]!='-')count+=num;
						else count-=num;

					}
			}
		}
		//cout<<count<<"ddd"<<endl;
		for(int i=denghao+1;i<len;i++){
			if(a[i]>='a'&&a[i]<='z'){
				if(i==denghao+1){
					count--;
					continue;
				}
				if(a[i-1]=='+'||a[i-1]=='='){

					count--;
				}
				if(a[i-1]=='-')
						count++;
				if(a[i-1]>='1'&&a[i-1]<='9')
					{
						int p=i-1;
						int num=0;
						while(a[p]>='1'&&a[p]<='9'){
							int g=a[p];
							for(int k=i-1-p;k>=0;k--){
								g=g*10;								
							}
							num+=g;
							p--;

						}
						if(a[p]!='-')count-=num;
						else count+=num;
					}
			}
		}

cout<<count<<"ddd"<<endl;
		for(int i=0;i<denghao;i++){
				if(a[i]>='1'&&a[i]<='9'){
					if(a[i+1]<'a'||a[i+1]>'z'){
						if(i==denghao-1){
							if(a[i-1]=='-')
								changshu+=(a[i]-'0');
							else 
								changshu-=(a[i]-'0');

							continue;
						}
						if(i==0){
							changshu-=(a[i]-'0');
							break;
						}
						if(a[i-1]=='-'){
							changshu+=(a[i]-'0');
						}
						else if(a[i-1]=='+'){
							changshu-=(a[i]-'0');
						}
					
					}

				}
		}
		cout<<changshu<<"dd"<<endl;
		for(int i=denghao+1;i<len;i++){
				if(a[i]>='1'&&a[i]<='9'){
					if((a[i+1]<'a'||a[i+1]>'z')){
						if(i==len-1){
							if(a[i-1]=='-')
								changshu-=(a[i]-'0');
							else 
								changshu+=(a[i]-'0');

							continue;
						}
						if(i==denghao+1){
							changshu+=(a[i]-'0');
							//cout<<changshu<<endl;
							continue;
						}
						if(a[i-1]=='-'){
							//cout<<"ddd";
							changshu-=(a[i]-'0');
						}
						if(a[i-1]=='+'){
							changshu+=(a[i]-'0');
						}
						if(a[i-1]=='='){
							changshu+=(a[i]-'0');
						}						
					}

				}
		}


		
		//cout<<changshu<<" "<<count<<endl;
		if(changshu==0)cout<<"0.000"<<endl;
		else {
			jieguo=changshu*1.0/count;
		printf("%.3f\n",jieguo*1.0);}
	}
}