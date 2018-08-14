#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int a,b;
}p[800];

int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		int i,j,k;
		int ans=0,cnt;
		for(i=0;i<n;i++){
			cin>>p[i].a>>p[i].b;
		}
		
		for(i=0;i<n;i++){

			for(j=i+1;j<n;j++){
							cnt=2;
				for(k=j+1;k<n;k++){
					
					if((p[k].b-p[j].b)*(p[j].b-p[i].b)==(p[k].a-p[j].a)*(p[j].a-p[i].a))
						cnt++;
					if(cnt>ans)ans=cnt;
				}
			}
		}
		cout<<ans<<endl;
	}
	

}
