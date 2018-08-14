#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long san[45]={1},ans[5][33],A,B,C;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	long long  n,m;
	long long now;
	for(int i=1;i<=39;i++){
		san[i]=san[i-1]*3;
	}
	while(cin>>n>>m){
		A=0,B=0,C=0;
		m+=1;

		for(int i=n;i>=1;i--){
			if(i==n){
				now=(m-1)/san[i-1]+1;
				switch(now){
					case 1:ans[1][++A]=i;break;
					case 2:ans[2][++B]=i;break;
					case 3:ans[3][++C]=i;
				}
			}
			else {
				now=m-m/(san[i]*2)*(san[i]*2);
				if(now==0)
					now=6;
				else{
					now=(now-1)/san[i-1]+1;
				}
				switch(now){
					case 1:ans[1][++A]=i;break;
					case 2:ans[2][++B]=i;break;
					case 3:ans[3][++C]=i;break;
					case 4:ans[3][++C]=i;break;
					case 5:ans[2][++B]=i;break;
					case 6:ans[1][++A]=i;
				}
			}
		}
			if(A==0)ans[1][++A]=0;
			if(B==0)ans[2][++B]=0;
			if(C==0)ans[3][++C]=0;
			sort(ans[1]+1,ans[1]+A+1);
			sort(ans[2]+1,ans[2]+B+1);
			sort(ans[3]+1,ans[3]+C+1);			

			printf("%lld",ans[1][A]);
			for(int i=A-1;i>=1;i--){
				printf(" %lld",ans[1][i]);
			}
			printf("\n");


			printf("%lld",ans[2][B]);
			for(int i=B-1;i>=1;i--){
				printf(" %lld",ans[2][i]);
			}
			printf("\n");
			printf("%lld",ans[3][C]);
			for(int i=C-1;i>=1;i--){
				printf(" %lld",ans[3][i]);
			}
			printf("\n");
	}

}