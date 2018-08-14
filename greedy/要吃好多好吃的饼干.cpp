#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
float map[60][60];
int main(){
	int n,c;
	int w[60];
	float v[60];
	while(cin>>n){
		cin>>c;
		memset(map,0,sizeof(map));
		for(int i=1;i<=c;i++){
			scanf("%d%f",&w[i],&v[i]);
		}
		for(int i=1;i<=c;i++){
			for(int j=w[i];j<=n;j++){
				for(int k=0;k*w[i]<=j;k++)
					map[i][j]=max(map[i-1][j-k*w[i]]+k*v[i],map[i-1][j]);
			}
		}	

			cout<<map[c][n]/0.4<<endl;
		}	
	}

