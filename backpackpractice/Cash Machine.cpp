#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

int n,N;
struct jinqian{
	int num;
	int value;
}a[15];

vector<int>value;
int dp[100000];
int main(){
	while(~scanf("%d",&n)){
		scanf("%d",&N);
		memset(dp,0,sizeof(dp));
		dp[0]=0;
		value.clear();
		for(int i=1;i<=N;i++){
			scanf("%d%d",&a[i].num,&a[i].value);
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=a[i].num;j<<=1){
				value.push_back(j*a[i].value);
				a[i].num-=j;
			}

			if(a[i].num>0){
				value.push_back(a[i].num*a[i].value);
			}
		}


		for(int i=0;i<value.size();i++){
			for(int j=n;j>=value[i];j--){
				dp[j]=max(dp[j-value[i]]+value[i],dp[j]);
			}
		}


		/*for(int i=n;i>=0;i--){
			if(dp[i]!=0){
				printf("%d\n",i);
				break;
			}
		}*/

		printf("%d\n",dp[n]);
	}

}