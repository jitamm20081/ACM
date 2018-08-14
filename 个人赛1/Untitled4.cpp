#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m&&n+m>0){
		int a[105],b[105];
		int c[105];
		memset(c,0,sizeof(c));
		int p=n;
		int i,j;
		int k=0;
		for(i=0;i<n;i++)
			cin>>a[i];
		
		sort(a,a+n);
		for(j=0;j<m;j++)
			cin>>b[j];
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
			{
				if(a[i]==b[j])
				{
					c[i]=a[i];
				
				}
			}
		} 
		for(i=0;i<n;i++){
			if(a[i]==c[i]&&c[i]){
				p--;
			} 
				
			else
			{
				
				cout<<a[i]<<" ";
				
			}	

		} 
		if(p==0)
			cout<<"NULL"<<endl;
		else 
			cout<<endl;
		
	}
	
}
