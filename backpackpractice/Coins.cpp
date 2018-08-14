#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

int dp[400300];
vector<int>vec;
int n,m;
struct qian{
	int dian;
	int num;
}a[100100];
int main(){
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		vec.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i].dian);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].num);
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=a[i].num;j<<=1){
				vec.push_back(j*a[i].dian);
				a[i].num-=j;
			}
			if(a[i].num>0){
				vec.push_back(a[i].num*a[i].dian);
			}
		}
		int count=0;
		for(int i=0;i<vec.size();i++){
			for(int j=m;j>=vec[i];j--){
				dp[j]+=dp[j-vec[i]];
				//printf("%d %d %d\n",j,j-vec[i],dp[j]);
			}
		}
		for(int i=1;i<=m;i++){
			//printf("***%d***\n",dp[i]);
			if(dp[i])
				count++;
		}
		cout<<count<<endl;
	}
}