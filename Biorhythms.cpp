#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int i=0;
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)&&a!=-1){
		while(a>23)
			a-=23;
		while(1){
			if(a>d&&(a-b)%28==0&&(a-c)%33==0){
				break;
			}
			a+=23;
		}
		i++;
		printf("Case %d: the next triple peak occurs in %d days.\n",i,(a-d));
	}
	
} 
