#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
float v;
int N;
struct bank{
	int qian;
	float caught;
}a[120];


float dp[15000];

int main(){
	int test;
	int sum;
	cin>>test;
	while(test--){
		scanf("%f %d",&v,&N);
		v=1-v;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		sum=0;
		for(int i=0;i<N;i++){
			scanf("%d%f",&a[i].qian,&a[i].caught);
			a[i].caught=1.0-a[i].caught;
			sum+=a[i].qian;
		}
		for(int i=0;i<N;i++){
			for(int j=sum;j>=a[i].qian;j--){
				dp[j]=max(dp[j],dp[j-a[i].qian]*a[i].caught);
			}
		}

		for(int j=sum;j>=0;j--){
			if(dp[j]>=v){
				printf("%d\n",j);
				break;
			}
		}

	}
}