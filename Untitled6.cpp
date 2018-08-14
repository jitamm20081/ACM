#include<cstdio>
#include<iostream>
using namespace std;
bool p[10000006];
int main(){
	int i,j;
	int n;
	while(~scanf("%d",&n)){
		for(i=2;i<=n;i++){		
			if(!p[i]){
				printf("%d\n",i);
				if((long long)i*i>n)
					continue;
				for(int j=i*i;j<=n;j+=i){
					p[j]=true;
				}
			}
		}
		
	}
	
}
