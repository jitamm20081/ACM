#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[25][3];
int n;
int vis[25];
int lu[25];

int ti;

void dfs(int i,int j,int step){
	if(step==21&&i==j){
		printf("%d: ",++ti);
		for(int i=1;i<=20;i++){
			cout<<" "<<lu[i];
		}
		printf(" %d",n);
		cout<<endl;
		//step=0;
	}
	if(step>21)return;
	if(vis[i]==1)return;
	if(step<21){
			vis[i]=1;
			lu[step]=i;
			dfs(a[i][0],n,step+1);
			dfs(a[i][1],n,step+1);
			dfs(a[i][2],n,step+1);
			vis[i]=0;			
	}
}
+


int main(int argc, char const *argv[])
{
	int step;
	for(int i=1;i<=20;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		int t;
		if(a[i][0]>a[i][1]){
			t=a[i][0];
			a[i][0]=a[i][1];
			a[i][1]=t;
		}
		if(a[i][1]>a[i][2]){
			t=a[i][1];
			a[i][1]=a[i][2];
			a[i][2]=t;
		}
		if(a[i][0]>a[i][2]){
			t=a[i][0];
			a[i][0]=a[i][2];
			a[i][2]=t;
		}		
	}

	while(cin>>n&&n!=0){
		memset(vis,0,sizeof(vis));
		ti=0;
		step=1;
		vis[n]=1;
		lu[1]=n;
		dfs(a[n][0],n,step+1);
		dfs(a[n][1],n,step+1);
		dfs(a[n][2],n,step+1);

	}
	return 0;

}