#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define N 105
using namespace std;
int temp[N],in[N],Sort[N],pos;
int m,n;
char X,O,Y;
queue<int>q;
vector<int>G[N];


void init(){//初始化 
	memset(in,0,sizeof(in));
	for(int i=0;i<=n;i++)
		G[i].clear();
}


inline bool find(int u,int v){//相同的线段不再引入 
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]==v)	return true;
	} 
	return false;
}

int paixv(){//寻找入度为零的点不断入队，若这种点超过一个，则无法确定唯一顺序 
	while(!q.empty())q.pop();
	int i,j;
	for(i=0;i<n;i++){
		if(in[i]==0)
			q.push(i);
	}
	bool unsure=false;
	pos=0;
	int flag;
	while(!q.empty()){
		if(q.size()>1)unsure=true;
		int t=q.front();
		q.pop();
		Sort[pos++]=t;
		for(i=0;i<G[t].size();i++){
			if(--in[G[t][i]]==0)
				q.push(G[t][i]);
		}
	}
	if(pos<n) return 1;
	if(unsure) return 2;
	return 3;
	
}

int main(){
	int x,y,i,flag;
	bool ok;
 	freopen("in.txt","r",stdin);
	while(~scanf("%d%d%*c",&n,&m)){//%*c是用来跳过回车键的 
		int stop; 
		//cout<<n<<m<<endl;
		if(n==0||m==0)break;
		init();
		flag=2;
		ok=false;
		for(i=1;i<=m;i++){
			scanf("%c%c%c%*c",&X,&O,&Y);
			
			if(ok) continue;	
			x=X-'A',y=Y-'A';
		//	cout<<x<<endl<<y<<endl;
			if(O=='<'&&!find(x,y)){
				G[x].push_back(y);
				in[y]++;
			}  
			if(O=='>'&&!find(y,x)){
				G[y].push_back(x);
				in[x]++;
			}
			memcpy(temp,in,sizeof(in));//复制一个in数组的副本用来还原，经过排序后会使in数组产生变化 
			flag=paixv();
			//cout<<flag<<endl;
			memcpy(in,temp,sizeof(temp));
			if(flag!=2){
				ok=true;
				stop=i;
			}
		}
		if(flag==3){
			cout<<"Sorted sequence determined after "<<stop<<" relations: ";
            for(int i=0; i<=pos-1; ++i)
                printf("%c",Sort[i]+'A');
			cout<<"."<<endl;
		}
		else if(flag==2)
			cout<<"Sorted sequence cannot be determined."<<endl;
		else
			cout<<"Inconsistency found after "<<stop<<" relations."<<endl;
		}
	}
	

