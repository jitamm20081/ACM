#include<iostream>
#include<cmath>
using namespace std;
int n,a[1200];
int max1=0;

int cal(int x){
	int sum=0;
	int dp;
	for(int i=1;i<=n;i++){
		dp=0;
		for(int j=i;j<n+i;j+=x){
			//cout<<j<<" ";
			if(j==n)dp+=a[j];
			else dp+=a[j%n];
		}	
		//cout<<dp<<"d"<<endl;
		sum=max(sum,dp);	
	}


	
	return sum;
}


int main(){
	while(cin>>n){
		max1=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			max1+=a[i];
		}

		for(int i=2;i<=n;i++){
			if(n%i==0){
				if(n/i>=3){
					max1=max(max1,cal(i));
				}
			}
		}	
		cout<<max1<<endl;
	}
}