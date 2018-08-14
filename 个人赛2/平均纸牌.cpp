#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	int ans,aver,n;
	int a[150];
	int sum;
	while(cin>>n){
		sum=0;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		cout<<sum<<endl; 
		aver=sum/n;
		for(int i=0;i<n;i++){
			if(a[i]>aver){
				a[i+1]+=(a[i]-aver);
				ans++;
			}
			else if(a[i]<aver){
				a[i+1]-=(aver-a[i]);
				ans++;
			}
		}
			cout<<ans<<endl;
	}

	
}
