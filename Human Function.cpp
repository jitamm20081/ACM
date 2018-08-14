#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int Get[210][210];
int Matrix[5][5]={
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2}, 
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0}
} ;

int Change(char c){
	switch(c){
		case 'A':return 0;break;
		case 'C':return 1;break;
		case 'G':return 2;break;
		case 'T':return 3;break;
		case '-':return 4;break;
		default:;break;
	}
}

int main(){
	int i,j,k;
	int t,n,m;
	cin>>t;
	char A[150],B[150];
	for(k=0;k<t;k++){
		cin>>n>>A>>m>>B;
		for(i=0;i<=n;i++)
			for(j=0;j<=m;j++){
				Get[i][j]=-4545;
			}
		Get[0][0]=0;
		for(j=1;j<=n;j++)
			Get[0][j]=Get[0][j-1]+Matrix[Change('-')][Change(B[j-1])];//注意，A，B中i-1即为第i个字符的下标 
		for(i=1;i<=m;i++)
			Get[i][0]=Get[i-1][0]+Matrix[Change(A[i-1])][Change('-')];
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				if(Get[i][j-1]+Matrix[Change('-')][Change(B[j-1])]>Get[i][j])
					Get[i][j]=Get[i][j-1]+Matrix[Change('-')][Change(B[j-1])];
				if(Get[i-1][j]+Matrix[Change(A[i-1])][Change('-')]>Get[i][j])
					Get[i][j]=Get[i-1][j]+Matrix[Change(A[i-1])][Change('-')];
				if(Get[i-1][j-1]+Matrix[Change(A[i-1])][Change(B[j-1])]>Get[i][j])
					Get[i][j]= Get[i-1][j-1]+Matrix[Change(A[i-1])][Change(B[j-1])];
			}		
			cout<<Get[n][m]<<endl;
	}
	
}
