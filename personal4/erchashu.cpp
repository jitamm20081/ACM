#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
char a[100][3];
void fff(int c){
	if(c=='*')return ;
	printf("%c",c);
	for(int i=0;i<n;i++){
		if(c==a[i][0])
		{
			fff(a[i][1]);
			fff(a[i][2]);
		}
	}
}


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	fff(a[0][0]);
}