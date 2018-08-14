#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int t;
	cin>>t;
	int i;
	for(i=0;i<t;i++){
		char a[500],b[500];
		int c[600];
		scanf("%s",a);
		scanf("%s",b);
		int lena=strlen(a),lenb=strlen(b);
		int cha=abs(lena-lenb);
		int length;
		memset(c,0,sizeof(c));
		
		if(lena>lenb){
			int jinwei=0;
			int k,h;
			length=lena;
			int m=length;                                                      
			char buqi[500];
			int r=0; 
			for(int u=0;u<cha;u++){
				buqi[u]='0';
			}
			for(int u=cha;u<length;u++){
				buqi[u]=b[r];
				r++;
			}

			for(k=length-1;k>=0;k--){
				if(a[k]-'0'+buqi[k]-'0'+jinwei>=10){
					c[m]=(a[k]-'0'+buqi[k]-'0'+jinwei)%10;
					m--;
					jinwei=1;
				}
				else
				{
					c[m]=(a[k]-'0'+buqi[k]-'0'+jinwei)%10;
					m--;
					jinwei=0;
				}		
			}
			if(jinwei==1)
				c[0]=1;
			if(c[0]==1){
				for(int o=0;o<length+1;o++)
					printf("%d",c[o]);				
			}
			else{
				for(int o=1;o<length+1;o++)
					printf("%d",c[o]);					
			}

			printf("\n");
		}
		if(lena==lenb){
			int jinwei=0;
			int k,h;
			length=lena;
			int m=length;
			for(k=length-1;k>=0;k--){
				if(a[k]-'0'+b[k]-'0'+jinwei>=10){	
					c[m]=(a[k]-'0'+b[k]-'0'+jinwei)%10;
					m--;
					jinwei=1;
				}
				else
				{
					c[m]=(a[k]-'0'+b[k]-'0'+jinwei)%10;
					m--;
					jinwei=0;
				}		
			}
			if(jinwei==1)
				c[0]=1;
				
			if(c[0]==1){
				for(int o=0;o<length+1;o++)
					printf("%d",c[o]);				
			}
			else{
				for(int o=1;o<length+1;o++)
					printf("%d",c[o]);					
			}

			printf("\n");
		}
		if(lena<lenb){
			int jinwei=0;
			int k,h;
			length=lenb;
			int m=length;
			char buqi[500];
			int r=0; 
			for(int u=0;u<cha;u++){
				buqi[u]='0';
			}
			for(int u=cha;u<length;u++){
				buqi[u]=a[r];
				r++;
			}
			for(k=length-1;k>=0;k--){
				if(buqi[k]-'0'+b[k]-'0'+jinwei>=10){
					c[m]=(buqi[k]-'0'+b[k]-'0'+jinwei)%10;
					m--;
					jinwei=1;
				}
				else
				{
					c[m]=(buqi[k]-'0'+b[k]-'0'+jinwei)%10;
					m--;
					jinwei=0;
				}		
			}
			if(jinwei==1)
				c[0]=1;
			if(c[0]==1){
				for(int o=0;o<length+1;o++)
					printf("%d",c[o]);				
			}
			else{
				for(int o=1;o<length+1;o++)
					printf("%d",c[o]);					
			}

			printf("\n");	
		}
	}
	
}
