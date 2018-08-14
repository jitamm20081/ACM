#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
bool visit[70][70][70],tab[70][70][70];
int n,m,k,l;
int face;
class W3{
	public:
		int x,y,z;
	W3& set(int xx,int yy,int zz){
		x=xx;
		y=yy;
		z=zz;
		return *this;
	}
};

void bfs(){
	face=0;
	queue<W3>Q;
	W3 temp;
	Q.push(temp.set(0,0,0));
	while(!Q.empty()){
		W3 Top;
		Top=Q.front();
		Q.pop();
		if(visit[Top.x][Top.y][Top.z])continue;
		visit[Top.x][Top.y][Top.z]=1;
		if(Top.x-1>=0){
			if(tab[Top.x-1][Top.y][Top.z]==0){
				if(!visit[Top.x-1][Top.y][Top.z])
					Q.push(temp.set(Top.x-1,Top.y,Top.z));				
			}
			else 
				face++;	
		}
		if(Top.x<=n){
			if(tab[Top.x+1][Top.y][Top.z]==0){
				if(!visit[Top.x+1][Top.y][Top.z])
					Q.push(temp.set(Top.x+1,Top.y,Top.z));
			}
			else 
				face++;			
		}
		if(Top.y-1>=0){
			if(tab[Top.x][Top.y-1][Top.z]==0){
			 	if(!visit[Top.x][Top.y-1][Top.z])
					Q.push(temp.set(Top.x,Top.y-1,Top.z));
			}
			else 
				face++;		
	
						
		}
		if(Top.y<=m){
			if(tab[Top.x][Top.y+1][Top.z]==0){
			
				if(!visit[Top.x][Top.y+1][Top.z])
					Q.push(temp.set(Top.x,Top.y+1,Top.z));
			}
			else 
				face++;
		//	cout<<face<<endl;		
		}
		if(Top.z>=0){
			if(tab[Top.x][Top.y][Top.z-1]==0)
					{
					if(!visit[Top.x][Top.y][Top.z-1])
					Q.push(temp.set(Top.x,Top.y,Top.z-1));}
			else 
				face++;
			//cout<<face<<endl;
		}
		if(Top.z<=k){
			if(tab[Top.x][Top.y][Top.z+1]==0)
				{
					if(!visit[Top.x][Top.y][Top.z+1])
						Q.push(temp.set(Top.x,Top.y,Top.z+1));}
			else 
				face++;	
		//	cout<<face<<endl;		
		}		
	} 
}

int main(){
	freopen("in.txt","r",stdin);
	while(cin>>n>>m>>k>>l){
		if(!n&&!m&&!l&&!k)break;
		memset(visit,0,sizeof(visit));
		memset(tab,0,sizeof(tab));
		int temp1;
		for(int i=0;i<l;i++){
			cin>>temp1;
			tab[temp1%(n*m)%n+1][temp1%(n*m)/n+1][temp1/(n*m)+1]=1;
		}
		bfs();
		printf("The number of faces needing shielding is %d.\n",face);
	}
} 
