#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int dp[400400];
int n,m;
struct data{
	int dian;
	int num;
}a[100100];
void zeropack(int val){
	for(int i=m;i>=val;i--){
		dp[i]=max(dp[i],dp[i-val]+val);
	}
}

void completepack(int val){
	for(int i=val;i<=m;i++){
		dp[i]=max(dp[i],dp[i-val]+val);
	}
}


void multiplepack(int val,int cost,int amount){
	if(val*amount>m)completepack(val);
	else {
		int k=1;
		while(k<=amount){
			zeropack(k*val);
			amount-=k;
			k<<=1;
		}
		zeropack(amount*val);
	}

}


int main(){
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		if(n==0&&m==0)break;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].dian);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].num);
		}
		for(int i=0;i<n;i++){
			multiplepack(a[i].dian,a[i].dian,a[i].num);
		}
		int count=0;
		for(int i=1;i<=m;i++){
			if(dp[i]==i)
				count++;
		}
		cout<<count<<endl;
	}
}


