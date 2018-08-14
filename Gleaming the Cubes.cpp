#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct data{
	int x1,y1,z1;
	int x2,y2,z2;
	data(){}
	data(int _x,int _y,int _z,int _d){
		x1=_x,y1=_y,z1=_z;
		x2=x1+_d;
		y2=y1+_d;
		z2=z1+_d;
	}
	data(int _x1,int _y1,int _z1,int _x2,int _y2,int _z2){
		x1=_x1;y1=_y1;z1=_z1;
		x2=_x2;y2=_y2;z2=_z2;
	}
	bool ok(){
		return x2>x1&&y2>y1&&z2>z1;
	}
	int volume(){
		return (x2-x1)*(y2-y1)*(z2-z1);
	}
	
}; 


data infer(data a,data b){
	if(a.ok())
		return data(max(a.x1,b.x1),max(a.y1,b.y1),max(a.z1,b.z1),min(a.x2,b.x2),min(a.y2,b.y2),min(a.z2,b.z2));
	else return data(0,0,0,-1);
}


int main(){
	int x,y,z,d;
	int n;
	int i;
	while(scanf("%d",&n)&&n){
		scanf("%d%d%d%d",&x,&y,&z,&d);
		data ans(x,y,z,d);
		for(i=1;i<n;i++){
			scanf("%d%d%d%d",&x,&y,&z,&d);
			ans=infer(ans,data(x,y,z,d));
		}
		printf("%d\n",ans.volume());
	}
	
}
