#include<iostream>
#include<cstdio>
using namespace std;

int vis[20];
int n;
int a[20];
void dfs(int a[],int k){
	if(k==n){
		for(int j=0;j<=n-1;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
		k=0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[k]=i;
			dfs(a,k+1);
			vis[i]=0;			
		}

	}
}


int main(){
	while(cin>>n){
		dfs(a,0);
	}
}
