#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	char s[101][101];
	char a[101];
	int n;
	int z,x,c,v;
	cin>>n;
	int i,j,k,q,w,u,x1,x2,x3,x4;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cin>>s[i][j];
	}
	int flag;
	while(scanf("%s",a)){
		flag=0;
		if(a[0]=='0')break;
		int m=strlen(a);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
			{
				k=0,q=0,w=0,u=0,x1=0,x2=0,x3=0,x4=0;
				if(s[i][j]==a[0]){
					for(k=1;k<=m-1;k++)
					{
						if(s[i][j+k]==a[k])
							continue;
						else break;
					}
					for(x1=1;x1<=m-1;x1++)
					{
						if(s[i][j-x1]==a[x1])
							continue;
						else break;
					}
					for(u=1;u<=m-1;u++)
					{
						if(s[i+u][j-u]==a[u])
							continue;
						else break;
					}
					for(x3=1;x3<=m-1;x3++)
					{
						if(s[i-x3][j-x3]==a[x3])
							continue;
						else break;
					}
					for(x4=1;x4<=m-1;x4++)
					{
						if(s[i-x4][j+x4]==a[x4])
							continue;
						else break;
					}
					for(q=1;q<=m-1;q++)
					{
						if(s[i+q][j]==a[q])
							continue;
						else break;
					}
					for(x2=1;x2<=m-1;x2++)
					{
						if(s[i-x2][j]==a[x2])
							continue;
						else break;
					}
					for(w=1;w<=m-1;w++){
						if(s[i+w][j+w]==a[w])
							continue;
						else break;
					}
					if(k>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+1,j+m);
						flag=1;
						break;
					}
					if(q>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+m,j+1);
						flag=1;
						break;
					}
					if(w>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+m,j+m);
						flag=1;
						break;
					}
					if(u>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+m,j+2-m);
						flag=1;
						break;
					}
					if(x1>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+1,j+2-m);
						flag=1;
						break;
					}
					if(x2>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+2-m,j+1);
						flag=1;
						break;
					}
					if(x3>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+2-m,j+2-m);
						flag=1;
						break;
					}
					if(x4>=m){
						printf("%d,%d %d,%d\n",i+1,j+1,i+2-m,j+m);
						flag=1;
						break;
					}
				}
			}
		}
		if(flag==0)printf("Not found\n"); 
	}
	
}
