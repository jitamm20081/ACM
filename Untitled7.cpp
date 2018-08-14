#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 705
#define mod 1000000007
char s[N];
int match[N];
int tmp[N];
int dp[N][N][3][3];

void match1(int length){
	int i;
	int p=0;
	for(i=0;i<length;i++){
		if(s[i]=='('){
			tmp[p++]=i;
		}
		else{
			match[i]=tmp[p-1];
			match[tmp[p-1]]=i;
			p--;
		}
	}
}

void dp1(int l,int r){
	if(l+1==r){
		dp[l][r][0][1]=1;
		dp[l][r][1][0]=1;
		dp[l][r][0][2]=1;
		dp[l][r][2][0]=1;
		return ;
	}
	if(match[l]==r){
		dp1(l+1,r-1);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=1){
					dp[l][r][1][0]=(dp[l][r][1][0]+dp[l+1][r-1][i][j])%mod;
				}
				if(j!=1){
					dp[l][r][0][1]=(dp[l][r][0][1]+dp[l+1][r-1][i][j])%mod;
				}
				if(i!=2){
					dp[l][r][2][0]=(dp[l][r][2][0]+dp[l+1][r-1][i][j])%mod;
				}
				if(j!=2){
					dp[l][r][0][2]=(dp[l][r][0][2]+dp[l+1][r-1][i][j])%mod;
				}
			}
		}	
		return ;
	}
	if(match[l]!=r){
		int p=match[l];
		dp1(l,p);
		dp1(p+1,r);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					for(int q=0;q<3;q++){
						if(!((k==1&&q==1)||(k==2&&q==2)))
						dp[l][r][i][j]=(dp[l][r][i][j]+(dp[l][p][i][k]*dp[p+1][r][q][j])%mod)%mod;
					}
				}
			}
		}
		return ;
	}
}


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long ans=0;
		scanf("%s",s);
		memset(dp,0,sizeof(dp));
		int length=strlen(s);
		match1(length);
		dp1(0,length-1);
		for(int k=0;k<3;k++){
			for(int h=0;h<3;h++){
				ans=(ans+dp[0][length-1][k][h])%mod;
			}
		}
		printf("%ld\n",ans);
	}
	
}
