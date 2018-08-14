#include<iostream>
#include<cstdio>
#include<cstdlib>
struct deng{
	char c;
	int num;
}str[11];

using namespace std;
int n;
int main(){
	cin>>n;
	int i=0;
	while(scanf("%c",&str[i].c)){
		if(str[i].c=='Q')break;
		scanf("%d",&str[i++].num);
	}
	
}