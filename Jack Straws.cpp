#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int pre[25];

struct Straw{
	int x1,y1,x2,y2;
	void read(){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	}
	
}s[20];

void initial(int n){
	for(int i=1;i<=n;i++)
		pre[i]=i;
}

int cross(int x1,int x2,int y1,int y2){
	return x1*y2-x2*y1;
} 

int find(int x){
	return x==pre[x] ? x:pre[x]=find(pre[x]);
}

int Xiangjiao(Straw A,Straw B){
	int c[4];
	if(max(A.x1,A.x2)<min(B.x1,B.x2)||max(B.x1,B.x2)<min(A.x1,A.x2)||max(A.y1,A.y2)<min(B.y1,B.y2)||max(B.y1,B.y2)<min(A.y1,A.y2)) return 0;//快速排斥 判断共线且不相交的情况
	c[0]=cross(B.x1-A.x1,A.x2-A.x1,B.y1-A.y1,A.y2-A.y1);
	c[1]=cross(B.x2-A.x1,A.x2-A.x1,B.y2-A.y1,A.y2-A.y1);	
	c[2]=cross(A.x1-B.x1,B.x2-B.x1,A.y1-B.y1,B.y2-B.y1);	 
	c[3]=cross(A.x2-B.x1,B.x2-B.x1,A.y2-B.y1,B.y2-B.y1);
	if(c[0]*c[1]<=0&&c[2]*c[3]<=0)return 1;	
	return 0;
}

int main(){
	int n;
	int i,j;
	while(~scanf("%d",&n)&&n){
		for(i=1;i<=n;i++){
			s[i].read();	
		}
		initial(n);
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(Xiangjiao(s[i],s[j]))
				{
					int c=find(i);
					int d=find(j);
					if(c !=d)
						pre[c]=d;
				}
			}
		}
		int a,b;
		while(~scanf("%d%d",&a,&b),a|b){
			if(find(a)==find(b))
				cout<<"CONNECTED "<<endl;
			else
				cout<<"NOT CONNECTED "<<endl;
		}
		
	}
	
	return 0;
} 
