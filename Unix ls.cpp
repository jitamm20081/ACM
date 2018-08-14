#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 105
using namespace std;

int main(){
	int n;
	freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		string file[N];

		int i,j;
		for(i=0;i<n;i++){
			cin>>file[i];
		}
		sort(file,file+n);
		int cmax=0;
		printf("------------------------------------------------------------\n");
		for(i=0;i<n;i++)
			cmax =max(cmax,(int)file[i].size());
		int col = 62 / (cmax + 2);
		int row = ceil(1.0 * n / col);
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				int t;
				t=j*row+i;
				if(t>=n)
					continue;
				int k;
				k=cmax-file[t].size();
				cout<<file[t];
				for(k;k>0;k--){
					cout<<" ";
				}
				if(j!=col-1)
					cout<<"  ";
				
			}
			if(i<=row-1)
				cout<<endl;
		}
		
	}
	
}
