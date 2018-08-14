#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct Node{
	int x,y;
	char fuhao;
}a[27];

string  b[15000];
int n;
int index1=0;
void xunzhao(){
	int i,j,k,l;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			if(j==i)continue;
			else{
					if(a[i].y==a[j].y&&a[j].x>a[i].x){
					
						for(k=0;k<n;k++){
							if(k==j||k==i)continue;
							else{
								if(a[k].x==a[j].x&&a[k].y<a[j].y)
								{
									for(l=0;l<n;l++){
										if(l==k||l==i||l==j) continue;
										else{
											if(a[l].x==a[i].x&&a[l].y==a[k].y)
											{
												b[index1].push_back(a[i].fuhao);
												b[index1].push_back(a[j].fuhao);
												b[index1].push_back(a[k].fuhao);
												b[index1].push_back(a[l].fuhao);
										
												index1++;
											}
											else 
											 continue;
										}
									}
								}
								else continue;
							}
						}
					}
					else continue;
				}
		}
}
}


int main(){
	int temp=1;
	freopen("in.txt","r",stdin);
	while(cin>>n){
		if(n==0)break;
		int i;
		for(i=0;i<n;i++){
			getchar();
			cin>>a[i].fuhao>>a[i].x>>a[i].y;
		}
		index1=0;
		xunzhao();
		printf("Point set %d:",temp++);
		if(index1==0)
		{
			cout<<" No rectangles"<<"\n";
			continue;
		}
		sort(b,b+index1-1);
		printf("\n");
		for(i=0;i<index1;i++){
			cout<<" "<<b[i];
			if((i+1)%10==0)
				cout<<endl;
		}
		cout<<endl;	
		for(i=0;i<index1;i++){
			b[i].clear();
		}
		
	}
}
