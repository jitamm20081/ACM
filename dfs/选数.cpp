#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int visited[500005];
int a[500005];
int c[500005];
int add1[500005];
int k=0;
bool judge(int q){
	int i;
	for(int i=2;i<=sqrt(q);i++){
		if(q%i==0)
			return false;
	}
	return true;
}

int add(int a[]){
	int p=0;
	for(int i=0;i<m;i++)
	{
		p+=a[i];
	}
	return p;
}


int dfs(int str,int start,int end,int last){
	/*if(str==m){
		for(int j=0;j<m;j++)
			cout<<c[j]<<" ";
		cout<<endl;
		if(judge(add(c))){
			int flag=0;
			for(int j=0;j<k;j++){
				if(add(c)==add1[j])
					flag=1;
			}
		//	cout<<flag<<endl;
			if(flag==0){
					add1[k]=add(c);
				//	cout<<add1[k];
					k++;
				//	cout<<k<<endl;
					sum++;
					return;
			}

		//	cout<<sum<<endl;

		}
	}*/
	if(str==0){
			return judge(last);
	}
	int sum=0;
	for(int i=start;i<=end;i++){
			sum+=dfs(str-1,i+1,end,last+a[i]);
		}
	return sum;
}

int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}	
		cout<<dfs(m,0,n-1,0)<<endl;
	}
} 
