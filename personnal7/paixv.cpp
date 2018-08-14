#include<iostream>
#include<algorithm>
using namespace std;

struct tongxue{
	char s[30];
	int y,m,d,n;
};

bool cmp(tongxue a,tongxue b){
	if(a.y!=b.y)return a.y<b.y;
	else {
		if(a.m!=b.m)return a.m<b.m;
		else{
			if(a.d!=b.d)return a.d<b.d;
			else return a.n>b.n;
			//else return b.d>a.d;
		}
		//else return b.m>a.m;
	}
	//else return b.y>a.y;
}


int main(){
	tongxue a[300];
	int test;
	cin>>test;
		for(int i=0;i<test;i++){
			scanf("%s%d%d%d",a[i].s,&a[i].y,&a[i].m,&a[i].d);
			a[i].n=i;
		}
		sort(a,a+test,cmp);
		for(int i=0;i<test;i++){
			printf("%s\n",a[i].s);
		}		
	


}