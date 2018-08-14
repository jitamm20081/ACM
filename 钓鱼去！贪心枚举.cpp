#include<cstring>
#include<iostream>
#include<cstdio> 
#define MAXN 26
using namespace std;
int F[MAXN],t[MAXN]={0},d[MAXN],ans[MAXN],ANS[MAXN],f[MAXN];

int main(){
/*	freopen("in.txt","r",stdin);*/
	int n,h;
	int j,k,p,time,max,sum=0,i;
	while(cin>>n>>h){
	h=h*12;
	for(i=0;i<n;i++)	cin>>F[i];
	for(i=0;i<n;i++)	cin>>d[i];
	for(i=1;i<n;i++){
		cin>>time;
		t[i]=t[i-1]+time;
	}//走到某一地点所需要的时间
	memset(ANS,0,sizeof(ANS));
	for(i=1,max=0;i<=n;i++){
		memset(ans,0,sizeof(ans));
		for(j=0;j<i;j++)
			f[j]=F[j];
		for(k=0,sum=0;k<h-t[i-1];k++){
			for(j=1,p=0;j<i;j++){
				if(f[j]>f[p]){
					p=j;
				}
			}
			if(f[p]<=0){
				ans[0]+=h-t[i-1]-k;
				break;
			}
			sum+=f[p];
			f[p]-=d[p];
			ans[p]++;

		}
		if(sum>max)
		{
			memcpy(ANS,ans,sizeof(ans));
			max=sum;
		}
		if(sum==max){
			for(j=0;j<i;j++)
			{
				if(ans[j]!=ANS[j])
					break;
			}
			if(ans[j]>ANS[j])
				memcpy(ANS,ans,sizeof(ans));
		}
		
	}
	
	for(i=0;i<n-1;i++)
		cout<<ANS[i]*5<<", ";
	cout<<ANS[n-1]*5<<endl;
	cout<<"Number of fish expected: "<<max<<endl<<endl;
	}
	return 0;
}
 
