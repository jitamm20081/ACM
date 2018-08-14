#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
struct node1{
	int way;
	int fath;
}Node[370000];

struct node2{
	int n;//n为9在aa中的位置{
	int son;
	int aa[10];
};

int fac[10];

void count_fac(){
	fac[0]=1;
	for(int i=1;i<9;i++){
		fac[i]=fac[i-1]*i;
	}
}


int conto(int a[]){
	int k;
	int ans=0;
	int i,j;
	for(i=0;i<9;i++){
		k=0;
		for (j = i+1; j<9; j++)
		{
			if (a[i]>a[j])
				{
					k++;
				}	
			
		}
		ans+=(fac[8-i]*k);
	}
	return ans;
}

void bfs(int a[]){
	queue<node2>que;
	int e,fx,fy,temp;
	node2 p,q;
	for(e=0;e<9;e++)p.aa[e]=a[e];
	p.son=0;
	p.n=8;
	Node[p.son].fath=0;
	que.push(p);
	while(!que.empty()){
		p=que.front();

		que.pop();
		for(int i=0;i<4;i++){
			q=p;
			fx=p.n/3+dx[i];
			fy=p.n%3+dy[i];
			if(fx>=0&&fx<3&&fy>=0&&fy<3){
				q.n=3*fx+fy;
				temp=q.aa[q.n];
				q.aa[q.n]=q.aa[p.n];
				q.aa[p.n]=temp;
				q.son=conto(q.aa);
				if (Node[q.son].fath==-1)//右左下上
				{
					Node[q.son].fath=p.son;
					if(i==0)Node[q.son].way='l';
					if(i==1)Node[q.son].way='r';
					if(i==2)Node[q.son].way='d';
					if(i==3)Node[q.son].way='u';
					que.push(q);
				}
			}
		}		
	}


}


int main(){
	char s[100];
	int ss[10];
	int a[10],i,j;
	for(i=0;i<9;i++){
		a[i]=i+1;
	}
    for(i=0;i<370000;i++){
    	Node[i].fath=-1;
    }
	count_fac();
	bfs(a);


	while(gets(s)>0){
		for(i=0,j=0;s[i]!='\0';i++){
			if(s[i]=='x')
				ss[j++]=9;
			else if (s[i]>='0'&&s[i]<='8')
			{
				ss[j++]=s[i]-'0';}
		}
		int abs=conto(ss);
		if(Node[abs].fath==-1){
			cout<<"unsolvable"<<endl;
			continue;
		}
		while(abs!=0){
			printf("%c",Node[abs].way);
			abs=Node[abs].fath;
		}
		cout<<endl;
	}
}