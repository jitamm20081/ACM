#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[100],visited[100];
int lastnumber,L,n;
bool cmp(int a,int b){
	return a>b;
}


bool dfs(int m,int l){
	if(m==0&&l==0){
		return true;
	}
	if(l==0)l=L;
	int s=1; 
	if(L!=l){
		s=lastnumber+1;
	}
	for(int i=s;i<=n;i++){
		if(!visited[i-1]&&i>1&&a[i-1]==a[i])continue;
		if(!visited[i]&&a[i]<=l){
			visited[i]=1;
			lastnumber=i;
			if(dfs(m-1,l-a[i]))return true;
			else{
				visited[i]=0;
				if(L==l||a[i]==l){
					return false;
				}
			}
		}
		
	}
	return false;
}


int main()
{
	while(cin>>n&&n!=0){
		int total=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			total+=a[i];
		}	
		sort(a+1,a+n+1,cmp);
		memset(visited,0,sizeof(visited));
		int j;
		for(j=a[1];j<=total/2;j++){
			if(total%j)continue;
		//	lastnumber=0;
			L=j;
			if(dfs(n,j)){
				printf("%d\n",j);
				break;
			}
				
		}
		if(j>total/2){
			printf("%d\n",total);
		}
	}
	
 } 
