#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
char map1[20][20],map2[20][20];
void refresh(){
	int i,j;
	int flag=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map1[i][j]=='*'&&map2[i][j]=='x')
			{
				flag=1;	
			}
		}
	}	
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map2[i][j]=='x'){

				if(flag==1&&map1[i][j]=='*'){
					map2[i][j]='*';
				}
				else{
					int q=0;
					if(map1[i-1][j]=='*')
						q++;
					if(map1[i+1][j]=='*')
						q++;
					if(map1[i-1][j-1]=='*')
						q++;
					if(map1[i][j+1]=='*')
						q++;
					if(map1[i+1][j+1]=='*')
						q++;
					if(map1[i-1][j+1]=='*')
						q++;
					if(map1[i][j-1]=='*')
						q++;
					if(map1[i+1][j-1]=='*')
						q++;
					map2[i][j]=char(q+'0');						
					}
					}
				else {
					if(flag==1&&map1[i][j]=='*')
						map2[i][j]='*';
				}
			
		}
	}
}


int main(){
	char s[20];
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<n;j++){
			map1[i][j]=s[j];
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<n;j++){
			map2[i][j]=s[j];
		}
	}
	refresh();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map2[i][j];
		}
		cout<<endl;
	}	
		
}
