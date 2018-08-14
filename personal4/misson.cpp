#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

struct cas{
	int a,b;
}cos1[10010];

bool cmp(cas m,cas n){
	if(m.a-m.b!=n.a-n.b)return m.a-m.b>n.a-n.b;
	return m.b>n.b;
}

int main(){
	int test;
	while(cin>>test&&test){
		for(int i=0;i<test;i++){
			scanf("%d%d",&cos1[i].a,&cos1[i].b);
		}

		int last=0;
		int ans=0;
		sort(cos1,cos1+test,cmp);
		for(int i=0;i<test;i++){
			if(cos1[i].a>last){
				ans+=cos1[i].a-last;
				last=cos1[i].a;
			}
			else ;
			cout<<last<<"a"<<endl;
			if(cos1[i].b>last){
				ans+=cos1[i].b-last;
				last=0;
			}
			else {
				last-=cos1[i].b;
			}
			cout<<last<<"b"<<endl;
	
		}
		cout<<ans<<endl;
	}

}
