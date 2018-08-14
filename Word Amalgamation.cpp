#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char copy1[101][101],s[101][101];

struct mc{
	char st[101];
}num[101];

bool cmp(mc a,mc b){
	return strcmp(a.st,b.st)<0;

} 
int main(){
    int i,flag=0;
	char str[101];
	while(scanf("%s",s[flag])&&strcmp("XXXXXX",s[flag])){
		flag++;
	}
	for(i=0;i<flag;i++)
	{	
		strcpy(copy1[i],s[i]);
	}
	for(i=0;i<flag;i++)
	{	
		sort(copy1[i],copy1[i]+strlen(copy1[i])); 
	}
	for(i=0;i<flag;i++)
	{	
		printf("%s\n",copy1[i]);
	}
	while(scanf("%s",str)&&strcmp("XXXXXX",str)!=0){
			int sign=0,t=0;
			sort(str,str+strlen(str));
			for(i=0;i<flag;i++){
				if(strcmp(str,copy1[i])==0){
					sign=1;
					strcpy(num[t++].st,s[i]);
				}
			}
			if(!sign){
				printf("NOT A VALID WORD\n");
				printf("******\n");}
			else
				{
					sort(num,num+t,cmp);
					for(i=0;i<t;i++)
						printf("%s\n",num[i].st);
					printf("******\n");
				}
			
	}
	
}


