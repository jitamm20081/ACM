#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1050];
char b[1050];
int dp[1050][1050];
int main(){
	while(~scanf("%s%s",a,b)){
		int len = strlen(a);
		int len1= strlen(b);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++){
			for(int j=0;j<=len1;j++){
				if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
		printf("%d\n",dp[len][len1]);
	}
}