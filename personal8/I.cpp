#include<iostream>
#include<cmath>
using namespace std;
int sum[1000010];
int n,m;
int main(){
	int count;
	int p;
	for(int i=1;i<=1000000;i++){
		count=0;
		p=i;
		while(p!=0){
			if(p%10==1)
				count++;
			p/=10;
		}
		sum[i]=sum[i-1]+count;
	}
	while(~scanf("%d%d",&n,&m)){
		if(n<m)swap(n,m);
		//cout<<(sum[n]-sum[m-1])<<endl;
		printf("%d\n",sum[n]-sum[m-1]);
	}


}