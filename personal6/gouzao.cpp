#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
		int dp[1010][1010];
int main(){
	char a[1050];
	char ra[1050];
	while(~scanf("%s",a)){
		int k=0;
		int length=strlen(a);
		for(int i=length-1;i>=0;i--){
			ra[k]=a[i];
			k++;
		}


		memset(dp,0,sizeof(dp));
		for(int i=0;i<length;i++){
			for(int j=0;j<length;j++){
				if(a[i]==ra[j]){
					dp[i+1][j+1]=dp[i][j]+1;
				}
				else 
					dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
		cout<<length-dp[length][length]<<endl;
	}
}